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
/*
Learnt something new 
always try to learn
the farthest node from any node of the tree is 
one of the ends of the diameter of the tree

*/
int n,k,c;
int ans;
vector<vector<int>> g;
vector<int> dep;
vector<int> dep2;
vector<int> par;
void dfs(int node,int parent,int depth,bool flag)
{
	flag ? dep[node] = depth : dep2[node] = depth;
	par[node] = parent;
	for(auto v:g[node])
	{
		if(v!=parent)
		{
			dfs(v,node,depth+1,flag);
		}
	}

}
void solve_dfs(int node,int parent,int depth)
{

	// to come till this point depth * c coins
	int maxi = max(dep[node],dep2[node]);
	int total_cost = maxi * k - depth * c;
	ans = max(ans,total_cost);
	par[node] = parent;
	for(auto v:g[node])
	{
		if(v!=parent)
		{
			solve_dfs(v,node,depth+1);
		}
	}

}
int end_point1,end_point2;
void diameter(){
	// take any arbitrary node and find farthest node from
	// there then find the farthest node from that node
	// that will be the diameter end points
	dfs(1,0,0,1);
	int maxi = -1;
	for(int i=1;i<=n;i++){
		if(dep[i] > maxi){
			maxi = dep[i];
			end_point1 = i;
		}
	}
	// got end_point1 do dfs from here
	dfs(end_point1,0,0,1);
	maxi = -1;
	for(int i=1;i<=n;i++){
		if(dep[i] > maxi){
			maxi = dep[i];
			end_point2 = i;
		}
	}
	dfs(end_point2,0,0,0);
	
}
void solve(){
	cin >> n >> k >> c;
	g.assign(n+1,vector<int>());
	dep.assign(n+1,0);
	dep2.assign(n+1,0);
	par.assign(n+1,0);
	ans = -1;
	for(int i=0;i<n-1;i++){
		int u,v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	diameter();
	solve_dfs(1,0,0);
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