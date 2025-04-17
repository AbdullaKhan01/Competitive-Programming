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
const int INF = 1e18;
void solve()
{
	int n,m,k;
	cin >> n >> m >> k;
	vector<int> a(n);
	vector<int> pref(n+1);
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
		pref[i+1] = pref[i] + a[i];
		// cout << pref[i+1] << " ";
	}
	// cout << endl;
	// [l1,r1],[l2,r2],[l3,r3],.........[lk,rk]
	vector<vector<int>>dp(n+1,vector<int>(k+1,-INF));
	// do some dp calculations
	// what will dp[i][k] represent 
	// it represents the maximal possible answer with
	// kth pair ending at i and the rk at the ith index 

	for(int i=0;i<=n;i++) dp[i][0] = 0;

	vector<int> optimal(k+1,-INF);
	optimal[0] = 0;

	for(int i=m;i<=n;i++)
	{
		// int j = m-1;//array index
		for(int kk=1;kk<=k;kk++)
		{
			int pref_sum = pref[i] - pref[i-m];
			// some dp[optimal]
			int best_ans = optimal[kk-1];

			dp[i][kk] = max(dp[i][kk],pref_sum + best_ans);

			optimal[kk] = max(optimal[kk],dp[i-m][kk]);
		}
	}

	// done dp calculations
	int ans = -INF;
	for(int i=m*k;i<=n;i++)
	{
		ans = max(ans,dp[i][k]);
	}
	cout << ans << endl;
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