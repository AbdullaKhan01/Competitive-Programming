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
int n;
int a[5001];
int b[5001];
int dp[5001][5001];
int rec(int l,int r)
{
	// return the product a[i] * b[i] when l to r subarray of
	// a is reversed
	// pruning 

	// base case
	if(l > r)
	{
		return 0;
	}
	if(l == r)
	{
		return a[l] * b[l];
	}
	// cache check
	if(dp[l][r] != -1) return dp[l][r];
	// compute
	int ans = (a[r] * b[l] + a[l] * b[r]) + rec(l+1,r-1);
	// save and return
	return dp[l][r] = ans;
}
void solve()
{
	cin >> n;
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
	}
	for(int i=0;i<n;i++)
	{
		cin >> b[i];
	}
	vector<int> pref(n+1);
	for(int i=0;i<n;i++)
	{
		pref[i+1] += pref[i] + (a[i] * b[i]);
	}
	memset(dp,-1,sizeof(dp));
	int ans = pref[n];
	int maxi = -1;
	for(int l=0;l<n;l++)
	{
		for(int r=l;r<n;r++)
		{
			int prev_sum = pref[r+1] - pref[l];
			int new_sum = rec(l,r);
			maxi = max(maxi,ans - prev_sum + new_sum);
		}
	}
	cout << maxi << endl;
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