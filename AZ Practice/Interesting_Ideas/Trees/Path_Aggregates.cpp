#include<bits/stdc++.h>
using namespace std; 
/* 
for fast input output use printf and scanf;
*/
/*
Q). Given a Tree maintain the property for the paths
 	from the node u to v and answer them while querying

 	Basically find the gcd of path from u to v
 	// or find the sum of path from u to v
 	// or min , max , xor etc.

*/
// next(node,i) = next(next(node,i-1),i-1)
int n;
vector<vector<int>>g;
vector<int> val;
vector<int> depth;
vector<vector<int>> par;
vector<vector<int>> dp;
void dfs(int node,int parent,int dep)
{
	
	depth[node] = dep;
	par[node][0] = parent;
	dp[node][0] = val[node];
	// we came through dfs to this node so everything
	// above has been already processed so this for loop
	// can be written
	for(int i=1;i<20;i++)
	{
		par[node][i] = par[par[node][i-1]][i-1];
		dp[node][i] = __gcd(dp[node][i-1],dp[par[node][i-1]][i-1]);
	}
	for(auto v:g[node])
	{
		if(v != parent)
		{
			dfs(v,node,dep+1);
		}
	}
}
int gcd(int a,int b){
	return __gcd(a,b);
}
int findGCD(int u,int v)
{
	// Two steps of LCA

	// Step 1 : Bring u and v to same depth
	// Step 2 : Try jumping to parent till they are not same

	if(depth[u] < depth[v])
	{
		swap(u,v);
	}
	int h_diff = depth[u] - depth[v];
	int ans = 0;
	// Bringing u to same depth as v
	for(int i=20;i>=0;i--)
	{
		if(h_diff & (1<<i))
		{
			ans = __gcd(ans,dp[u][i]);
			u = par[u][i];
		}
	}
	if(u == v) return __gcd(ans,val[u]); // if u v in same subtree
	for(int i=20;i>=0;i--)
	{
		if(par[u][i] != par[v][i])
		{
			ans = __gcd(ans,dp[u][i]);
			u = par[u][i];
			ans = __gcd(ans,dp[v][i]);
			v = par[v][i];
		}
	}
	return gcd(ans,gcd(val[u],gcd(val[v],val[par[u][0]])));
}
void solve()
{
	cin >> n;
	g.assign(n+1,vector<int>());
	val.assign(n+1,0);
	depth.assign(n+1,0);
	par.assign(n+1,vector<int>(21,-1));
	dp.assign(n+1,vector<int>(21,-1));

	for(int i=1;i<=n;i++){
		cin >> val[i];
	}
	for(int i=0;i<n-1;i++)
	{
		int u,v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,1,0);
	int q;
	cin >> q;
	while(q--){
		int u,v;
		cin >> u >> v;
		cout << findGCD(u,v) << endl;
	}
}
signed main(){

	int tt;
	cin >> tt;
	while(tt--){
		solve();	
	}
    return 0;
}