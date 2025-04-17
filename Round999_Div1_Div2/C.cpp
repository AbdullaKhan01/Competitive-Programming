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
    int n;cin >> n;
    vector<vector<int>> tree(n+1,vector<int>());
    multiset<pair<int,int>,greater<pair<int,int>>> ms;
    for(int i=0;i<n-1;i++){
        int u,v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        ms.insert({tree[i].size(),i});
    }
    int cnt = 0;
    for(auto it : ms){
        cout << it.first << " " << it.second << endl;
    }

    cout << "done" << endl;
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