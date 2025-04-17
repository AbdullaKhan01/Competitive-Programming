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

int modAdd(int a,int b){
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
void solve()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
	}
	vector<pair<int,int>> dp(n);
	// {} = length of lis,count of lis
	dp[0] = {1,1};
	int maxi = 1;
	for(int i=1;i<n;i++)
	{
		dp[i] = {1,1};
		for(int j=0;j<i;j++)
		{
			if(a[j] < a[i])
			{
				// then only we can do something
				int lval = modAdd(1,dp[j].first);
				if(lval == dp[i].first)
				{
					// dp[i].second++;
					dp[i].second = modAdd(dp[i].second,dp[j].second);
				}
				if(lval > dp[i].first)
				{
					dp[i] = {lval,dp[j].second};
				}
				
			}
		}
		maxi = max(maxi,dp[i].first);
	}
	// for(int i=0;i<n;i++)
	// {
	// 	cout << dp[i].first << " " << dp[i].second << endl;
	// }
	// cout << maxi << endl;
	int cnt = 0;
	for(int i=0;i<n;i++)
	{
		if(dp[i].first == maxi)
		{
			cnt = modAdd(cnt,dp[i].second);
		} 
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