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
int n;
string s;
int dp[1001][501];
int rec(int level,int score)
{
	//pruning
	if(score < 0 || score > n/2) return 0;
	//base case
	if(level == n)
	{
		return (score == 0);
	}
	// what does rec return no of ways to make valid
	// parenthesis from [level to n) if current score is 
	// score
	//cache check
	if(dp[level][score] != -1) return dp[level][score];
	//compute
	int ans = 0;
	if(s[level] == '(') ans = rec(level+1,score+1);
	else if(s[level] == ')') ans = rec(level+1,score-1);
	else
	{
		// it's a ?
		int a = rec(level+1,score+1); // add (
		int b = rec(level+1,score-1); // add )

		ans = modAdd(a,b);
	}
	//save and return
	return dp[level][score] = ans;
}
void solve()
{
	cin >> s;
	n = s.size();
	// memset(dp,-1,sizeof(dp));
	// int dp[n+1][n+1];
	// memset(dp,0,sizeof(dp));
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n/2;j++)
		{
			dp[i][j] = -1;
		}
	}
	cout << rec(0,0) << endl;
	// dp[n][0] = 1;
	// for(int i=n-1;i>=0;i--)
	// {
	// 	for(int score=i;score>=0;score--)
	// 	{
	// 		if(s[i] == '(') dp[i][score] = dp[i+1][score+1];
	// 		else if(s[i] == ')' && score-1 >= 0) dp[i][score] = dp[i+1][score-1];
	// 		else
	// 		{
	// 			dp[i][score] = dp[i+1][score+1];
	// 			if(score-1 >= 0)
	// 				dp[i][score] = modAdd(dp[i][score],dp[i+1][score-1]);
	// 		}
	// 	} 
	// }
	// cout << dp[0][0] << endl;
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