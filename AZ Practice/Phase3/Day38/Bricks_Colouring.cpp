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
int n,m,k;
int dp[2001][2001];
int rec(int level,int k) // no of ways to colour [level,n] with k different
{
	//pruning
	//base case
	if(level == n-1)
	{
		if(k == 0) return m; // no of ways to color last brick
		else return 0;
	}
	//cache check
	if(dp[level][k] != -1) return dp[level][k];
	int ans = 0;
	//compute
		//either i and i+1th wall same color
		int a = rec(level+1,k);
		//or i and i+1th wall different color
		int b = modMul((m-1),rec(level+1,k-1));
		ans = modAdd(a,b);
	//save and return
	return dp[level][k] = ans;
}
void solve()
{
	cin >> n >> m >> k;
	
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			dp[i][j] = -1;
		}
	}
	// cout << n << m << k << endl;
	cout << rec(0,k) << endl;
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