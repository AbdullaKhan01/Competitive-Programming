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
// _ _ X _ _ _

// dp ?

/*

Question -> given n k 

find no of strings of length n that can have at
most k consecutive vowels 

return ans % 1e9 + 7
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

void solve(){
    // ith vowel -> 
    // 0 consonant
    // 1 vowel
    int n,k;
    cin >> n >> k;
    vector<vector<int>> dp(n+2,vector<int>(2,0));
    dp[n+1][0] = 1 , dp[n+1][1] = 1;
    dp[n][0] = 21;
    dp[n][1] = 5;
    for(int i=n-1;i>=1;i--){
        // place consonant
        dp[i][0] = modMul(21,modAdd(dp[i+1][0],dp[i+1][1]));
        // place vowel here
        int val = 5;
        for(int j=i+1;j<=min(n+1,i+k);j++){
            dp[i][1] = modAdd(dp[i][1],modMul(val,dp[j][0]));
            val = modMul(val,5);
        }
        // _ _ _ _ _ 
    }
    // cout << n << endl;

    // 2 21 5
    // 1
    cout << dp[n][0] << " " << dp[n][1] << endl;
    cout << dp[1][0] << " " << dp[1][1] << endl;
    int ans = (dp[1][0] + dp[1][1])%mod;
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