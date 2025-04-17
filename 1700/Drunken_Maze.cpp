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
const int inf = 1e9;
int dx[] = {0,-1,0,+1};
int dy[] = {-1,0,+1,0};
// int dk[] = {1,2,3,4};
vector<string>g;
vector<vector<int>> vis;
vector<vector<vector<int>>> moves;
vector<vector<vector<int>>>dist;
int n,m;

bool check(pair<int,int> &a)
{
	int r = a.first;
	int c = a.second;
	return (r >= 0 && r < n && c >= 0 && c < m && g[r][c] != '#');
}
void BFS(pair<int,int> &st)
{
	int row = st.first;
	int col = st.second;
	priority_queue<pair<int,pair<pair<int,int>,int>>>pq;
	pq.push({0,{{row,col},-1}});
	while(!pq.empty())
	{
		auto top = pq.top();pq.pop();
		int dist = -top.first;
		int row = top.second.first.first;
		int col = top.second.first.second;
		int leke = top.second.second;
		vector<int> temp(4,0);
		for(int i=1;i<=4;i++){
			int nrow = row + dx[i];
			int ncol = col + dy[i];
			pair<int,int> v = {nrow,ncol};
			if(!check(v)) continue;
			if(leke)
		}
	}

}
void solve()
{
	cin >> n >> m;
	g.assign(n,string());
	vis.assign(n,vector<int>(m,0));
	dist.assign(n,vector<int>(m,inf));
	moves.assign(4,vector<vector<int>>(n+1,vector<int>(m,0)));
	pair<int,int> st,en;
	for(int i=0;i<n;++i)
	{
		cin >> g[i];
		for(int j=0;j<(int)g[i].size();j++)
		{
			if(g[i][j] == 'S') st.first = i,st.second = j;
			if(g[i][j] == 'T') en.first = i,en.second = j;
		}
	}
	BFS(st);
	// cout << moves[2][1][9] << endl;
	int ans = dist[en.first][en.second];
	cout << (ans == inf ? -1 : ans) << endl;
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