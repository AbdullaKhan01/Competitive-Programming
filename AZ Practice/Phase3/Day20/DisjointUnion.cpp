#include<bits/stdc++.h>
using namespace std; 
/* 
for fast input output use printf and scanf;
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
int n,q;
void solve()
{
	cin >> n >> q;
	UnionFind d(n);
	while(q--)
	{
		int a,x,y;
		cin >> a >> x >> y;
		if(a == 0)
		{
			d.merge(x,y);	
		}
		else
		{
			// a == 1;
			cout << (d.find(x) == d.find(y)) << endl;
		}
	}
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
    int tt = 1;
    // cin >> tt;
    while(tt--)
    {
    	solve();
    }
    return 0;
}