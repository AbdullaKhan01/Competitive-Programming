#include<bits/stdc++.h>
using namespace std; 
/* 
for fast input output use printf and scanf;
*/
/*
Q). Given a structure where you can not randomly access
some element you can only sequentially go forward or
backward 

Eg. -> LinkedList , Tree

You are Given Q queries of the type

? x k -> find the kth node from the xth node

eg ? 1 5 -> find the 5th node from the 1st node 
== 6th node from the beginning 

To solve this type of problems we can using Binary 
Lifting which is just a technique used to make link
from every node to every node which is 2^i th from 
it 

This means build a link for 2^0 2^1 2^2 .. 2^k th
node for each node 

then we can easily query by just going to 2^(set bit)
from the initial node and continuing until the find
the answer

for eg to find the 13 th node from the 4th node

build all the links in O(NlogN)

then 13 = 1101

go to 8th node from 4 = 12th node

go to 4th node from 12 = 16

go to 1st node from 16 = 7

and we found the 13th node from 4


*/
int n;
vector<vector<int>>g;
vector<int> depth;
vector<vector<int>> par;

int cnt = 1000;
void dfs(int node,int parent,int dep)
{
	// if(cnt)
	// {
	// 	cout << "here " << node << endl;
	// 	cnt--;
	// }
	// else return;
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
		int x,y,z;
		cin >> x >> y >> z;

		int I = lca(x,y);
		int a = lca(x,z);
		int b = lca(y,z);

		if(a == I) cout << b;
		else if(b == I) cout << a;
		else cout << I;
		cout << endl;
		// int x,y;
		// cin >> x >> y;
		// cout << lca(x,y) << endl;
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