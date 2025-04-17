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
int dp[200200][15];
void solve()
{
	cin >> n >> q;
	UnionFind d(n);
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<15;j++)
		{
			dp[i][j] = 0;
		}
	}
	while(q--)
	{
		int a,diff,k;
		cin >> a >> diff >> k;
		int last = a + (k * diff);
		int cnt = 0;
		for(int i=k;i>=0;i--)
		{
			int node = a + (i * diff);
			d.merge(last,node);
			dp[last][diff] = 1;
			last = node;
			if(dp[last][diff] == 1) cnt++;
			if(cnt >= 3) break;
			last = node;
		}
		
		int first = a;
		cnt = 0;
		for(int i=0;i<=k;i++)
		{
			int node = a + (i * diff);
			d.merge(first,node);
			dp[first][diff] = 1;
			first = node;
			if(dp[first][diff] == 1) cnt++;
			if(cnt >= 3) break;
			first = node;
		}
	}
	cout << d.set_size << endl;
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
    int tt = 1;
    cin >> tt;
    while(tt--)
    {
    	solve();
    }
    return 0;
}