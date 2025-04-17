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
using state = pair<ii,int>;
int n,m;
vector<vector<pair<int,int>>>g;
int dis[100100];

void BFS01(int node)
{
	deque<int> dq;
	dis[node] = 0;
	dq.push_back(node);
	while(!dq.empty())
	{
		int node = dq.front();
		dq.pop_front();
		for(auto v:g[node])
		{
			int neigh = v.first;
			int w = v.second;
			if(dis[neigh] > dis[node] + w)
			{
				dis[neigh] = dis[node] + w;
				if(w == 0)
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
	g.assign(n+1,vector<pair<int,int>>());
	for(int i=1;i<=n;i++)
	{
		dis[i] = 1e9;
	}
	set<pair<pair<int,int>,int>> st1,st2;
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin >> a >> b;
		g[a].push_back({b,0});	
		g[b].push_back({a,1});
	}
	BFS01(1);
	if(dis[n] == 1e9) cout << -1 << endl;
	else cout << dis[n] << endl;
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