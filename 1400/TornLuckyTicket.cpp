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
bool solve(int n,int mid,int k)
{
    ll sum = binpow(2,mid) - 1;
    // cout << mid << " " << sum << " " << k << endl;
    if(sum <= k && n-mid >= k - sum)
    {
        return true;
    }
    return false;
}
signed main(){
    fast_io();
    ll tt;
    cin >> tt;
    while(tt--)
    {
        int n,k;
        cin >> n >> k;
        int s = 0 , e = 31;
        int ans = 0;
        int sum = 0;
        while(s <= e)
        {
            ll m = (s+e)/2;
            if(solve(n,m,k))
            {
                ans = m;
                sum = binpow(2,ans) - 1;
                s = m + 1;
            }
            else
            {
                e = m - 1;
            }
        }
        // cout << ans << " " << sum << endl;
        k-=sum;
        int num = 1;
        vector<int> g;
        while(ans--)
        {
            n--;
            g.pb(num);
            num*=2;
        }
        while(n > 1)
        {
            g.pb(1);
            n--;
            k--;
        }
        g.pb(k);
        output(g);
        cout << endl;
    }
    return 0;
}