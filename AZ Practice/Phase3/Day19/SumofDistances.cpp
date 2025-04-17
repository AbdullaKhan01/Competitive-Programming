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
int n;
vector<int> g[200100];
int subtreeSz[200100];
int dep[200100];
int par[200100];

int ans = 0;
void dfs(int node,int parent,int depth)
{
	dep[node] = depth;
	par[node] = parent;
	subtreeSz[node]++;
	for(auto v:g[node])
	{
		if(v!=parent)
		{
			dfs(v,node,depth+1);
			subtreeSz[node] += subtreeSz[v];
		}
	}
}
void dfsagain(int node,int parent)
{
	ans += (subtreeSz[node] * (n-subtreeSz[node]));
	for(auto v:g[node])
	{
		if(v!=parent)
		{
			dfsagain(v,node);
		}
	}
}
void solve()
{

	cin >> n;	
	for(int i=0;i<n-1;i++)
	{
		int a,b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(1,0,0);
	dfsagain(1,0);
	cout << ans << endl;
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