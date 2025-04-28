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
Given a Graph G(V,E)

every node has a value Ci and every edge has a value Di

Ci is the cost for Activating the Power Plant at node V
and Di is the cost for Activating the Road connecting the
power plant between the edges now we want every
Power Plant to have good either being made there or 
reaching there through roads 

find the minimum cost to do the whole setup 

Solution -> Add a super node connect it to all the nodes
and the edge cost will be Ci of the node now the MST
of this New Graph is actually the solution

why ? Because the super Node will actually be in the MST
so consider the nodes connected directly to super node in 
the MST of the new Graph as that Node Power Plant 
getting activated by Paying Cost Ci hence the solution



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