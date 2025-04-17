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
int dx[] = {0,-1,0,+1};
int dy[] = {-1,0,+1,0};
int n,m;
vector<vector<int>>a;
vector<vector<int>>vis;
bool isSafe(int i,int j)
{
	return (i>=1&&i<=n&&j>=1&&j<=m);
}
vector<pair<int,int>>children(pair<int,int>&k)
{
	vector<pair<int,int>>ans;
	for(int i=0;i<4;i++)
	{
		int r = k.first + dx[i];
		int c = k.second + dy[i];
		if(isSafe(r,c) && a[r][c] == 0)
		{
			ans.push_back({r,c});
		}
	}
	return ans;
}
void bfs(int i,int j)
{
	queue<pair<int,int>>q;
	vis[i][j] = 1;
	q.push({i,j});
	vector<pair<int,int>>temp;
	while(!q.empty())
	{
		pair<int,int> node = q.front();q.pop();
		temp.push_back(node);
		for(auto v:children(node))
		{
			if(!vis[v.first][v.second])
			{
				vis[v.first][v.second] = 1;
				q.push(v);
			}
		}
	}
	if(temp.size() <= 1) return ;
	for(auto it:temp)
	{
		a[it.first][it.second] = temp.size();
	}
}
void solve()
{
	cin >> n >> m;
	a.assign(n+1,vector<int>(m+1,0));
	vis.assign(n+1,vector<int>(m+1,0));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin >> a[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j] == 0 && !vis[i][j])
			{
				bfs(i,j);
			}
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
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



// _ _ _ _ (1/5/9) 