#include<bits/stdc++.h>
using namespace std;

// Q). Given a Tree find the no of nodes which are 
//     part or any cycle

// algorithm is color all nodes as 1 initially
// then color the intermediate nodes which are processed
// as color 2 

// and color the nodes which are completely processed 
// as color 3 

// node - v color[v] = 1 -> this is called forward edge

// (node - v) edge color[node] = 2 color[v] = 2 
// this is called a back edge or the edge which is making
// a cycle

// (node - v) edge color[node] = 2 color[v] = 3 
// this is called a cross edge or the edge which does not
// cause a cycle

// then use the technique of partial sums

vector<vector<int>>g;
vector<int> color;
vector<int> parent;

bool is_cycle = 0;

vector<int> any_cycle;
vector<int> cntcycle;

vector<int> prefixOrder;

void dfs(int node,int par)
{
	parent[node] = par;
	color[node] = 2;
	
	for(auto v:g[node])
	{
		//uncomment this line if graph is undirected
		// if(v == parent[node]) continue;
		if(color[v] == 1)
		{
			// node - v is a forward edge
			dfs(v,node);
		}
		else if(color[v] == 2)
		{
			// node - v is a back edge
			// we found a cycle !!

			if(is_cycle == 0)
			{
				int temp = node;
				while(temp != v)
				{
					any_cycle.push_back(temp);
					temp = parent[temp];
				}
				any_cycle.push_back(temp);
				reverse(any_cycle.begin(),any_cycle.end());

			}
			// edge b/w node - v
			cntcycle[node]++;
			cntcycle[parent[v]]--;
			is_cycle = 1;
		}
		else if(color[v] == 3)
		{
			// node - v is a cross edge
			// unimportant
		}
	}
	color[node] = 3;
	prefixOrder.push_back(node);
}
void solve()
{
	int n,m;
	cin >> n >> m;
	g.resize(n+1);
	is_cycle = 0;
	color.assign(n+1,1);
	parent.assign(n+1,0);
	cntcycle.assign(n+1,0);

	for(int i=0;i<m;i++)
	{
		int x,y;
		cin >> x >> y;
		g[x].push_back(y);
		// g[y].push_back(x);
		if(x == y)
		{
			//self loop
		}
		if(x > y) swap(x,y);
		{
			// edgecnt[{x,y}]++;
			//if(edgecnt{x,y} > 1)
			// {
				// multiple edges handle it here
			// }
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(color[i] == 1)
		{
			dfs(i,0);
		}
	}
	
	for(auto v:prefixOrder)
	{
		cntcycle[parent[v]] += cntcycle[v];

	}
	// this prints some cycle
	// for(auto v:any_cycle)
	// {
	// 	cout << v << " ";
	// }
	int cntnodes = 0;
	for(int i=1;i<=n;i++)
	{
		if(cntcycle[i] > 0) cntnodes++;
	}
	// cout << cntnodes << endl;
	cout << ((is_cycle)?"Yes":"No") << endl;
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
