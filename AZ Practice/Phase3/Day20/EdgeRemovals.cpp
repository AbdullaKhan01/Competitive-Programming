#include<bits/stdc++.h>
using namespace std; 
#define output(x) for(auto &a:x) {cout << a << " ";}cout << endl;
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
int n,m,q;
void solve()
{
	cin >> n >> m >> q;
	vector<pair<int,int>>a(m+1);
	vector<int> done(m+1);
	for(int i=1;i<=m;i++)
	{
		cin >> a[i].first >> a[i].second;
	}
	vector<int> s(q);
	for(int i=0;i<q;i++)
	{
		int x;cin >> x;
		if(x == 1)
		{
			int b;cin >> b;
			s[i] = b;
			done[b] = 1;
		}
		else s[i] = -1;
	}
	UnionFind d(n);
	for(int i=1;i<=m;i++)
	{
		if(!done[i]) d.merge(a[i].first,a[i].second); 
	}
	vector<int> ans;
	for(int i=q-1;i>=0;i--)
	{
		if(s[i] == -1) ans.push_back(d.set_size);
		else
		{
			int node = s[i];
			d.merge(a[node].first,a[node].second);
		}
	}
	reverse(ans.begin(),ans.end());
	for(auto it:ans)
	{
		cout << it << endl;
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