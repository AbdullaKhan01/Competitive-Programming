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
    int n,l,r;
    cin >> n >> l >> r;
    l--,r--;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }	
    int ans = 1e9;
    multiset<int> ms;
    for(int i=0;i<=r;i++){
        ms.insert(a[i]);
    }
    int cnt = r - l + 1;
    int g = 0;
    while(cnt--){
        int val = *ms.begin();
        ms.erase(ms.find(val));
        g += val;
    }
    ans = min(ans,g);
    // from 0 to r and l to n
    ms.clear();
    for(int i=l;i<n;i++){
        ms.insert(a[i]);
    }
    cnt = r - l + 1;
    g = 0;
    while(cnt--){
        int val = *ms.begin();
        ms.erase(ms.find(val));
        g += val;
    }
    ans = min(ans,g);
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