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
const int inf = 1e18;
int n,m;
int g[2001][2001];
int dist[2001][2001];
int vis[2001][2001];
vector<pii> portal;
map<pii,int> mp;
void dijkstra(int i,int j)
{
	// shortest path to every cell in the grid
	priority_queue<pair<int,pair<int,int>>> pq;
	// {{coordinate},dist}
	pq.push({0,{i,j}});
	while(!pq.empty())
	{
		auto top = pq.top(); pq.pop();
		
	}
}
void solve()
{

	cin >> n >> m;
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			dist[i][j] = inf;
			vis[i][j] = 0;
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin >> g[i][j];
			if(g[i][j] != 0 && g[i][j] != -1)
			{
				portal.push_back({i,j});
				mp[{i,j}]++;
			}
		}
	}
	dijkstra(0,0);
	cout << dist[n-1][m-1] << endl;
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