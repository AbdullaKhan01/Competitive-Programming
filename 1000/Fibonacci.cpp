#include<bits/stdc++.h>
// #define mod 1000000007
#define mod2 998244353
#define ll long long
#define ll long long
#define lli long long int
#define vi vector<int>
#define vll vector<ll>
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define input(x) for(auto &a:x) cin >> a;
#define llmax(a,b) max(1LL*(a),1LL*(b))
#define output(x) for(auto a:x) cout << a <<" ";
#define FOR(i,n) for(i=0;i<n;i++)
using namespace std; 
const int mod = 1e9+7;
pair<ll,ll> fib (long long n) {
    if (n == 0)
        return {0, 1};

    auto p = fib(n >> 1);
    ll c = (p.first)%mod * ((2 * p.second)%mod - p.first);
    ll d = ((p.first * p.first)%mod + (p.second * p.second)%mod)%mod;
    if (n & 1)
        return {d, c + d};
    else
        return {c, d};
}
int main(){
    ll tt;
    cin >> tt;
    cout << (fib(tt).first)%mod;
    return 0;
}