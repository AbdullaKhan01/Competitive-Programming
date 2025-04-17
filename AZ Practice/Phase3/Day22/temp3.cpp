// #include<bits/stdc++.h>
// #define mod 1000000007
// #define mod2 998244353
// #define ceil(a,b) ((a+b-1)/b)
// #define floor(a,b)((a-b+1)/b)
// #define fast_io() ios::sync_with_stdio(0);cin.tie(0);
// #define ll long long
// #define int long long
// #define vi vector<int>
// #define all(x) (x).begin(),(x).end()
// #define rall(x) (x).rbegin(),(x).rend()
// #define input(x) for(auto &a:x) cin >> a;
// #define output(x) for(auto a:x) cout << a <<" ";
// #define rep(i,a,n) for(int i=(a);i<n;i++)
// #define pb push_back
// #define ppb pop_back
// #define pf push_front
// #define ppf pop_front
// #define ff first
// #define ss second
// #define si set<int>
// #define pii pair<int,int>
// #define mii map<int,int>
// #define msi map<string,int>
// #define yes "YES"
// #define no "NO"
// #define endl '\n'
// using namespace std; 
// /* 
// for fast input output use printf and scanf;
// */
// int n;
// vector<int> g[200100];
// int dep[200100];
// int par[200100];

// int c1 = INT_MAX;
// int c2 = INT_MAX;

// int cnt = 0;
// int given = -1;


// vector<int> counter1,counter2;

// void dfs(int node,int parent,int depth)
// {
// 	dep[node] = depth;
// 	par[node] = parent;	



// 	if(dep[node] == given)
// 	{
// 		cnt++;
// 	} 

// 	for(auto v:g[node])
// 	{
// 		if(v != parent)
// 		{
// 			dfs(v,node,depth+1);
// 		}
// 	}


// 	if(parent == c1)
// 	{
// 		counter1.push_back(cnt);
// 		cnt = 0;
// 	}
// 	else if(parent == c2)
// 	{
// 		counter2.push_back(cnt);
// 		cnt = 0;
// 	}
// }
// void diameter()
// {
// 	dfs(1,0,0);
// 	int end1 = 1;
// 	for(int i=1;i<=n;i++)
// 	{
// 		if(dep[i] > dep[end1])
// 		{
// 			end1 = i;
// 		}
// 	}
// 	dfs(end1,0,0);
// 	int end2 = 1;
// 	for(int i=1;i<=n;i++)
// 	{
// 		if(dep[i] > dep[end2])
// 		{
// 			end2 = i;
// 		}
// 	}

// 	// now we have got the end1 and end2 of the diameters
// 	int len = dep[end2];

// 	// cout << len << endl;
// 	int z = len/2;
// 	given = z;
// 	cnt = 0;
// 	if(len % 2 == 0)
// 	{
// 		// 1 center
// 		// to find center go len/2 up from end1 
// 		int node = end2;
// 		given = z;
// 		while(z--)
// 		{
// 			node = par[node];
// 		}
// 		// we have found the center
// 		c1 = node;
		
// 		dfs(c1,0,0);

// 		int ans = 0;
// 		int sum = 0;
// 		for(auto it:counter1)
// 		{
// 			ans += (it*sum);
// 			sum += it;
// 		}
// 		cout << max(1LL,ans) << endl;
// 	}
// 	else
// 	{
// 		// 2 centers
// 		int node = end2;
// 		given = z;
// 		while(z--)
// 		{
// 			node = par[node];
// 		}
// 		c1 = node;
// 		c2 = par[c1];
// 		// cout << c1 << " " << c2 << endl;
		
// 		dfs(c1,c2,0);
// 		dfs(c2,c1,0);

// 		int ans = 0;
// 		int sum = 0;
// 		for(auto it:counter1) sum += it;
// 		for(auto it:counter2) ans += (it*sum);

// 		cout << max(1LL,ans) << endl;
// 	}
	
// }
// void solve()
// {
// 	cin >> n;	
// 	for(int i=0;i<n-1;i++)
// 	{
// 		int a,b;
// 		cin >> a >> b;
// 		g[a].push_back(b);
// 		g[b].push_back(a);
// 	}
// 	diameter();
// }
// signed main(){
// 	fast_io();
//     int tt = 1;
//     // cin >> tt;
//     while(tt--)
//     {
//     	solve();
//     }
//     return 0;
// }		

/*
    Sarthak Johnson Prasad
    A Bondservant of God, if I cheat, may I be banned.
*/

/* Imports */
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

/* Custom Definitions */
#define int long long
#define append push_back
#define all(a) a.begin(), a.end()
#define F first
#define S second

/* Constants */
int MOD = 1e9 + 7;
const int N = 2e5 + 5;

/* Logic */
int n, x, y, len;
int cands[N], depth[N], parent[N];
vector<vector<int>>adj;

void dfs(int node, int par){
	depth[node] = depth[par] + 1;
	parent[node] = par;

	for(int child : adj[node]){
		if(child != par){
			dfs(child, node);
		}
	}
}

void findCands(int node, int par, int dep){
	cands[node] = (dep == len/2);

	for(int child : adj[node]){
		if(child != par){
			findCands(child, node, dep + 1);
			cands[node] += cands[child];
		}
	}
}

void solve(){
	cin >> n;
	adj.resize(n + 1, vector<int>());
	memset(depth, -1, sizeof(depth));

	for(int i = 1; i < n; i++){
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}


	int maxChild = 1;
	dfs(1,0);
	for(int i = 2; i <= n; i++){
		if(depth[i] > depth[maxChild]) maxChild = i;
	}

	dfs(maxChild, 0);
	for(int i = 1; i <= n; i++){
		if(depth[i] > depth[maxChild]) maxChild = i;
	}

	len = depth[maxChild];
	int ans = 0;

	// One center
	if(len % 2 == 0){
		int center = maxChild;
		for(int i  = 0; i < len/2; i++){
			center = parent[center];
		}
		findCands(center, 0, 0);
		int sum = 0;
		for(int child : adj[center]){
			sum += cands[child];
			ans += cands[child] * (cands[center] - sum);
		}
	}
	// Two centers
	else{
		int firstCenter = maxChild;
		for(int i  = 0; i < len/2; i++){
			firstCenter = parent[firstCenter];
		}
		int secondCenter = parent[firstCenter];

		findCands(firstCenter, secondCenter, 0);
		int firstCands = 0;
		for(int child : adj[firstCenter]){
			if(child == secondCenter) continue;
			firstCands += cands[child];
		}

		findCands(secondCenter, firstCenter, 0);
		int secondCands = 0;
		for(int child : adj[secondCenter]){
			if(child == firstCenter) continue;
			secondCands += cands[child];
		}

		ans = firstCands * secondCands;
	}

	cout << ans;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tests = 1;
    // cin >> tests;
    while(tests--){
        solve();
    }
}