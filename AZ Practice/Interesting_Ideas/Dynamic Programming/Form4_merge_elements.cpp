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
vector<int> a;
int dp[501][501];
int rec(int l,int r)
{
	if(l == r)
	{
		return 0;
	}
	if(dp[l][r] != -1)
	{
		return dp[l][r];
	}
	int ans = 1e9;
	int total = 0;
	int sum = 0;
	for(int mid=l;mid<=r;mid++)
	{
		total += a[mid];
	}
	for(int mid=l;mid<r;mid++)
	{
		sum += a[mid];
		sum %= 100;
		int right = (total - sum)%100;
		ans = min(ans,rec(l,mid) + rec(mid+1,r) + (sum * right));
	}
	return dp[l][r] = ans;
}
void solve()
{
	cin >> n;
	a.resize(n);
	vector<int> pref(n);
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
		pref[i] = a[i];
		if(i > 0) pref[i] += pref[i-1];
	}
	// memset(dp,-1,sizeof(dp));
	// cout << rec(0,n-1) << endl;
	if(n == 1)
	{
		cout << a[0] << endl;
		return ;
	}
	const int inf = 1e9;
	// rec1();
	vector<vector<int>>dp(n,vector<int>(n,inf));
	for(int r=0;r<n;r++)
	{
		for(int l=r;l>=0;l--)
		{
			if(l == r)
			{
				dp[l][r] = 0;
				continue;
			}
			for(int b=r;b>=l+1;b--)
			{
				//1. merge from l to b-1 
				int s1 = pref[b-1];
				if(l > 0) s1 -= pref[l-1];
				//2. merge from b to r
				int s2 = pref[r];
				if(b > 0) s2 -= pref[b-1];
				s1 %= 100;
				s2 %= 100;
				//merge 1 and 2
				// cout << "for " << l << " " << r << " with " << b << " " << s1 << " " << s2 << endl;
				dp[l][r] = min(dp[l][r],dp[l][b-1] + dp[b][r] + (s1 * s2));
			}
		}
	}
	cout << dp[0][n-1] << endl;
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