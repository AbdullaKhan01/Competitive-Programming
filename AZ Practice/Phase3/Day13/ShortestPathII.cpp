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
const int INF = 1e18;

int par[1001][1001];
// if we want to print the shortest path from i to j
// then we keep track of the parent in floyd warshall 
// algo and then just process that to print the path

void printPath(int i,int j)
{
	if(i != j) printPath(i,par[i][j]);
	cout << j << " ";
}
void printPathIterative(int i,int j)
{
	vector<int> path;
	int parent = j;
	while(i != parent)
	{
		path.push_back(parent);
		parent = par[i][parent];
	}
	path.push_back(i);
	reverse(path.begin(),path.end());
	output(path);
}


/*

very important what is par[i][j] storing

lets say for the optimal path from i to j

i->j the path is i->x->y->.....->par[i][j]->j

so par[i][j] is storing the node that is just before j
in the optimal shortest path from i to j

now using this node par[i][j] we can find the node
just before par[i][j] in the optimal path from i to par[i][j]

that node will be par[i][par[i][j]] by definition of this
parent array

*/
void pathFloyd()
{
	int n,m,q;
	cin >> n >> m >> q;
	vector<vector<int>>dist(n+1,vector<int>(n+1,INF));
	for(int i=0;i<m;i++)
	{
		int a,b,c;
		cin >> a >> b >> c;
		dist[a][b] = min(dist[a][b],c);
		dist[b][a] = min(dist[b][a],c);
	}
	for(int i=1;i<=n;i++) dist[i][i] = 0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			par[i][j] = i;
		}
	}

	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(dist[i][j] > dist[i][k] + dist[k][j])
				{
					dist[i][j] = dist[i][k]+dist[k][j];	

					// going from i to k then k to j
					par[i][j] = par[k][j];
					// storing to print the path

					// be careful of no path
				}
			}
		}
	}
	while(q--)
	{
		int i,j;
		char ch;
		cin >> ch >> i >> j;
		if(ch == 'P')
		{
			printPathIterative(i,j);
			cout << endl;
		}
		else
		{
			if(dist[i][j] == INF) cout << -1 << endl;
			else cout << dist[i][j] << endl;
		}
	}
}
void solve()
{
	int n,m,q;
	cin >> n >> m >> q;
	vector<vector<int>>dist(n+1,vector<int>(n+1,INF));
	for(int i=0;i<m;i++)
	{
		int a,b,c;
		cin >> a >> b >> c;
		dist[a][b] = min(dist[a][b],c);
		dist[b][a] = min(dist[b][a],c);
	}
	for(int i=1;i<=n;i++) dist[i][i] = 0;

	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}
	while(q--)
	{
		int a,b;
		cin >> a >> b;
		if(dist[a][b] == INF) cout << -1 << endl;
		else cout << dist[a][b] << endl;
	}
}
signed main(){
	fast_io();
    int tt = 1;
    // cin >> tt;
    while(tt--)
    {
    	pathFloyd();
    }
    return 0;
}