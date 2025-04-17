#include<bits/stdc++.h>
using namespace std;


vector<vector<int>>adj;
vector<int> color;
// vector<int> parent;

bool f;


void dfs(int v)
{
	// parent[node] = par;
	if(f) return;
	color[v] = 2;
	
	for(auto x:adj[v])
	{
		//uncomment this line if graph is undirected
		// if(v == parent[node]) continue;
		if(color[x] == 1)
		{
			// node - v is a forward edge
			dfs(x);
		}
		else if(color[x] == 2)
		{
			// node - v is a back edge
			// we found a cycle !!
			f = true;
			return ;
		}
		else if(color[v] == 3)
		{
			// node - v is a cross edge
			// unimportant
		}
	}
	color[v] = 3;
}
void solve()
{
	int n,m;
	cin >> n >> m;
	adj.assign(n+1,vector<int>());
	// adj.resize(n+1);
	f = false;
	color.assign(n+1,1);
	// parent.assign(n+1,0);
	for(int i=0;i<m;i++)
	{
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
	}
	for(int i=1;i<=n;i++)
	{
		if(color[i] == 1)
		{
			dfs(i);
		}
	}
	
	cout << ((f)?"Yes":"No") << '\n';
}
signed main()
{
	int tt;
	cin >> tt;
	while(tt--)
	{
		solve();
	}
}
