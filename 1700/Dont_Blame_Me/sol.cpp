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
// it was a dp bitmask problem
ll modAdd(ll a,ll b){
    ll p = (a%mod + b%mod)%mod;
    return p;
}
ll modSub(ll a,ll b){
    ll p = (a%mod - b%mod)%mod;
    if(p<0) p+=mod;
    return p;
}
ll modMul(ll a,ll b){
    ll p = (a%mod * b%mod)%mod;
    return p;
}
void solve()
{
	// int n,k;
	int n;
	cin >> n;
	// cin >> n >> k;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	sort(all(a));
	vector<vector<int>> dp(n,vector<int>(64,0));
	dp[0][a[0]] = 1;
	for(int i=1;i<n;i++){
		
		for(int j=0;j<64;j++){
			// dp[i][j] -> no of ways to make bitwise AND
			// exactly j from the first i elements


			// not take the ith element
			dp[i][j] = modAdd(dp[i][j],dp[i-1][j]);

			// take the ith
			dp[i][a[i] & j] = modAdd(dp[i][a[i] & j],dp[i-1][j]); 			
		}
		// take only the ith element
		dp[i][a[i]] = modAdd(dp[i][a[i]],1);
	}
	// int ans = 0;
	// for(int i=0;i<64;i++){
	// 	if(__builtin_popcount(i) == k){
	// 		ans = modAdd(ans,dp[n-1][i]);
	// 	}
	// }
	// for(int i=0;i<n;i++){
	// 	// cout << i << " " << dp[i][0] << endl;
	// 	ans = modAdd(ans,dp[n-1][0]);
	// }
	cout << dp[n-1][0] << endl;
}
signed main(){
	fast_io();
    int tt = 1;
    // cin >> tt;
    while(tt--)
    {
    	solve();
    }
    return 0;
}