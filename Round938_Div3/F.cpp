#include<bits/stdc++.h>
#define mod 1000000007
#define mod2 998244353
#define ceil(a,b) ((a+b-1)/b)
#define floor(a,b)((a-b+1)/b)
#define fast_io() ios::sync_with_stdio(0);cin.tie(0);
#define ll long long
#define int long long
#define vi vector<int>
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define input(x) for(auto &a:x) cin >> a;
#define output(x) for(auto a:x) cout << a <<" ";
#define rep(i,a,n) for(int i=(a);i<n;i++)
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define ff first
#define ss second
#define si set<int>
#define pii pair<int,int>
#define mii map<int,int>
#define msi map<string,int>
#define yes "YES"
#define no "NO"
#define endl '\n'
using namespace std; 
/* 
for fast input output use printf and scanf;
*/
int solve(vector<int>arr,int n,int k){

        int i = 0 , j = n-1;
        int d = 0;
        while(k)
        {
        	if(d == 0)
        	{
        		arr[i]--;
        		k--;
        		if(arr[i] == 0) i++;
        	}
        	if(k <= 0) break;
        	if(d == 1)
        	{
        		arr[j]--;
        		k--;
        		if(arr[j] == 0) j--;
        	}
        	d = !d;
        }
        // cout << "here " << i << " " << j << endl;
        // output(arr);
        // cout << endl;
       return n - max(j-i+1,1LL*0);
}
int mine(vector<int>arr,int n,int k)
{

        int i = 0 , j = n-1;
        int karaken = true;
        while(i<=j)
        {
        	// cout << i << " " << j << endl;
        	if(i == j)
        	{
        		if(k >= arr[i]) i++;
        		// else break;
        		break;
        	}
        	if(karaken == true && arr[i]==1 && k>=1)
        	{
        		karaken = false;
        		i++;
        		k--;
        		continue;
        	} 
        	if(karaken == false && arr[j] == 1 && k>=1)
        	{
        		k--;
        		karaken = true;
        		j--;
        		continue;
        	}
        	int e1 = arr[i];
        	int e2 = arr[j];
        	int mini = min(arr[i],arr[j]);
        	// cout << e1 << e2 << endl;
        	if(e1 == e2 && e2 == mini && e1 == mini)
        	{
        		// cout << "here" << endl;
        		k -= ((2*e1) - 1);
        		if(k < 0) break;
        		if(karaken == true)
        		{
        			arr[j] = 1;
        		}
        		if(karaken == false)
        		{
        			arr[i] = 1;
        		}
        		if(karaken) i++;
        		else j--;
        		karaken = !karaken;
        	}
        	else
        	{
        		if(e1 == mini)
        		{
        			if(karaken == false)
        			{
        				k -= (e1 + e1);
        				if(k < 0) break;
        				arr[j] = arr[j] - e1;
        			}
        			else
        			{
        				k -= ((2*e1) - 1);
        				if(k < 0) break;
        				arr[j] -= e1; 
        			}
        			karaken = false;
        			i++;
        		}
        		else if(e2 == mini)
        		{
        			if(karaken == true)
        			{
        				k -= (e2 + e2);
        				if(k < 0) break;
        				arr[i] = arr[i] - e2;
        			}
        			else
        			{
        				k -= ((2*e2) - 1);
        				if(k < 0) break;
        				arr[i] -= e2; 
        			}
        			karaken = true;
        			j--;
        		}
        	}
        }
        return n - max(j-i+1,1LL*0);

}
void test(){
	srand(time(NULL));
	int cnt = 1;
	int MAX = 1e3;
	while(cnt <= MAX){
		int n = rand() % 10 + 1;
		int k = rand() % 10 + 1;
		vector<int> arr(n);
		for(int i=0;i<n;i++){
			arr[i] = rand() % 1000 + 1;
		}
		int correctAns = solve(arr,n,k);
		int myAns = mine(arr,n,k);
		if(correctAns != myAns){
			cout << correctAns << " " << myAns << endl;
			cout << n << " " << k << endl;
			output(arr);
			break;
		}
		cnt++;
	}
}
signed main(){
	test();
    return 0;
}