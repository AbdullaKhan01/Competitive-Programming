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
int n,m;
vector<vector<int>>a;
vector<int> vis;
map<int,int> mp;
void dfs(int node,int curr)
{
	vis[node] = 1;
	mp[curr]++;
	for(auto v:a[node])
	{
		if(!vis[v])
		{
			dfs(v,curr);
		}
	}
}
void solve()
{
	cin >> n >> m;
	a.resize(n+1);
	vis.resize(n+1);
	mp.clear();
	while(m--)
	{
		int u,v;
		cin >> u >> v;
		a[u].pb(v);
		a[v].pb(u);
	}
	int cnt = 0;
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			cnt++;
			dfs(i,cnt);
		}
	}
	int ans = 0;
	int sum = 0;
	for(auto it:mp)
	{
		// cout << it.first << " " << it.second << endl;
		ans += it.second * sum;
		sum += it.second;
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