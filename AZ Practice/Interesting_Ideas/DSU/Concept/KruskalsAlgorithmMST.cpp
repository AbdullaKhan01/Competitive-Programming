#include<bits/stdc++.h>
#define fast_io() ios::sync_with_stdio(0);cin.tie(0);
#define int long long
using namespace std; 
/* 
for fast input output use printf and scanf;
*/

/*

Find Minimum Spanning Tree (MST) sum of edge weights
is minimum

2 algorithms

Kruskal's Algo
Prim's Algo

we will learn Kruskal's Algo

1.sort edges based on weight
2.iterate on edges if edges not connected add that 
edge otherwise skip

this is just the Algorithm and we will have the final
Minimum Spanning Tree

G(V,E)
Time Complexity -> O(ElogE + (E+V)alpha(V))

ElogE -> sorting edges
(E+V) alpha V -> find and merge for each edge

*/


struct UnionFind
{
	int n,set_size;
	vector<int> parent,rank;
	UnionFind(){}
	UnionFind(int a)
	{
		n = set_size = a;
		parent.resize(n+1);
		rank.resize(n+1);
		for(int i=1;i<=n;i++)
		{
			parent[i] = i;
			rank[i] = 1;
		}
	}
	int find(int x)
	{
		if(x != parent[x]) 
		{
			return parent[x] = find(parent[x]);
		}
		else return x;
	}
	void merge(int x,int y)
	{
		int xroot = find(x) , yroot = find(y);
		if(xroot != yroot)
		{
			if(rank[xroot] >= rank[yroot])
			{
				parent[yroot] = xroot;
				rank[xroot] += rank[yroot];
			}
			else
			{
				parent[xroot] = yroot;
				rank[yroot] += rank[xroot];
			}
			set_size -= 1;
		}
	}
	//Complexity of Union Find is AuckerMan of (x)
	// of alpha(x) which is log(log(n)) -> very small value
	// nearly equal to O(1)
	void reset()
	{
		set_size = n;
		for(int i=1;i<=n;i++)
		{
			parent[i] = i;
			rank[i] = 1;
		}
	}
};
vector<pair<int,int>> g[100100];
void solve()
{
	int n,m;
	cin >> n >> m;
	
	UnionFind dsu(n);

	vector<pair<int,pair<int,int>>> edgeList;

	int a,b,c;
	for(int i=0;i<m;i++)
	{
		cin >> a >> b >> c;
		// g[a].push_back({b,c});
		// g[b].push_back({a,c});
		edgeList.push_back({c,{a,b}});
	}
	sort(edgeList.begin(),edgeList.end());

	int mst_cost = 0;
	int cnt = 0;

	for(auto v:edgeList)
	{
		int x = v.second.first;
		int y = v.second.second;

		if(dsu.find(x) != dsu.find(y))
		{
			mst_cost += v.first;
			dsu.merge(x,y);

			// forming the MST
			// g[x].push_back({y,v.first});
			// g[y].push_back({x,v.first});
			cnt++;
		}
	}

	if(cnt != n-1) // because there are n-1 edges in tree
	{
		cout << "IMPOSSIBLE\n";
		return;
	}
	cout << mst_cost << endl;
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