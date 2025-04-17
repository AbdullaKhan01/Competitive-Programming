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
int n;
int cost[26][26];
int dp[101][101][26];
int rec(int level,int k,int prev){
	//base case
	if(level == n) return 0;
	//cache check
	if(dp[level][k][prev] != -1) return dp[level][k][prev];
	//compute
	int ans = INT_MIN;
	for(int i=0;i<26;i++){
		if(i == s[level] - 'a') ans = max(ans,cost[prev][i] + rec(level+1,k,i));
		else{
			if(k - 1 >= 0){

				ans = max(ans,cost[prev][i] + rec(level+1,k-1,i));
			}
		}
	}
	//save and return
	return dp[level][k][prev] = ans;
}
void solve()
{
	memset(cost,0,sizeof(cost));
	cin >> s;
	n = (int)s.size();
	int k;cin >> k;
	int m;cin >> m;
	while(m--){
		char a,b;
		int c;
		cin >> a >> b >> c;
		cost[a - 'a'][b - 'a'] = c;
	}
	memset(dp,-1,sizeof(dp));
	int ans = INT_MIN;
	for(int i=0;i<26;i++){
		if(i == s[0] - 'a') ans = max(ans,rec(1,k,i));
		else{
			if(k - 1 >= 0){
				ans = max(ans,rec(1,k-1,i));
			}
		}
	}
	cout << ans << endl;
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