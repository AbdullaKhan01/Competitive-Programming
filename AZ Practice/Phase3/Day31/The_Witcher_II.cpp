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
	// we will need a 2D dp of pairs
	// what will dp[i][j].first represent ???
	// -> min health needed to reach cell i,j from cell 1,1
	// what will dp[i][j].second represent ???
	// -> after reaching cell i,j what will be the health

	// how will the transitions go
	// dp[i][j].first = min(dp[i-1][j].first + dp[i-1][j].second - g[i][j])
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