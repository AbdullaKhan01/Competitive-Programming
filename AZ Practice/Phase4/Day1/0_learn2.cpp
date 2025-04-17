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

Catalan Numbers -> 1,1,2,5,14,42

Cn = (1/(n+1)) * 2nCn 

Cn+1 = summation i from 0 to n Ci * Cn-i C0 = 1 for n>=0 

 
# of path from 0,0 to (N,N) not going above the 
diagonal of a N*N grid is -> Cn

# of 2n length Balanced Paranthesis is -> Cn

# of Binary Trees with n nodes is -> Cn

# of Full Binary Tree with n+1 leaves -> Cn

# of Triangulation ways for a Convex Polygon of n+2 sides 
-> Cn

# of ways to connect 2n points on circle , so that no two
intersect 

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