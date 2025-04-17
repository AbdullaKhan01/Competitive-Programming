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
	int n;
	string s;cin >> s;
	n = s.length();
	int pref[n+1];
	int last[26];
	int dp[n+1];
	memset(last,-1,sizeof(last));
	// cout << "here" << endl;
	dp[0]=1;
	pref[0] = 1;
	for(int i=1;i<=n;i++)
	{
		dp[i] = pref[i-1];
		if(last[s[i-1]-'a'] != -1)
		{
			int idx = last[s[i-1]-'a'];
			dp[i] -= pref[idx];
		}
		pref[i] = pref[i-1] + dp[i];
		last[s[i-1]-'a'] = i-1;
	}
	cout << pref[n]-1 << endl;
}
signed main(){
	fast_io();
    int tt = 1;
    cin >> tt;
    // cout << ""
    while(tt--)
    {
    	solve();
    }
    return 0;
}