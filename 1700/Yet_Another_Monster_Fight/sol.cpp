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
    const int inf = 1e18;
    int n;cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }	
    vector<int> pref(n,-inf);
    vector<int> suff(n,-inf);
    for(int i=1;i<n;i++){
        pref[i] = max(a[i-1],1 + pref[i-1]);
    }
    for(int i=n-2;i>=0;i--){
        suff[i] = max(a[i+1],1 + suff[i+1]);
    }
    int ans = inf;
    for(int i=0;i<n;i++){
        int left = i+1;
        int right = n - i;
        int v1 = max(a[i],suff[i] + 1);
        int cnt1 = max(0LL,pref[i] - v1 + right);
        int v2 = max(a[i],pref[i] + 1);
        int cnt2 = max(0LL,suff[i] - v2 + left);
        int k = max({a[i],v1 + cnt1,v2 + cnt2});
        ans = min(ans,k);
    }
    
    cout << ans << endl;
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