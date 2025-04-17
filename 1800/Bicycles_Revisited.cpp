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
int n,m,k,str,e;
using ii = pair<int,int>;
using st = pair<int,int>;
vector<vector<pair<int,int>>>g;
int dist[1001][1001];
int vis[10001][1001];
int s[1001];	

void dijkstra(st node)
{
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=1000;j++)
		{
			dist[i][j] = 1e18;
			vis[i][j] = 0;
		}
	}
	// cout << dist[e][0] << endl;
	// cout << node.first << " " << node.second << endl;
	priority_queue<pair<int,ii>> pq;
	dist[node.first][node.second] = 0;
	pq.push(MP(0,MP(node.first,node.second)));
	
	while(!pq.empty())
	{
		auto top = pq.top();pq.pop();

		int curr_time = -top.first;
		st curr = top.second;
		int city = curr.first;
		int slow = curr.second;
		// cout << "took out " << city << endl;
		// important step
		if(vis[city][slow]) continue;
		vis[city][slow] = 1;
		//-------

		//travel to neighbouring cities
		for(auto v:g[city])
		{	
			//reaching city v using the advanced bike
			int n_slow = min(slow,s[v.first]);
			// cout << "processing " << v.first << " " << n_slow << endl; 
			if(dist[v.first][n_slow] > (curr_time + v.second * slow))
			{
				// cout << "updated " << v.first << " " << n_slow << endl;
				dist[v.first][n_slow] = curr_time + v.second * slow;
				pq.push(MP(-(curr_time + v.second * slow),MP(v.first,n_slow)));
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
	int kp = INT_MIN;
	for(int i=1;i<=n;i++)
	{
		 cin >> s[i];
		 kp = max(kp,s[i]);
	}
	
	str = 1;e = n;
	dijkstra({str,s[1]});
	g.clear();
	int res = LLONG_MAX;
	// cout << dist[1][8] << endl;
	for(int i=1;i<=kp;i++)
	{
		// cout << dist[e][i] << " ";
		res = min(res,dist[e][i]);
	}
	cout << res << endl;

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