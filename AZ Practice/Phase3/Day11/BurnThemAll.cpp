#include<bits/stdc++.h>
#define int long long
#define MP make_pair
using namespace std; 
/* 
for fast input output use printf and scanf;
*/
using ii = pair<int,int>;
#define f first
#define s second

class prioritize
{
	public: bool operator()(ii &p1, ii&p2){
			return p1.s > p2.s;
		}
};
int n,m;
vector<ii> g[200100];

int dist[200100];
int vis[200100];

void dijkstra(int sc)
{
	for(int i=1;i<=n;i++)
	{
		dist[i] = 1e18;
		vis[i] = 0;
	}
	dist[sc] = 0;
	priority_queue<ii,vector<ii>,prioritize> pq;
	pq.push(MP(sc,0));
	while(!pq.empty())
	{
		ii fs = pq.top();pq.pop();
		if(vis[fs.f]) continue;
		else
		{
			vis[fs.f] = 1;
			for(auto v:g[fs.f])
			{
				int neigh = v.f;
				int wt = v.s;
				if(dist[neigh] > dist[fs.f] + wt)
				{
					dist[neigh] = dist[fs.f] + wt;
					pq.push(MP(neigh,dist[neigh]));
				}
			}
		}
	}
}


void solve()
{
	cin >> n >> m;
	for(int i=0;i<m;i++)
	{
		int a,b,c;
		cin >> a >> b >> c;
		g[a].push_back({b,c});
		g[b].push_back({a,c});
	}
	int sc;
	cin >> sc;
	dijkstra(sc);
	int ans = 0;
	for(int i=1;i<=n;i++)
	{
		for(auto it:g[i])
		{
			int a = i;
			int b = it.first;
			int d = it.second;

			int mn = min(dist[a],dist[b]);
			int mx = max(dist[a],dist[b]);

			// int bound = min(dist[a],dist[b]) + d;
			

			int maxT = 10*mx;

			int val = (d-(mx-mn)) * 10;

			int totalT = maxT + val/2;

			ans = max(ans,totalT); 
		}
	}
	cout << ans << endl;
}

signed main(){

	solve();
    return 0;
}