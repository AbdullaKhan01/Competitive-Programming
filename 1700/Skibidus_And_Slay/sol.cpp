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

// vector<vector<int>> tree;
// vector<int> val;
// string s;
// void dfs(int node,int parent){
// 	for(auto v : tree[node]){
// 		if(v != parent){
// 			if(val[node] == val[v]){
// 				s[val[node]] = '1';
// 			}
// 			for(auto c : tree[v]){
// 				if(c != node)
// 				{
// 					if(val[node] == val[c]){
// 						s[val[node]] = '1';	
// 					}
// 				}
// 			}
// 			dfs(v,node);
// 		}
// 	}
// }
// void solve()
// {
// 	int n;
// 	cin >> n;	
// 	tree.clear();
// 	tree.assign(n+1,vector<int>());
// 	val.assign(n+1,0);
// 	s.assign(n+1,'0');
	
// 	for(int i=1;i<=n;i++){
// 		cin >> val[i];
// 	}
// 	for(int i=1;i<n;i++){
// 		int u,v;
// 		cin >> u >> v;
// 		tree[u].push_back(v);
// 		tree[v].push_back(u);
// 	}
// 	int root = -1;
// 	for(int i=1;i<=n;i++){
// 		if(tree[i].size() == 1) root = i;
// 	}

// 	dfs(root,-1);
// 	for(int i=1;i<=n;i++){
// 		cout << s[i];
// 	}
// 	cout << '\n';
// }
// signed main(){
// 	fast_io();
//     int tt = 1;
//     cin >> tt;
//     while(tt--)
//     {
//     	solve();
//     }
//     return 0;
// }

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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve()
{
	
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