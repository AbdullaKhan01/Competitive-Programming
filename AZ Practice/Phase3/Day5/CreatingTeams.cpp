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

vector<vector<int>>g;
vector<int> color;
bool possible = true;

void dfs(int node,int c)
{
	color[node] = c;
	for(auto v:g[node])
	{
		if(color[v] == 0)
		{
			dfs(v,3 - c);
		}
		if(color[v] == color[node])
		{
			possible = false;
			return ;
		}
	}
}
void solve()
{
	int n,m;
	cin >> n >> m;
	g.resize(n+1);
	color.assign(n+1,0);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i=1;i<=n;i++)
	{
		if(color[i] == 0) dfs(i,1);
	}
	cout << (possible?"YES":"NO") << endl;
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