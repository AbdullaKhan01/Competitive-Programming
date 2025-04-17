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
int n,m;
string a,b;
int dp[1001][1001];

//finding the LCS
int rec(int i,int j)
{
	// return LCS of a[i.....n-1] and b[j........m-1]
	// pruning
	// base case
	if(i>=n || j>=m) return 0;
	// cache check
	if(dp[i][j] != -1) return dp[i][j];
	// compute
	int ans = 0;
	if(a[i] == b[j]) return dp[i][j] = 1+rec(i+1,j+1);
	ans = max(ans,rec(i+1,j));
	ans = max(ans,rec(i,j+1));
	
	// save and return
	return dp[i][j] = ans;
}
void solve()
{
	// cin >> n >> m;
	cin >> a >> b;
	n = a.size() , m = b.size();
	memset(dp,-1,sizeof(dp));	
	cout << rec(0,0) << endl;
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