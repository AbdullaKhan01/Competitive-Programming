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

struct Info
{
	int min_price;
	int min_price_routes;
	int min_price_min_flights;
	int min_price_max_flights;
	Info()
	{
		min_price = 0;
		min_price_routes = 1;
		min_price_min_flights = 0;
		min_price_max_flights = 0;
	}
	Info(int a,int b,int c,int d)
	{
		min_price = a;
		min_price_routes = b;
		min_price_min_flights = c;
		min_price_max_flights = d;
	}
};

ll modAdd(ll a,ll b){
    ll p = (a%mod + b%mod)%mod;
    return p;
}
ll modSub(ll a,ll b){
    ll p = (a%mod - b%mod)%mod;
    if(p<0) p+=mod;
    return p;
}
ll modMul(ll a,ll b){
    ll p = (a%mod * b%mod)%mod;
    return p;
}

const int INF = 1e18;
int n,m;
vector<vector<pair<int,int>>>g;
vector<Info> nodes;
int dist[100100];
int vis[100100];
void dijkstra(int sc)
{

	for(int i=1;i<=n;i++)
	{
		dist[i] = INF;
		vis[i] = 0;
	}
	priority_queue<pair<int,int>>q;
	dist[sc] = 0;
	q.push({-0,sc});
	while(!q.empty())
	{
		pair<int,int> t = q.top();q.pop();
		int d = -t.first;
		int node = t.second;


		for(auto v:g[node]) 
		{
			int city = v.first;
			int cost = v.second;
			if(dist[city] > d + cost)
			{
				dist[city] = d + cost;
				q.push({-dist[city],city});

				nodes[city].min_price = dist[city];
				nodes[city].min_price_routes = nodes[node].min_price_routes % mod;
				nodes[city].min_price_min_flights = nodes[node].min_price_min_flights + 1;
				nodes[city].min_price_max_flights = nodes[node].min_price_max_flights + 1;

			}
			else if(dist[city] == d + cost)
			{
				
				nodes[city].min_price_routes = modAdd(nodes[city].min_price_routes,nodes[node].min_price_routes);
				nodes[city].min_price_min_flights = min(nodes[city].min_price_min_flights,nodes[node].min_price_min_flights + 1);
				nodes[city].min_price_max_flights = max(nodes[city].min_price_max_flights,nodes[node].min_price_max_flights + 1);

			}
		}
	}
}
void solve()
{
	cin >> n >> m;
	g.resize(n+1);
	nodes.resize(n+1);
	for(int i=0;i<m;i++)
	{
		int a,b,c;
		cin >> a >> b >> c;
		g[a].push_back({b,c});
	}
	dijkstra(1);
	if(dist[n] == INF)
	{
		cout << -1 << endl;
	}
	else
	{
		cout << nodes[n].min_price << " ";
		cout << nodes[n].min_price_routes << " ";
		cout << nodes[n].min_price_min_flights << " ";
		cout << nodes[n].min_price_max_flights << endl;
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