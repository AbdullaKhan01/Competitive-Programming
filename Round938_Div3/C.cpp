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
signed main(){
	fast_io();
    ll tt;
    cin >> tt;
    while(tt--)
    {
        int n,k;
        cin >> n >> k;
        vi arr(n);
        input(arr);
        int i = 0 , j = n-1;
        int karaken = true;
        while(i<=j)
        {
        	
        	if(i == j)
        	{
        		if(k >= arr[i]) i++;
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
        				arr[j] -= (e1-1); 
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
        				arr[i] -= (e2-1); 
        			}
        			karaken = true;
        			j--;
        		}
        	}
        }
        // cout << i << " " << j << endl;
        cout << n - max(j-i+1,1LL*0) << endl;

    }
    return 0;
}