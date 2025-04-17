#include<bits/stdc++.h>
#define mod 1000000007
#define mod2 998244353
#define ceil(a,b) ((a+b-1)/b)
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
void solve(){
    int n;
    cin >> n;
    vector<int>x(n), y(n);

    for(auto &i : x) cin >> i;
    for(auto &i: y) cin >> i;
    vector<int> final;
    for(int i = 0; i < n; i++){
        final.pb(y[i] - x[i]);
    }

    sort(rall(final));
    int j = n - 1, cnt = 0;

    for(int i = 0; i < n; i++){
        while(j > i && final[i] + final[j] < 0) j--;
        if(j <= i) break;
        cnt++; j--;
    }
    cout << cnt << endl;
}

signed main() {
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}