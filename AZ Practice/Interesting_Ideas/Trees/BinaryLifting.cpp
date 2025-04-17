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
// next(node,i) = next(next(node,i-1),i-1)
vector<vector<int>>g;
vector<int> depth;
vector<vector<int>> par;
void dfs(int node,int parent,int dep)
{
	par[node][0] = parent;
	depth[node] = dep;
	// we came through dfs to this node so everything
	// above has been already processed so this for loop
	// can be written
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
	// Two steps of LCA

	// Step 1 : Bring u and v to same depth
	// Step 2 : Try jumping to parent till they are not same

	if(depth[u] < depth[v])
	{
		swap(u,v);
	}
	int h_diff = depth[u] - depth[v];
	// Bringing u to same depth as v
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
	
}
signed main(){

	solve();
    return 0;
}