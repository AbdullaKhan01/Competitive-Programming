// #include<bits/stdc++.h>
// #define mod 1000000007
// #define mod2 998244353
// #define ceil(a,b) ((a+b-1)/b)
// #define floor(a,b)((a-b+1)/b)
// #define fast_io() ios::sync_with_stdio(0);cin.tie(0);
// #define ll long long
// #define int long long
// #define vi vector<int>
// #define all(x) (x).begin(),(x).end()
// #define rall(x) (x).rbegin(),(x).rend()
// #define input(x) for(auto &a:x) cin >> a;
// #define output(x) for(auto a:x) cout << a <<" ";
// #define rep(i,a,n) for(int i=(a);i<n;i++)
// #define pb push_back
// #define ppb pop_back
// #define pf push_front
// #define ppf pop_front
// #define ff first
// #define ss second
// #define si set<int>
// #define pii pair<int,int>
// #define mii map<int,int>
// #define msi map<string,int>
// #define yes "YES"
// #define no "NO"
// #define endl '\n'
// using namespace std; 
// /* 
// for fast input output use printf and scanf;
// */
// int n,m,q;
// vector<vector<int>>g;
// vector<int> vis;
// vector<int> sz;
// void dfs(int node,int cnt,int &curr)
// {
// 	vis[node] = cnt;
// 	for(auto v:g[node])
// 	{
// 		if(!vis[v]) curr++,dfs(v,cnt,curr);
// 	}
// 	sz[node] = curr;
// }
// void solve()
// {
// 	int n,m,q;
// 	cin >> n >> m >> q;
// 	g.resize(n+1);
// 	vis.assign(n+1,0);
// 	sz.assign(n+1,0);
// 	while(m--)
// 	{
// 		int u,v;
// 		cin >> u >> v;
// 		u--,v--;
// 		g[u].push_back(v);
// 		g[v].push_back(u);	
// 	}
// 	int cnt = 0;
// 	for(int i=0;i<n;i++)
// 	{
// 		int curr = 1;
// 		if(!vis[i]){
// 			cnt++;
// 			dfs(i,cnt,curr);	
// 		} 
		
// 	}
// 	while(q--)
// 	{
// 		int tt;
// 		cin >> tt;
// 		if(tt == 1)
// 		{
// 			int x;
// 			cin >> x;
// 			x--;
// 			cout << sz[x] << endl;
// 		}
// 		else
// 		{
// 			int u,v;
// 			cin >> u >> v;
// 			u--,v--;
// 			if(vis[u] == vis[v])
// 			{
// 				cout << "YES" << endl;
// 			}
// 			else
// 			{
// 				cout << "NO" << endl;
// 			}
// 		}
// 	}
// }
// signed main(){
// 	fast_io();
//     int tt = 1;
//     // cin >> tt;
//     while(tt--)
//     {
//     	solve();
//     }
//     return 0;
// }

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
int n,m,q;
vector<vector<int>>g;
vector<int> vis;
void dfs(int node,int curr)
{
	vis[node] = curr;
	for(auto v:g[node])
	{
		if(!vis[v]) dfs(v,curr);
	}
}
void solve()
{
	cin >> n >> m >> q;
	g.resize(n+1);
	vis.assign(n+1,0);
	while(m--)
	{
		int u,v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	int cnt = 0;
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			cnt++;
			dfs(i,cnt);
		}
	}
	map<int,int>mp;
	for(int i=1;i<=n;i++)
	{
		mp[vis[i]]++;
	}

	while(q--)
	{
		int x;
		cin >> x;
		if(x == 1)
		{
			int a;
			cin >> a;
			cout << mp[vis[a]] << endl;
		}
		else
		{
			int a,b;
			cin >> a >> b;
			cout << (vis[a] == vis[b] ? yes:no) << endl;
		}
	}
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