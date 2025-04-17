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


//VERDICT -> ACCEPTED
using ii = pair<int,int>;
int n,m;
vector<vector<int>>g;
int dis[1001][1001];

pair<int,int> dx[] = {{},{0,1},{0,-1},{1,0},{-1,0}};

bool isSafe(int i,int j)
{
	return (i >= 1 && i <= n && j >= 1 && j <= m);
}
void BFS01(ii sc)
{
	deque<ii> dq;
	dis[sc.first][sc.second] = 0;
	dq.push_back(sc);
	while(!dq.empty())
	{
		ii st = dq.front();
		dq.pop_front();
		int i = st.first;
		int j = st.second;
		for(int k=1;k<=4;k++)
		{
			int r = i + dx[k].first;
			int c = j + dx[k].second;
			int w = (1 - (g[i][j] == k));
			if(isSafe(r,c))
			{

				if(dis[r][c] > dis[i][j] + w)
				{
					dis[r][c] = dis[i][j] + w;
					if(w == 0)
					{
					
						dq.push_front({r,c});
					}
					else
					{
						dq.push_back({r,c});
					}
				}
			}	
		}
	}
}
void solve()
{
	cin >> n >> m;
	g.assign(n+1,vector<int>(m+1,0));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin >> g[i][j];
			dis[i][j] = 1e9;	
		}
	}
	
	BFS01({1,1});
	// -> we have shortest distance from sc to everyNode
	cout << dis[n][m] << endl;
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