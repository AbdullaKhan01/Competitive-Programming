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
string s;
int dp[1001][1001];
int rec(int i,int j) //min cost to make palindrome from i to j
{
	//pruning
	//base case
	if(i > j) return 0;
	//cache check
	if(dp[i][j] != -1) return dp[i][j];
	//compute
	int ans = 0;
	if(s[i] == s[j]) ans = rec(i+1,j-1);
	else ans = 1 + min(rec(i,j-1),rec(i+1,j));
	//save and return
	return dp[i][j] = ans;
}
void solve()
{
	cin >> s;
	int n = s.size();
	memset(dp,-1,sizeof(dp));
	cout << rec(0,n-1) << endl;
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