
// #include <bits/stdc++.h>
// using namespace std;

// vector<vector<int>>dis;
// vector<vector<int>>vis;
// int dx[] = {+1,+1,-1,-1,+2,+2,-2,-2};
// int dy[] = {+2,-2,+2,-2,+1,-1,+1,-1};

// vector<pair<int,int>>child(pair<int,int>&a,int n)
// {
// 	vector<pair<int,int>>ans;
// 	for(int i=0;i<8;i++)
// 	{
// 		int r = a.first + dx[i];
// 		int c = a.second + dy[i];
// 		if(r>=1&&r<=n&&c>=1&&c<=n && !vis[r][c])
// 		{
// 			ans.push_back({r,c});
// 		}
// 	}
// 	return ans;
// }
// int KnightWalk(int N, int Sx, int Sy, int Fx, int Fy)
// {
// 	// Complete the function
// 	dis.assign(N+1,vector<int>(N+1,0));
// 	vis.assign(N+1,vector<int>(N+1,0));

// 	queue<pair<int,int>>q;
// 	dis[Sx][Sy] = 0;
// 	vis[Sx][Sy] = 1;
// 	q.push({Sx,Sy});
// 	while(!q.empty())
// 	{
// 		pair<int,int> a = q.front();
// 		q.pop();
// 		if(a.first == Fx && a.second == Fy)
// 		{
// 			return dis[Fx][Fy];
// 		}
// 		for(pair<int,int> c:child(a,N))
// 		{
// 			if(!vis[c.first][c.second])
// 			{
// 				dis[c.first][c.second] = dis[a.first][a.second]+1;
// 				vis[c.first][c.second] = 1;
// 				q.push(c);
// 			}
// 		}
// 	}
// 	return -1;
// }


// int main()
// {
// 	ios_base::sync_with_stdio(0);
// 	cin.tie(NULL);
// 	cout.tie(NULL);

// 	int test_case;
// 	cin >> test_case;

// 	while (test_case--)
// 	{
// 		int N, Sx, Sy, Fx, Fy;
// 		cin >> N >> Sx >> Sy >> Fx >> Fy;

// 		cout << KnightWalk(N, Sx, Sy, Fx, Fy) << "\n";
// 	}
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

const int INF = 1e9;
int n,sx,sy,fx,fy;
vector<vector<int>>dis;
vector<vector<bool>>vis;

int dx[] = {+1,+1,-1,-1,+2,+2,-2,-2};
int dy[] = {+2,-2,+2,-2,+1,-1,+1,-1};

bool isSafe(int r,int c)
{
	return (r>=1&&r<=n&&c>=1&&c<=n);
}
vector<pair<int,int>> children(pair<int,int> &a)
{
	vector<pair<int,int>> ans;
	for(int i=0;i<8;i++)
	{
		int r = a.ff + dx[i];
		int c = a.ss + dy[i];
		if(isSafe(r,c) && !vis[r][c])
		{
			ans.push_back({r,c});
		}
	}
	return ans;
}
void bfs(int r,int c)
{
	queue<pair<int,int>> q;
	q.push({r,c});
	dis[r][c] = 0;
	vis[r][c] = 1;
	while(!q.empty())
	{
		pair<int,int> a = q.front();q.pop();
		if(a.first == fx && a.second == fy)
		{
			// return dis[fx][fy];
			return ;
		}
		for(pair<int,int> v:children(a))
		{
			dis[v.first][v.second] = dis[a.first][a.second]+1;
			vis[v.first][v.second] = 1;
			q.push(v);	
		}
	}
	// return -1;
}
void solve()
{
	cin >> n >> sx >> sy >> fx >> fy;
	dis.assign(n+1,vector<int>(n+1,INF));
	vis.assign(n+1,vector<bool>(n+1,0));
	if(sx == fx && sy == fy)
	{
		cout << 0 << endl;
		return ;
	}
	bfs(sx,sy);
	// cout << bfs(sx,sy) << endl;
	if(dis[fx][fy] != INF)
		cout << dis[fx][fy] << endl;
	else cout << -1 << endl;
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