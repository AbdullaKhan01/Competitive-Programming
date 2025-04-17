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
vector<vector<int>> g(101);
vector<int> a(101);
int dp[101][101][101];
int n;
int sq(int x){
	return x*x;
}
int rec(int l,int r,int x){
	//pruning 
	if(l > r) return 0;
	//base case
	//cache check
	if(dp[l][r][x] != -1) return dp[l][r][x];
	//compute
		// delete 
		int op1 = 0 , op2 = 0;
		op1 = rec(l+1,r,0) + sq(x+1);
		int idx = upper_bound(g[a[l]].begin(),g[a[l]].end(),l) - g[a[l]].begin();
		int index = INT_MAX;
		if(idx < g[a[l]].size()) index = g[a[l]][idx];
		if(index <= r){
			op2 = rec(l+1,index-1,0) + rec(index,r,x+1);
		}
		// take next occurence
	//save and return
	return dp[l][r][x] = max(op1,op2);
}
void solve()
{
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a[i];
		g[a[i]].push_back(i);
	}
	memset(dp,-1,sizeof(dp));
	cout << rec(0,n-1,0);
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