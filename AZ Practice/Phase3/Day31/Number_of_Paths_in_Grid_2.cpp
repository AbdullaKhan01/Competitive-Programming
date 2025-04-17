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
ll modAdd(ll a,ll b){
    ll p = (a%mod + b%mod)%mod;
    return p;
}
ll modSub(ll a,ll b){
    ll p = (a%mod - b%mod)%mod;
    if(p<0) p+=mod;
    return p;
}
ll modMul(ll a,ll b){
    ll p = (a%mod * b%mod)%mod;
    return p;
}
int n,m,kk;
void solve()
{
	cin >> n >> m >> kk;
	vector<vector<int>> g(n,vector<int>(m,0));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin >> g[i][j];
		}
	}
	// we need a 3D dp 
	// dp[i][j][k]
	// what will dp[i][j][k] denote
	// -> total no of different paths from 1,1 to
	// the cell i,j with k cells unblocked
	// so how will the transition look like

	// upar se aao ya right se

	//basically the idea is to find no of ways to reach
	// cell i , j with exacly k walls changed how to do
	// that obviously agar wo cell 1 hai to i-1,j se k-1
	// cells ko change karke hi is cell ko change karoge
	// similarly for i,j-1,k-1
	int dp[n][m][kk+1];
	memset(dp,0,sizeof(dp));
	if(g[0][0] == 0) dp[0][0][0] = 1;
	if(g[0][0] == 1 && kk >= 1) dp[0][0][1] = 1; 
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			for(int k=0;k<=kk;k++)
			{
				
				int flag = g[i][j];
				if(i - 1 >= 0 && k-flag >= 0)
					dp[i][j][k] = modAdd(dp[i][j][k],dp[i-1][j][k-flag]);
				if(j - 1 >= 0 && k-flag >= 0)
					dp[i][j][k] = modAdd(dp[i][j][k],dp[i][j-1][k-flag]);

			}

		}
	}
	int cnt = 0;
	for(int k=0 ; k<=kk; k++)
	{
		cnt = modAdd(cnt,dp[n-1][m-1][k]);
	}
	cout << cnt << endl;
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