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
int n,m;
vector<vector<pair<int,int>>>g;
int dis[100100];
void BFS01(int sc)
{
	deque<int> dq;
	dis[sc] = 0;
	dq.push_back(sc);
	while(!dq.empty())
	{
		int front = dq.front();
		dq.pop_front();
		for(auto v:g[front])
		{
			int neigh = v.first;
			int weight = v.second;
			if(dis[neigh] > dis[front] + weight)
			{
				dis[neigh] = dis[front] + weight;
				if(weight == 0)
				{
					dq.push_front(neigh);
				}
				else
				{
					dq.push_back(neigh);
				}
			}
		}
	}
}
void solve()
{
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		dis[i] = 1e9;
	}
	g.resize(n+1);
	for(int i=0;i<m;i++)
	{
		int a,b,c;
		cin >> a >> b >> c;
		g[a].push_back({b,c});
		g[b].push_back({a,c});
	}
	int sc,ds;
	cin >> sc >> ds;
	BFS01(sc);
	// -> we have shortest distance from sc to everyNode
	cout << dis[ds] << endl;
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