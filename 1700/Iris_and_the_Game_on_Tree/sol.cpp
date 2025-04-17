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


	// A = no of leaf node with value 1
	// B = no of leaf node with value 0
	// Q = no of leaf node with value ?
	
	// Leaf node x
	
	// ans = B + (Q+1)/2 00
	
	// Leaf node = ?

	// if Leaf = 1

	// ans = B + Q/2

	// if Leaf = 0

	// ans = A + Q/2
// till here was my approach

// Took help from TLE eliminators video

// if root node value already decided
// -> A = no of leaf nodes with value 1
// -> B = no of leaf nodes with value 0
// -> Q = no of leaf nodes with value ?

// ans = max(A,B) + ceil(Q/2)

// if root node value == ?
// -> A = no of leaf nodes with value 1
// -> B = no of leaf nodes with value 0
// -> Q = no of leaf nodes with value ?

// if A != B
// ans = max(A,B) + floor(Q/2)

// if A == B
// if(no of intermediate nodes with ?) == odd

// ans = max(A,B) + ceil(Q/2)

// if(no of intermediate nodes with ?) == even

// ans = max(A,B) + floor(Q/2)

vector<vector<int>>tree;
string s;
int A,B,Q,inter;

void dfs(int node,int parent){
	if(tree[node].size() == 1){
		if(node != 1){
			A += (s[node-1] == '1'); 
			B += (s[node-1] == '0'); 
			Q += (s[node-1] == '?'); 
		}
	}
	else{
		// cout << "inter is " << node << endl;
		if(node != 1)
			inter += (s[node-1] == '?');
	}
	for(auto v : tree[node]){
		if(v != parent){
			dfs(v,node);	
		}
	}

}
//     1 
//  2 3 4 5 

// 11?1? 
void solve()
{
	int n;cin >> n;
	tree.assign(n+1,vector<int>());
	A = B = Q = inter = 0;
	for(int i=0;i<n-1;i++){
		int u,v;cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	cin >> s;
	dfs(1,0);
	if(s[0] != '?'){
		if(s[0] == '1') cout << B + ceil(Q,2);
		else cout << A + ceil(Q,2);
	}
	else{
		// cout << "here" << endl;
		if(A != B){
			cout << max(A,B) + (Q/2);	
		}
		else{
			// cout << "here" << endl;
			// cout << inter << endl;
			if(inter % 2 == 1){
				cout << max(A,B) + ceil(Q,2);
			}
			else{
				cout << max(A,B) + (Q/2);
			}
		}
	}
	cout << '\n';
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

// LET B = X
// N A - B 
// B <= 10000
// NA - B <= 10000
// THEN DOES SOME A EXIST