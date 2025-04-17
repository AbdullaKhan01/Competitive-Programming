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
vector<string>a;
vector<vector<int>>visited;
int delR[] = {0,-1,0,+1};
int delC[] = {-1,0,+1,0};

bool isSafe(int r,int c)
{
	return r>=0 && r<n && c>=0 && c<m;
}
void dfs(int r,int c)
{
	visited[r][c] = 1;
	for(int i=0;i<4;i++)
	{
		int nrow = r + delR[i];
		int ncol = c + delC[i];
		if(isSafe(nrow,ncol) && !visited[nrow][ncol] && a[nrow][ncol] == '.')
		{
			dfs(nrow,ncol);
		}
	}
}
void solve()
{

	cin >> n >> m;
	visited.resize(n+1);
	a.resize(n);
	for(int i=0;i<n;i++)
	{
		visited[i].assign(m+1,0);
	}
	
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
	}
	int ans = 0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(a[i][j] == '.' && !visited[i][j])
			{
				ans++;
				dfs(i,j);
			}
		}
	}
	cout << ans << endl;
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