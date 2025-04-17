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
vector<vector<int>>tree;
vector<int> child;
int dp[300005];
void calc(int node,int parent)
{
	int ans = 1;
	for(auto v : tree[node])
	{
		if(v != parent)
		{
			calc(v,node);
			ans += child[v];
		}
	}
	child[node] = ans;
}
void dfs(int node,int parent)
{
	// int s_node = node , maxi = -1;

	// dp[i] = max(s[j] - 1 + dp[j])
	int ans = 0;
	for(auto v : tree[node])
	{
		if(v != parent)
		{
			dfs(v,node);
			ans += dp[v];
		}
	}
	for(auto v : tree[node])
	{
		if(v != parent)
			dp[node] = max(dp[node],ans + child[v] - 1 - dp[v]);	
	}
}
void solve()
{
	cin >> n;
	tree.assign(n+1,vector<int>());
	child.assign(n+1,0);
	memset(dp,0,sizeof(dp));
	for(int i=0;i<n-1;i++)
	{
		int u,v;
		cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	calc(1,-1);
	dfs(1,-1);
	cout << dp[1] << endl;
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