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
vector<int> g[100100];
int dep[100100];
int par[100100];
bool isLeaf[100100];
int subTreeSz[100100];
int numChild[100100];

void dfs(int node,int parent,int depth)
{
	dep[node] = depth;
	par[node] = parent;

	subTreeSz[node] = 1;
	numChild[node] = 0;
	for(auto v:g[node])
	{
		if(v!=parent)
		{
			numChild[node]++;
			dfs(v,node,depth+1);
			subTreeSz[node] += subTreeSz[v];
		}
	}
	if(numChild[node] == 0) isLeaf[node] = 1;

}
void solve()
{
	int n;
	cin >> n;
	for(int i=0;i<n-1;i++)
	{
		int a,b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}	
	dfs(1,0,0);
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