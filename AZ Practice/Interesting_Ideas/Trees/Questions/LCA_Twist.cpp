#include<bits/stdc++.h>
using namespace std; 
int n;
vector<vector<int>>g;
vector<int> depth;
vector<vector<int>> par;
void dfs(int node,int parent,int dep)
{

	par[node][0] = parent;
	depth[node] = dep;
	for(int i=1;i<20;i++)
	{
		par[node][i] = par[par[node][i-1]][i-1];
	}
	for(auto v:g[node])
	{
		if(v != parent)
		{
			dfs(v,node,dep+1);
		}
	}
}

int lca(int u,int v)
{
	if(depth[u] < depth[v])
	{
		swap(u,v);
	}
	int h_diff = depth[u] - depth[v];
	for(int i=20;i>=0;i--)
	{
		if(h_diff & (1<<i))
		{
			u = par[u][i];
		}
	}
	if(u == v) return u; // if u v in same subtree
	for(int i=20;i>=0;i--)
	{
		if(par[u][i] != par[v][i])
		{
			u = par[u][i];
			v = par[v][i];
		}
	}
	return par[u][0];
}
void solve()
{
	cin >> n;
	g.assign(n+1,vector<int>());
	depth.resize(n+1);
	par.assign(n+1,vector<int>(21,-1));
	for(int i=0;i<n-1;i++)
	{
		int u,v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int q;
	cin >> q;
	dfs(1,1,0);
	while(q--)
	{
		// If the root is changed then
		// there can be 3 cases only  
		// let x = LCA of (u,v)
		// Case 1 : z is above x then lca of u,v will be x only
		// Case 2 : z is below x but towards the branch of x 
		// containing u then lca of u,v will be lca of u,z
		// Case 3 : z is below x but towards the branch of x 
		// containing v then lca of u,v will be lca of v,z
		int x,y,z;
		cin >> x >> y >> z;

		int i = lca(x,y);
		int a = lca(x,z);
		int b = lca(y,z);

		if(a == i) cout << b;
		else if(b == i) cout << a;
		else cout << i;
		cout << endl;
	}
}
signed main(){

	int tt;
	cin >> tt;
	while(tt--)
	{
	    solve();
	}
    return 0;
}