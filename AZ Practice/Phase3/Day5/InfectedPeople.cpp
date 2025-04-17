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
vector<vector<char>>g;
int dx[] = {0,-1,0,1};
int dy[] = {-1,0,1,0};
bool isSafe(int i,int j)
{
	return (i >= 1 && i <= n && j >= 1 && j <= m);
}
vector<pair<int,int>>neighbour(pair<int,int>&a)
{
	vector<pair<int,int>> ans;
	for(int i=0;i<4;i++)
	{
		int r = a.first + dx[i];
		int c = a.second + dy[i];
		if(isSafe(r,c) && g[r][c] != '0')
		{
			ans.push_back({r,c});
		}
	}
	return ans;
}
void solve()
{
	cin >> n >> m;
	// vector<vector<char>> g(n+1,vector<char>(m+1,' '));
	g.assign(n+1,vector<char>(m+1,' '));
	vector<vector<int>> vis(n+1,vector<int>(m+1,0));
	vector<vector<int>> dis(n+1,vector<int>(m+1,0));
	queue<pair<int,int>> q;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin >> g[i][j];
			if(g[i][j] == '2')
			{
				dis[i][j] = 0;
				vis[i][j] = 1;
				q.push({i,j});
			}
		}
	}
	while(!q.empty())
	{
		pair<int,int> c = q.front();q.pop();
		for(auto v:neighbour(c))
		{
			if(!vis[v.first][v.second])
			{
				dis[v.first][v.second] = dis[c.first][c.second] + 1;
				vis[v.first][v.second] = 1;
				q.push(v);
			}
		}
	}
	int ans = -1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			// cout << disi][j] << " ";
			if(g[i][j] == '1' && dis[i][j] == 0)
			{
				ans = -1;
				break;
			}
			ans = max(ans,dis[i][j]);
		}
		// cout << endl;
	}
	if(ans == -1)
	{
		cout << -1 << endl;
	}
	else
	{
		cout << ans << endl;
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