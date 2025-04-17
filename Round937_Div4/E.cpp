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
int countSubarray(vector<int> &arr, int n, int k) 
{ 
    // To store count of subarrays with all 
    // elements less than or equal to k. 
    int s = 0; 
  
    // Traversing the array. 
    int i = 0; 
    while (i < n) { 
        // If element is greater than k, ignore. 
        if (arr[i] > k) { 
            i++; 
            continue; 
        } 
  
        // Counting the subarray length whose 
        // each element is less than equal to k. 
        int count = 0; 
        while (i < n && arr[i] <= k) { 
            i++; 
            count++; 
        } 
  
        // Summing number of subarray whose 
        // maximum element is less than equal to k. 
        s += ((count * (count + 1)) / 2); 
    } 
  
    return (n * (n + 1) / 2 - s); 
} 
bool works(string s,int mid){
	
	int n = s.size();
	string a;
	string b;
	for(int i=0;i<mid;i++){
		a.push_back(s[i]);
	}
	for(int j=n-mid;j<n;j++){
		b.push_back(s[j]);
	}
	// string b = "bb";
	// cout << a << " " << b << endl;
	// string b = "bb";
	if(n % mid != 0) return false;
	string temp1,temp2;
	for(int i=0;i<(n/mid);i++){
		temp1 = temp1 + a;
		temp2 = temp2 + b;
	}
	int cnt1 = 0,cnt2=0;
	for(int i=0;i<n;i++){
		if(s[i] != temp1[i]) cnt1++;
		if(s[i] != temp2[i]) cnt2++;
	}
	
	return (cnt1 <= 1 || cnt2 <= 1);

}
signed main(){
	// fast_io();
	vector<int> arr = {1,3,2,3,3};
	int solve = countSubarray(arr,arr.size(),1);
	cout <<  solve << endl;
    // ll tt;
    // cin >> tt;
    // while(tt--)
    // {

    //     int n;
    //     cin >> n;
    //     string s;
    //     cin >> s;
    //     // cout << "here" << endl;
    //     // cout << s << endl;
    //     int st = 1 , e = n;
    //     int ans = n;
        
    //     while(st <= e){
    //     	int mid = (st+e)/2;
    //     	if(works(s,mid)){
    //     		ans = min(ans,mid);
    //     		e = mid - 1;
    //     	}
    //     	else{
    //     		st = mid + 1;
    //     	}
    //     }
    //     cout << ans << endl;
    // }
    return 0;
}