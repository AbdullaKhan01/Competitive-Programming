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
int maxi;
vector<int> par;
vector<vector<int>> tree;
vector<int> freq;
int dfs(int node,int parent,int dep){
	maxi = max(maxi,dep);
	if(dep > 0){
		// all values from 0 to dep-1 to increase by 1
		par[0] += 1;
		par[dep] -= 1;
	}
	int val = dep;
	for(auto v : tree[node]){
		if(v != parent){
			// there is an edge from node to v
			int k = dfs(v,node,dep+1);
			val = max(val,k);
			// it goes to max k dep
		}
	}
	// node n goes to all values from val+1 to end increase
	// by 1

	par[val+1] += 1;
	par[n] -= 1; 
	return val;
}
void solve()
{
	maxi = 0;
	cin >> n;
	par.assign(n+1,0);
	tree.assign(n+1,vector<int>());
	freq.assign(n+1,0);
	for(int i=0;i<n-1;i++){
		int u,v;
		cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	dfs(1,0,0);
	int ans = 1e9;
	// cout << n << endl;
	for(int i=0;i<n;i++){
		if(i > 0)
			par[i] += par[i-1];
		// cout << i << " " << par[i] << endl;
		ans = min(ans,par[i]);
	}
	cout << ans << endl;
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