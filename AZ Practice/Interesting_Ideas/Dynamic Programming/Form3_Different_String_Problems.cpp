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
string a,b;
int n,m;
// vector<vector<int>>dp;
int dp[5050][5050];
int back[5050][5050];
int rec(int l1,int l2)
{
	// pruning
	
	// base 
	if(l1 == n && l2 == m) return 0;
	// cache
	if(dp[l1][l2] != -1) return dp[l1][l2];
	// compute
	int ans = 1e9;
	if(l1 < n && rec(l1+1,l2) + 1 < ans) // -x[l1]
	{
		ans = rec(l1+1,l2) + 1;
		back[l1][l2] = 0;
	}
	if(l2 < m && rec(l1,l2+1) + 1 < ans) // +y[l2]
	{
		ans = rec(l1,l2+1) + 1;
		back[l1][l2] = 1;
	}
	if(l1 < n && l2 < m && a[l1] == b[l2] && rec(l1+1,l2+1) + 1 < ans)
	{//x[l1]
		ans = rec(l1+1,l2+1) + 1;
		back[l1][l2] = 2;
	}
	// save and return
	return dp[l1][l2] = ans;
}
void generate(int l1,int l2)
{
	if(l1 == n && l2 == m) return ;
	if(back[l1][l2] == 0)
	{
		cout << "-"<<a[l1] << " ";
		generate(l1+1,l2);
	}
	else if(back[l1][l2] == 1)
	{
		cout << "+"<<b[l2] << " ";
		generate(l1,l2+1);
	}
	else if(back[l1][l2] == 2)
	{
		cout <<a[l1] << " ";
		generate(l1+1,l2+1);
	}
}
void solve()
{
	cin >> a >> b;
	n = a.size() , m = b.size();
	// dp.resize(n+1);
	// for(int i=0;i<=n;i++) dp[i].assign(m+1,-1);
	memset(dp,-1,sizeof(dp));
	cout << rec(0,0) << endl;
	generate(0,0);
	cout << endl;
}
signed main(){
	fast_io();
    int tt = 1;
    // cin >> tt;
    while(tt--)
    {
    	solve();
    }
    return 0;
}