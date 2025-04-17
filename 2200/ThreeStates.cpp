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

/*

Mistake -> was using normal BFS instead of 01 BFS

such a fool I am
*/
int n,m;
vector<string>g;
const int INF = 1e9;

int dx[] = {0,-1,0,+1};
int dy[] = {-1,0,+1,0};

bool isSafe(int i,int j)
{
	return (i>=0 && i<n && j>=0 && j<m);
}
vector<pair<int,int>>neigbours(pair<int,int>&a)
{
	vector<pair<int,int>>ans;
	for(int i=0;i<4;i++)
	{
		int r = a.first + dx[i];
		int c = a.second + dy[i];
		if(isSafe(r,c) && g[r][c] != '#')
		{
			ans.push_back({r,c});
		}
	}
	return ans;
}
void bfs(int i,int j,vector<vector<int>>&d)
{
	deque<pair<int,int>>q;
	d[i][j] = 0;
	q.push_back({i,j});
	while(!q.empty())
	{
		pair<int,int> node = q.front();q.pop_front();
		for(auto v:neigbours(node))
		{
			int w = g[v.first][v.second] == '.';
			if(d[v.first][v.second] > d[node.first][node.second] + w)
			{
				d[v.first][v.second] = d[node.first][node.second] + w;
				if(w == 0) q.push_front(v);
				else q.push_back(v);
			}
			
		}
	}
}
void solve()
{
	cin >> n >> m;
	g.resize(n);
	for(int i=0;i<n;i++)
	{
		cin >> g[i];
	}
	vector<vector<int>>d1(n,vector<int>(m,INF));
	vector<vector<int>>d2(n,vector<int>(m,INF));
	vector<vector<int>>d3(n,vector<int>(m,INF));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(g[i][j] == '1' && d1[i][j] == INF) bfs(i,j,d1);
			if(g[i][j] == '2' && d2[i][j] == INF) bfs(i,j,d2);
			if(g[i][j] == '3' && d3[i][j] == INF) bfs(i,j,d3);
		}
	}
	int k = INT_MAX;

	// for(int i=0;i<n;i++)
	// {
	// 	for(int j=0;j<m;j++)
	// 	{
	// 		cout << d1[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(d1[i][j] != INF && d2[i][j] != INF && d3[i][j] != INF)
			{
				// we can use this cell potentially
				int ans = d1[i][j] + d2[i][j] + d3[i][j];
				if(g[i][j] == '.')
				{	
					k = min(k,ans-2);
				}
				else
				{
					k = min(k,ans);
				}
			}
		}
	}
	if(k == INT_MAX) cout << -1 << endl;
	else cout << k << endl;
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