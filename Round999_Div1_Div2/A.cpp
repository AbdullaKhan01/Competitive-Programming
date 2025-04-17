#include<bits/stdc++.h>
#include <ext/pb_ds/detail/standard_policies.hpp>
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
    int n,capacity;cin >> n >> capacity;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int cnt = 0;
    int c = capacity;
    for(int i=0;i<n;i++){
        c -= a[i];
        cnt+= 1;
        if(i+1<n && c < a[i+1]){
            cnt += 2 * (i+1);
            c = capacity;
        }
    }
    cout << cnt << endl;
    return ;
}
signed main(){
    fast_io();
    int tt = 1;
    // cin >> tt;
    while(tt--)
    {
        solve();
    }
    return 0;
}