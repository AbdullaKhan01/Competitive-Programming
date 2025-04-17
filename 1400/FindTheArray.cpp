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
signed main(){
    fast_io();
    string s;
    cin >> s;

    vector<int> dp(1e5 + 5);
    dp[0] = 1;
    dp[1] = 1;

    for(int i=0;i<s.size();i++){
        if(s[i] == 'm' || s[i] == 'w'){
            cout << 0 << endl;
            return 0;
        }
    }

    for(int i=2;i<=s.size();i++){
        
        if(s.substr(i-2,2) == "uu" || s.substr(i-2,2) == "nn"){
            dp[i] = (dp[i-1] + dp[i-2])%mod;
        }
        else{
            dp[i] = dp[i-1];
        }
    }

    cout << dp[s.size()];

    return 0;
}