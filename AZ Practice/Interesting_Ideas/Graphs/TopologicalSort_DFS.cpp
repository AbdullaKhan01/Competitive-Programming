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
// Q). Given a Graph find an ordering of the nodes of
// the graph such that if u < v in the ordering then
// there should be no edge from v to u in the graph
vector<vector<int>>g;
vector<int> vis;
vector<int> topo;
void dfs(int node)
{
	vis[node] = 1;
	for(auto v:g[node])
	{
		if(!vis[v]) dfs(v);
	}
	topo.push_back(node);
}
// find longest path in a DAG can be solved by DP
// int dp[100100];
// int rec(int node) // longest path starting at node
// {
// 	if(dp[node] != -1) return dp[node];
// 	int ans = 1;
// 	for(auto v:g[node])
// 	{
// 		ans = max(ans,1+rec(v));
// 	}
// 	return dp[node] = ans;
// }

void solve()
{
	int n,m;
	cin >> n >> m;
	g.resize(n+1);
	vis.assign(n+1,0);
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin >> a >> b;
		g[a].push_back(b);
	}
	// memset(dp,-1,sizeof(dp));
	// int ans = 0;
	// for(int i=1;i<=n;i++)
	// {
	// 	ans = max(ans,rec(i));
	// 	cout << dp[i] << " ";
	// }
	// cout << ans << endl;
	for(int i=1;i<=n;i++)
	{
		if(!vis[i]) dfs(i);
	}
	reverse(all(topo));
	output(topo);
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