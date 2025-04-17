#include<bits/stdc++.h>
#define mod 1000000007
#define mod2 998244353
#define ceil(a,b) ((a+b-1)/b)
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
long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
long long lcm (long long a, long long b) {
    return a / __gcd(a, b) * b;
}
/*
WRONG ANSWER 
for 4 -> Expected(132) -> My(108);
*/
int main(){
    ll n,k;
    cin >> n >> k;
    cout << lcm(n,k) << endl;
    // ll ans = (n-1) * 4 * 3 * binpow(4,n-3);
    // cout << ans << endl;
    return 0;
}