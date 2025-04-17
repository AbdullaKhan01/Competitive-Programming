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
vector<set<int>> g;
vector<int> compo;
void dfs(int node,vector<int> &vis,int x){
	// cout << "here" << node << " " << x << endl;
	vis[node] = 1;
	compo[node] = x;
	for(auto v : g[node]){
		// cout << "child of " << node << " is " << v << endl;
		if(!vis[v]){
			// cout << "doing dfs" << endl;
			dfs(v,vis,x);
		}
	}
}
void solve()
{
	int n,m1,m2;
	cin >> n >> m1 >> m2;
	map<pair<int,int>,int> mp,mp1,mp2;
	g.assign(n+1,set<int>());
	compo.assign(n+1,0);
	for(int i=0;i<m1;i++){
		int u,v;
		cin >> u >> v;
		if(u < v) swap(u,v);
		pair<int,int> k = {u,v};
		mp1[k] = 1;
	}
	for(int i=0;i<m2;i++){
		int u,v;
		cin >> u >> v;
		if(u < v) swap(u,v);
		g[u].insert(v);
		g[v].insert(u);
		pair<int,int> k = {u,v};
		mp2[k] = 1;
	}
	int cnt = 0;
	// for adding check g
	for(auto it : mp2){
		pair<int,int> x = it.first;
		if(mp1.count(x)) continue;
		else{
			cnt++;
			int u = x.first,v = x.second;
			g[u].insert(v);
			g[v].insert(u);
		}
	}
	int x = 0;
	vector<int> vis(n+1,0);
	for(int i=1;i<=n;i++){
		if(!vis[i])
			dfs(i,vis,x);
		x++;
	}
	// for subtracting check compo
	for(auto it : mp1){
		pair<int,int> x = it.first;
		int u = x.first;
		int v = x.second;
		if(compo[u] == compo[v]) continue;
		else cnt++;
	}
	cout << cnt << endl;
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