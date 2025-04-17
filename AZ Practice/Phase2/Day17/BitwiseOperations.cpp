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
    cin >> n;
    vector<int> a(n);
    vector<int> cnt(21,0);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        for(int j=0;j<21;j++)
        {
        	if(a[i] & (1<<j)) cnt[j]++;
            // cnt[(a[i]>>j)&1]++;
        }
    }
    // a+b = a|b + a&b
    // so sum of array will always
    // remain constant

    int ans = 0;
    for(int i=0;i<n;i++)
    {
        int num = 0;
        for(int j=0;j<21;j++)
        {
            if(cnt[j]) num |= (1<<j),cnt[j]--;
        } 
        ans += num * num;
    }
    cout << ans << endl;
}
signed main(){
    fast_io();
    int tt;
    cin >> tt;
    while(tt--)
    {
        solve();
    }
    return 0;
}