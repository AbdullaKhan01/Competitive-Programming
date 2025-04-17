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
const int inf = 1e18;
vector<int> a,b;
vector<int> pref;
int n,m;
vector<vector<int>>dp;

int findIdx(int idx,int val)
{
	int ans = upper_bound(all(pref),val + pref[idx]) - pref.begin();
	return ans;
}

int rec(int idx,int k)
{

	// pruning 

	// base case
	if(idx >= n) return 0;
	if(k >= m)
	{
		if(idx >= n) return 0;
		else return inf;
	}
	if(a[idx] > b[k]) return inf;
	// cache check
	if(dp[idx][k] != -1) return dp[idx][k];
	// compute
		int ans1 = inf;
		int ans2 = inf;
		
		ans1 = rec(idx,k+1);

		// direct optimal

		// find r such that pref[r] - pref[l-1] <= b[k]
		// or pref[r] <= b[k] + pref[l-1]

		int find = findIdx(idx,b[k]);
		if(pref[find-1] - pref[idx] <= b[k])
		{
			ans2 = (m - k - 1) + rec(find-1,k);
		}
		
	// save and return
	return dp[idx][k] = min(ans1,ans2);
}
void solve()
{
	cin >> n >> m;
	a.resize(n);
	b.resize(m);
	pref.resize(n+1);
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
		pref[i+1] = pref[i] + a[i];
	}
	for(int i=0;i<m;i++)
	{
		cin >> b[i];
	}
	dp.resize(n+1);
	for(int i=0;i<=n;i++)
	{
		dp[i].assign(m+1,-1);
	}
	int ans = rec(0,0);
	if(ans == inf)
	{
		cout << -1 << endl;
	}
	else
	{
		cout << ans << endl;
	}
}
signed main(){
	fast_io();
    int tt = 1;
    cin >> tt;
    while(tt--)
    {
    	solve();
    }
    return 0;
}