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
Q). Given A Graph with N nodes and M queries in each query
u are given an Edge x,y remove the edge from x to y
and then print after each query the no of connected 
components

(1) A good way to solve this is to think in the reverse 
direction for eg after removing all the edges there will
be N nodes not connected to each other so the no of 
connected components will be N then add edges in reverse
direction and get the connected components finally print
the answer in reverse direction

also if not all edges are removed in the last then also
we can keep a map of all the query edges now build the
graph again without adding the edges from the queries 
in the DSU and then simulate the above process no (1).

*/

void solve(){
		
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