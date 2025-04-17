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
int n;
vector<int> a;
int rec(int i,int j)
{
	//base case
	if(i+1 == j)
	{
		return 0;
	}
	//cache check
	//compute
	int ans = 1e9;
	for(int k=i+1;k<=j-1;k++)
	{
		ans = min(ans,a[i]*a[j]*a[k] + rec(i,k) + rec(k,j));
	}
	//save and return
	return ans;
}
int dp[101][101];
int rec2(int i,int j)
{
	//base case
	if(i+1 == j)
	{
		return 0;
	}
	//cache check
	if(dp[i][j] != -1)
	{
		return dp[i][j];
	}
	//compute
	int ans = 1e18;
	for(int k=i+1;k<=j-1;k++)
	{
		ans = min(ans,a[i]*a[j]*a[k] + rec2(i,k) + rec2(k,j));
	}
	//save and return
	return dp[i][j] = ans;
}

// IDEA used -> base i,j will always be adjacent to 
// each other so just take i and j as two sides of a 
// triangle and iterate on finding the third side and
// then just solve the subproblems 
void solve()
{
	cin >> n;
	a.resize(n+1);
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	// cout << rec(1,n) << endl;

	memset(dp,-1,sizeof(dp));
	cout << rec2(1,n) << endl;

	// Form 4 Dp let's write it iteratively
	// int dp[n+1][n+1];
	// memset(dp,0,sizeof(dp));
	// for(int i=n-1;i>=0;i--)
	// {

	// }

	// cout << dp[1][n] << endl;
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