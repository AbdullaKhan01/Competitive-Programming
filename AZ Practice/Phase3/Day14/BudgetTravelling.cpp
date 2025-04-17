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
#define MP make_pair
#define endl '\n'
using namespace std; 
/* 
for fast input output use printf and scanf;
*/
int n,m,k,s,e;
using ii = pair<int,int>;
using st = pair<int,int>;
vector<vector<pair<int,int>>>g;
int dist[10001][101];
int vis[10001][101];
int c[10001];	

void dijkstra(st node)
{
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=k;j++)
		{
			dist[i][j] = 1e9;
			vis[i][j] = 0;
		}
	}
	// cout << dist[e][0] << endl;
	priority_queue<pair<int,ii>> pq;
	dist[node.first][node.second] = 0;
	pq.push(MP(0,MP(node.first,node.second)));
	
	while(!pq.empty())
	{
		auto top = pq.top();pq.pop();

		int curr_dist = -top.first;
		st curr = top.second;
		int city = curr.first;
		int petrol = curr.second;
		
		// important step
		if(vis[city][petrol]) continue;
		vis[city][petrol] = 1;
		//-------

		//travel to neighbouring cities
		for(auto v:g[city])
		{
			if(petrol >= v.second)
			{
				if(dist[v.first][petrol - v.second] > curr_dist + 0)
				{
					dist[v.first][petrol - v.second] = curr_dist + 0;
					pq.push(MP(-curr_dist,MP(v.first,petrol - v.second)));
				}
			}
		}
		//refill the tank
		if(petrol < k)
		{
			if(dist[city][petrol+1] > curr_dist + c[city])
			{
				dist[city][petrol+1] = curr_dist + c[city];
				pq.push(MP(-(curr_dist + c[city]),MP(city,petrol+1)));
			}
		}
	}
}
void solve()
{
	cin >> n >> m;
	g.resize(n+1);
	for(int i=0;i<m;i++)
	{
		int a,b,d;
		cin >> a >> b >> d;
		g[a].push_back(MP(b,d));
		g[b].push_back(MP(a,d));
	}
	for(int i=1;i<=n;i++) cin >> c[i];
	cin >> s >> e >> k;
	dijkstra({s,0});
	// for(int i=0;i<=k;i++)
	// {
	// 	cout << dist[e][i] << " ";
	// }
	cout << dist[e][0] << endl;

	
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