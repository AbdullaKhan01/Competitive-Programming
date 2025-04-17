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
int n;
vector<string> g;
vector<vector<int>>vis;

int dx[] = {0,-1,0,1};
int dy[] = {-1,0,1,0};

int fl = 0,fp=0;
bool isSafe(int i,int j)
{
	return (i >= 0 && i < n && j >= 0 && j < n);
}
void solve2(int i,int j)
{
	queue<pair<int,int>>q;
	vis[i][j] = 1;
	int cnt = 0;
	int cnt2 = 0;
	q.push({i,j});
	while(!q.empty())
	{
		pair<int,int> front = q.front();q.pop();
		cnt++;
		vector<pair<int,int>> temp;
		for(int i=0;i<4;i++)
		{
			int r = front.first + dx[i];
			int c = front.second + dy[i];

			if(!isSafe(r,c) || g[r][c] == '.') cnt2++;
			else temp.push_back({r,c});
		}
		// {1,4} -> {{2,4}}
		for(auto v:temp)
		{
			if(!vis[v.first][v.second])
			{
				vis[v.first][v.second] = 1;
				q.push(v);
			}
		}
	}
	if(cnt == fl)
	{
		fp = min(fp,cnt2);
	}
	else if(cnt > fl)
	{
		fl = cnt;
		fp = cnt2;
	}
}
void solve()
{
	cin >> n;
	g.resize(n+1);
	vis.assign(n+1,vector<int>(n+1,0));
	for(int i=0;i<n;i++)
	{
		cin >> g[i];
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(g[i][j] == '#' && !vis[i][j])
			{
				solve2(i,j);
			}
		}
	}
	cout << fl << " " << fp << endl;

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