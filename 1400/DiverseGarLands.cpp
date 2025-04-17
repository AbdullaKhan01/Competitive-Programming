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
int maximumSumSubArray(vi& arr,int n){
    int best = 0, sum = 0;
     for(int k = 0; k < n-1; k++) {
        sum = max(arr[k],sum+arr[k]);
        best = max(best,sum); 
    }
    return best;    
}
signed main(){
    fast_io();
    ll tt;
    cin >> tt;
    while(tt--)
    {
        int n;
        cin >> n;
        int k;
        cin >> k;
        vi arr(n);
        int sum = 0;
        rep(i,0,n){
            cin >> arr[i];
            sum+=arr[i];
        }
        int ans = sum + maximumSumSubArray(arr,arr.size());
        cout << ans << " ";
        int g = INT_MIN;
        for(int i=0;i<k;i++){
            g = max(g,ans%mod);
            ans = (2*ans)%mod;
        }
        cout << g%mod << endl;
    }
    return 0;
}