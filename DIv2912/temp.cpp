#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
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
using namespace __gnu_pbds; 
#define indexed_set tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update> 

/* 
for fast input output use printf and scanf;
*/
signed main(){
    fast_io();
    ll tt;
    cin >> tt;
    while(tt--)
    {
        int n;
        cin >> n;
        vector<int> A(n),B(n);
        for(int i=0;i<n;i++)
        {
            cin >> A[i];
        }
        for(int i=0;i<n;i++)
        {
            cin >> B[i];
        }
        // Ai + Aj > Bi + Bj
        // Ai - Bi > Bj - Aj
        int cnt = 0;
        int l = 1;
        indexed_set ms;
        for(int i=n-1;i>=0;i--)
        {
            int x = A[i] - B[i];
            auto it = ms.lower_bound({x,0});
            if(it != ms.end())
                cnt += ms.order_of_key(*it);
            else cnt += ms.size();
            ms.insert({B[i]-A[i],l++});
        }
        cout << cnt << endl;
    }
    return 0;
}