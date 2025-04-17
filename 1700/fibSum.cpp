#include<bits/stdc++.h>
#define mod 1000000007
#define mod2 998244353
#define ceil(a,b) ((a+b-1)/b)
#define ll long long
// #define ll long long ll
#define vi vector<ll>
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define input(x) for(auto &a:x) cin >> a;
#define output(x) for(auto a:x) cout << a <<" ";
#define rep(i,a,n) for(ll i=(a);i<n;i++)
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define ff first
#define ss second
#define si set<ll>
#define pii pair<ll,ll>
#define mii map<ll,ll>
#define msi map<string,ll>
#define yes "YES"
#define no "NO"
#define endl '\n'
using namespace std; 
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
pair<ll, ll> fib (ll n) {
    if (n == 0)
        return {0, 1};

    auto p = fib(n >> 1);
    ll c = modMul(p.first,modSub(modMul(2,p.second),p.first));
    ll d = modAdd(modMul(p.first,p.first),modMul(p.second,p.second));
    if (n & 1)
        return {d, modAdd(c,d)};
    else
        return {c, d};
}
signed main(){
	
    ll n;
    cin >> n;
    cout << fib(n).ff << endl;
    // ll x = 18 , y = 23;
    // cout << modMul(18,23);
    // cout << endl;
    // cout << modAdd(18,23);
    // cout << endl;
    // cout << modSub(18,23);
    
    return 0;
}