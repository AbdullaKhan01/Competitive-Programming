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

/*

4 3 -> the difference is 1
4 6 -> 8 6 -> 8 12 16 12


// a . b . c . d . e

// a < b < c < d < e

// 2a > e
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
long long binpow(long long a, long long b, long long m=1e9+7) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
void solve()
{
    int n,k;
    cin >> n >> k;
    multiset<int> ms;
    vi a(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        ms.insert(a[i]);
    }
    while(k)
    {
        int st = *ms.begin();
        if(2 * st >= *prev(ms.end())) break;
        int n_ele = 2*st;
        ms.erase(ms.find(st));
        ms.insert(n_ele);
        k--;
    }
    // we have come here
    vector<int> p;
    for(auto it:ms) p.push_back(it);
    vector<int> contri(n,0);
    if(k != 0)
    {

        int d = k/ms.size();
        for(int i=0;i<n;i++) contri[i] = d;

        int g = k % n;

        for(int i=0;i<g;i++)
        {
            contri[i]++;
        }
        // 3 5 6 7 27
        // all elements will be multiplied k/ms.size() times

        // some elements w    
    }
    
    int ans = 0;
    // output(p);
    // cout << endl;
    // output(contri);
    // cout << endl;
    for(int i=0;i<n;i++)
    {
        ans = modAdd(ans,p[i] * binpow(2,contri[i]));
    }
    cout << ans << endl;
}
signed main(){
    fast_io();
    ll tt;
    cin >> tt;
    while(tt--)
    {
        solve();
    }
    return 0;
}