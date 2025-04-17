#include<bits/stdc++.h>
#define mod 1000000007
#define mod2 998244353
#define ceil(a,b) ((a+b-1)/b)
#define floor(a,b)((a-b+1)/b)
#define fast_io() ios::sync_with_stdio(0);cin.tie(0);
#define ll long long
#define int long long
#define vi vector<int>
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define input(x) for(auto &a:x) cin >> a;
#define output(x) for(auto a:x) cout << a <<" ";
#define rep(i,a,n) for(int i=(a);i<n;i++)
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define ff first
#define ss second
#define si set<int>
#define pii pair<int,int>
#define mii map<int,int>
#define msi map<string,int>
#define yes "YES"
#define no "NO"
#define endl '\n'
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
	int ranking(int x)
	{
		return rank[x];
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
/*

Start from the highest weight first and find all the 
edges it is a part of then add to the answer and then 
do the union of the edges 

*/
void solve()
{
	int n;cin >> n;
	vector<pair<int,pair<int,int>>>edgeList;
	for(int i=0;i<n-1;i++)
	{
		int u,v,w;
		cin >> u >> v >> w;
		edgeList.push_back({w,{u,v}});
	}
	
	UnionFind dsu(n);

	sort(edgeList.rbegin(),edgeList.rend());

	int ans = 0;

	for(auto v:edgeList)
	{

		int w = v.first;
		int a = v.second.first;
		int b = v.second.second;
		// 
		int f1 = dsu.ranking(dsu.find(a));
		int f2 = dsu.ranking(dsu.find(b));

		ans += w * f1 * f2;
		dsu.merge(a,b);
	}
	cout << ans << endl;
}
signed main(){
	fast_io();
    int tt = 1;
    cin >> tt;
    while(tt--)
    {
    	solve();
    }
    return 0;
}