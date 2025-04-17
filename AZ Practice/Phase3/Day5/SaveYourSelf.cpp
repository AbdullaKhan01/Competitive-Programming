// #include<bits/stdc++.h>
// #define mod 1000000007
// #define mod2 998244353
// #define ceil(a,b) ((a+b-1)/b)
// #define floor(a,b)((a-b+1)/b)
// #define fast_io() ios::sync_with_stdio(0);cin.tie(0);
// #define ll long long
// // #define int long long
// #define vi vector<int>
// #define all(x) (x).begin(),(x).end()
// #define rall(x) (x).rbegin(),(x).rend()
// #define input(x) for(auto &a:x) cin >> a;
// #define output(x) for(auto a:x) cout << a <<" ";
// #define rep(i,a,n) for(int i=(a);i<n;i++)
// #define pb push_back
// #define ppb pop_back
// #define pf push_front
// #define ppf pop_front
// #define ff first
// #define ss second
// #define si set<int>
// #define pii pair<int,int>
// #define mii map<int,int>
// #define msi map<string,int>
// #define yes "YES"
// #define no "NO"
// #define endl '\n'
// using namespace std; 
// /* 
// for fast input output use printf and scanf;
// */

// const int INF = 1e9;
// vector<string> g;
// vector<vector<vector<int>>>dist;
// int n,m;
// // int dist[1001][1001];
// using a = pair<int,int>;

// int rr[] = {0,-1,0,+1};
// int cc[] = {-1,0,+1,0};
// bool isSafe(int i,int j)
// {
// 	return (i>=0&&i<n&&j>=0&&j<m);
// }
// vector<a> children(a k)
// {
// 	vector<a> ans;
// 	for(int i=0;i<4;i++)
// 	{
// 		int r = k.first + rr[i];
// 		int c = k.second + cc[i];
// 		if(isSafe(r,c) && g[r][c] != '#')
// 		{
// 			ans.push_back({r,c});
// 		}
// 	}
// 	return ans;
// }
// int bfs(int r,int c,int k)
// {
	
// 	// vector<vector<int>>visited(n+1,vector<int>(m+1,0));
// 	// memset(dist,-1,sizeof(dist));
// 	queue<a> q;
// 	dist[k][r][c] = 0;
// 	q.push({r,c});
// 	// visited[r][c] = 1;
// 	while(!q.empty())
// 	{
// 		a front = q.front();q.pop();

// 		for(auto v:children(front))
// 		{
// 			if(dist[k][v.first][v.second] == INF)
// 			{
// 				dist[k][v.first][v.second] = dist[k][front.first][front.second] + 1;
// 				q.push(v);
// 			}
// 		}
// 	}
// 	return -1;
// }
// void solve()
// {
// 	cin >> n >> m;
// 	g.resize(n+1);
// 	int sx,sy;
// 	vector<pair<int,int>>monsters;
// 	for(int i=0;i<n;i++)
// 	{
// 		cin >> g[i];
// 		for(int j=0;j<m;j++)
// 		{
// 			if(g[i][j] == 'A') sx=i,sy=j;
// 			if(g[i][j] == 'M') monsters.pb({i,j});
// 		}	
// 	}
// 	vector<pair<int,int>>b;
// 	for(int i=0;i<n;i++)
// 	{
// 		for(int j=0;j<m;j++)
// 		{
// 			if(i==0||i==n-1||j==0||j==m-1)
// 			{
// 				if(g[i][j] == '.' || g[i][j] == 'A')
// 					b.push_back({i,j});
// 			}
// 		}
// 	}
// 	if(sx == 0 || sx == n || sy == 0 || sy == m)
// 	{
// 		cout << "YES" << endl;
// 		cout << 0 << endl;
// 		return ;
// 	}
// 	bool flag = false;
// 	int ans = INT_MAX;
// 	for(auto it:b)
// 	{
// 		int ddx = it.first , ddy = it.second;
// 		// cout << ddx << " " << ddy << endl;
// 		int min_d = bfs(sx,sy,ddx,ddy);
// 		int min_m = INT_MAX;
// 		for(auto l:monsters)
// 		{
// 			min_m = min(min_m,bfs(l.first,l.second,ddx,ddy));
// 		}
// 		if(min_d != -1)
// 		{
// 			if(min_d < min_m)
// 			{
// 				// answer is bossible
// 				flag = true;
// 				ans = min(ans,min_d);
// 			}
// 		}
// 	}
// 	if(flag)
// 	{
// 		cout << "YES" << endl;
// 		cout << ans << endl;
// 	}
// 	else
// 	{
// 		cout << "NO" << endl;
// 	}

// }
// signed main(){
// 	fast_io();
//     int tt = 1;
//     // cin >> tt;
//     while(tt--)
//     {
//     	solve();
//     }
//     return 0;
// }

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
vector<string> g;
int n,m;
int dx[] = {0,-1,0,1};
int dy[] = {-1,0,1,0};

bool isSafe(int i,int j)
{
	return (i >= 1 && i <= n && j >= 1 && j <= m);
}
vector<pair<int,int>> children(pair<int,int>&a)
{
	vector<pair<int,int>> ans;
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
void solve()
{
	
	cin >> n >> m;
	g.assign(n+1,string(m+1,' '));
	queue<pair<int,int>> mn;
	queue<pair<int,int>> a;
	const int INF = 1e9;
	vector<vector<int>>d1(n+1,vector<int>(m+1,INF));
	vector<vector<int>>d2(n+1,vector<int>(m+1,INF));

	vector<vector<int>>v1(n+1,vector<int>(m+1,0));
	vector<vector<int>>v2(n+1,vector<int>(m+1,0));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin >> g[i][j];
			if(g[i][j] == 'M')
			{
				v1[i][j] = 1;
				d1[i][j] = 0;
				mn.push({i,j});
			}
			if(g[i][j] == 'A')
			{
				v2[i][j] = 1;
				d2[i][j] = 0;
				a.push({i,j});
			}
		}
	}
	while(!mn.empty())
	{
		pair<int,int> p = mn.front();mn.pop();
		for(auto v:children(p))
		{
			if(!v1[v.first][v.second])
			{
				d1[v.first][v.second] = d1[p.first][p.second] + 1;
				v1[v.first][v.second] = 1;
				mn.push(v);
			}
		}
	}
	while(!a.empty())
	{
		pair<int,int> p = a.front();a.pop();
		for(auto v:children(p))
		{
			if(!v2[v.first][v.second] &&g[v.first][v.second] != 'M')
			{
				d2[v.first][v.second] = d2[p.first][p.second] + 1;
				v2[v.first][v.second] = 1;
				a.push(v);
			}
		}
	}
	bool flag = false;
	int ans = INT_MAX;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(i==1||i==n||j==1||j==m)
			{
				if(d2[i][j] < d1[i][j])
				{
					flag = true;
					ans = min(ans,d2[i][j]);
				}
			}
		}
	}

	if(flag)
	{
		cout << yes << endl;
		cout << ans << endl;
	}
	else cout << no << endl;

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