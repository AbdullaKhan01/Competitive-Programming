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

Given a Graph with nodes and edges each edge has some 
distinct weight

s(i,0,n) -> stands for summation i from 0 to N


u need to find the s(i,0,N) s(j,i+1,N) d(i,j)

basically all pairs sum of distance of node i and j

and d(i,j) can be any function not only distance 

let's suppose d(i,j) is minimum value in the path from 
i to j

So to solve this problem how to do it

think about every edge contribution to the answer lets 
say if we can find for every edge the no of paths in which
that edge is the minimum then our answer is simply
(edge * no of paths in which that edge is minimum) this 
value added for each edge 

We can do this by traversing edges in decresing order of 
their weight 


*/
void solve()
{
	
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