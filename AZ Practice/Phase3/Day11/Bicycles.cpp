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

using ii = pair<int,int>;
int n,m;
vector<vector<pair<int,int>>>g;

int dist[1001][1001];
int vis[1001][1001];
int slow[1001];

void dijkstra(int sc,int bike)
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			dist[i][j] = 1e18;
			vis[i][j] = 0;	
		}
		
	}
	dist[sc][bike] = 0;
	set<pair<ii,int>> pq;
	pq.insert({{sc,1},0});
	while(!pq.empty())
	{
		auto fs = *pq.begin();pq.erase(fs);
		int node = fs.first.first;
		int bike = fs.first.second;
		int d = fs.second;
		
		if(vis[node][bike])
		{
			continue;
		}
		vis[node][bike] = 1;
		for(auto v:g[node])
		{
			int neigh = v.first;
			int w = v.second;

			int n_bike = bike;
			if(slow[node] < slow[bike])
			{
				n_bike = node;
			}

			if(dist[neigh][n_bike] > d + w * slow[n_bike])
			{
				dist[neigh][n_bike] = d + w * slow[n_bike];
				pq.insert({{neigh,n_bike},dist[neigh][n_bike]});
			}
		}	
	}
}

void solve()
{
	cin >> n >> m;
	g.assign(n+1,vector<pair<int,int>>());
	for(int i=0;i<m;i++)
	{
		int a,b,c;
		cin >> a >> b >> c;
		g[a].push_back({b,c});
		g[b].push_back({a,c});
	}
	for(int i=1;i<=n;i++)
	{
		cin >> slow[i];
	}
	dijkstra(1,1);
	int ans = LLONG_MAX;
	for(int i=1;i<=n;i++)
	{
		ans = min(ans,dist[n][i]);
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