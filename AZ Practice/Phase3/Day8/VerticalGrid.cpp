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

// VERDICT -> ACCEPTED

int n,m,k;
vector<vector<int>>g;
vector<vector<int>>v;

vector<pair<int,int>> rem;

bool removed = 1;

int dx[] = {0,-1,0,+1};
int dy[] = {-1,0,+1,0};

bool isSafe(int i,int j)
{
	return (i >= 1 && i <= n && j >= 1 && j <= m);
}
vector<pair<int,int>> neighbours(pair<int,int>&node)
{
	vector<pair<int,int>>ans;
	for(int i=0;i<4;i++)
	{
		int r = node.first + dx[i];
		int c = node.second + dy[i];

		if(isSafe(r,c) && !v[r][c] && g[r][c] == g[node.first][node.second])
		{
			ans.push_back({r,c});
		}
	}
	return ans;
}

void bfs(int i,int j)
{
	queue<pair<int,int>>q;
	v[i][j] = 1;
	q.push({i,j});
	int cnt = 0;
	vector<pair<int,int>> temp;
	while(!q.empty())
	{
		pair<int,int> front = q.front();q.pop();
		temp.push_back({front.first,front.second});
		cnt++;
		for(auto a:neighbours(front))
		{
			v[a.first][a.second] = 1;
			q.push(a);
		}
	}
	if(cnt >= k)
	{
		for(auto it:temp)
		{
			rem.push_back(it);
		}
	}
			
}
void phir_jao()
{
	//process the n*m matrix
	rem.clear();
	v.assign(n+1,vector<int>(m+1,0));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(g[i][j] != 0 && !v[i][j])
			{
				bfs(i,j);
			}
		}
	}
	//handle the zeroes
	// we have got rem
	if(rem.size() > 0)
	{
		removed = 1;
		for(auto it:rem) g[it.first][it.second] = 0;
		for(int c=1;c<=m;c++)
		{
			queue<pair<int,int>>temp;
			for(int r=n;r>=1;r--)
			{
				if(g[r][c] == 0)
				{
					temp.push({r,c});
				}
				else
				{
					// we have a number here
					if(!temp.empty())
					{
						pair<int,int> p = temp.front();temp.pop();
						int fr = p.first;
						int fc = p.second;
						g[fr][fc] = g[r][c];
						g[r][c] = 0;
						temp.push({r,c});
					}
				}
			}
		}	
	}
	else
	{
		removed = 0;
	}
}

void solve()
{
	cin >> n >> k;
	m = 10;
	g.assign(n+1,vector<int>(m+1,0));
	for(int i=1;i<=n;i++)
	{
		string s;
		cin >> s;
		for(int j=1;j<=m;j++)
		{
			g[i][j] = s[j-1] - 48;
		}
	}
	while(removed)
	{
		phir_jao();
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cout << g[i][j];
		}
		cout << endl;
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