#include<bits/stdc++.h>
using namespace std; 
/* 
for fast input output use printf and scanf;
*/
/*
Every node has a single parent

find(x) finds the topmost parent of node x that does
not have a parent

merge(x,y) -> find(x) find(y) merge them 

Rank Compression rank definition depends on use case
rank = height
rank = size 

(smaller to larger) merging so can we do not form a chain


rank[x] = size of representative of x

max height of tree O(log n) complicated maths proof 
available try to read about it

Path Compression -> par[x] = find(par[x]) this line
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
void solve()
{
	
}
signed main(){
    int tt = 1;
    // cin >> tt;
    while(tt--)
    {
    	solve();
    }
    return 0;
}