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
vector<int> g[200100];
int dep[200100];
int par[200100];
bool isLeaf[100100];
int subTreeSz[100100];
int numChild[100100];

void dfs(int node,int parent,int depth)
{
	dep[node] = depth;
	par[node] = parent;

	for(auto v:g[node])
	{
		if(v!=parent)
		{
			dfs(v,node,depth+1);
		}
	}

}

//Q ) given a tree we can go to any edge and then come back
// from it the cost of 1 move is 1unit . We can start from 
// any node and we don't necessarily have to come back unless
// not needed . Find the minimum cost of traversing the whole
// tree starting from any arbitrary node.

// fact -> if we had to come back to the original node then 
// no matter what node we choose even edge would have been
// traversed twice in the optimal path so the cost
// would have been 2 * no of edges = (2 * E)

// in the above question -> the cost of path length is being 
// saved (path from starting node to ending node)

// so ans will be (2E - path length)

// since we want to minimize the above expression so we need
// to maximize the path length and the maximum path length
// in a tree is the diameter of the tree.

// hence answer is 2E - diameter

void diameter()
{
	dfs(1,0,0);
	int maxch = 1;
	for(int j=2;j<=n;j++)
	{
		if(dep[j] > dep[maxch])
		{
			maxch = j;
		}
	}
	dfs(maxch,0,0);
	maxch = 1;	
	for(int j=2;j<=n;j++)
	{
		if(dep[j] > dep[maxch])
		{
			maxch = j;
		}
	}
	cout << dep[maxch] << endl;
}

// FACTS

// center of a tree is the mid point of a diameter

// a tree can have at max 2 centers 

// all diameters pass through all centers of a tree.


void solve()
{
	
	cin >> n;
	for(int i=0;i<n-1;i++)
	{
		int a,b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}	
	diameter();
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