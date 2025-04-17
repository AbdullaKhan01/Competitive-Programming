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
void solve()
{
	int n,m;
	cin >> n >> m;
	vector<vector<int>>g(n,vector<int>(m,0));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin >> g[i][j];
		}
	}
	// we will need a 2D dp 
	// what will dp[i][j] -> represent
	// it will represent the largest square side length
	// which is having the bottom right cell at the cell(i,j)

	// how will the transitions then be 
	// if we want to expand the cell (i,j) to a square then
	// we necessarily have to take the cells 
	// (i-1,j) , (i,j-1) , (i-1,j-1)
	// so the answer will depends on the answer of all of these
	// dp[i][j] = 1 + min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1]);
	// these all things will happen only when the cell (i,j) is 1
	// otherwise the answer will be just 0

	int maxi = 0;
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<m;j++)
		{
			if(g[i][j] == 0) continue;
			g[i][j] = 1 + min({g[i-1][j],g[i][j-1],g[i-1][j-1]});
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			maxi = max(maxi,g[i][j]);
		}
	}
	cout << maxi * maxi << endl;
 
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