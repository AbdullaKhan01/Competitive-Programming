#include<bits/stdc++.h>
#define mod 1000000007
#define mod2 998244353
#define ll long long
#define ll long long
#define lli long long int
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int,int>
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define input(x) for(auto &a:x) cin >> a;
#define llmax(a,b) max(1LL*(a),1LL*(b))
#define output(x) for(auto a:x) cout << a <<" ";
#define FOR(i,n) for(i=0;i<n;i++)
using namespace std; 

int main(){
    
    ll n;
    cin >> n;
    vector<pii> arr;
    vector<int> arr2(1001,0);
    while(n--){
        ll a,b;
        cin >> a >> b;
        arr.pb({a,b});
        // arr2[a]++;
    }
    ll ans = 0;
    for(auto it:arr){
        ll ff = it.first;
        ll ss = it.second;
        if(arr2[ff] == -1){ arr2[ss] = -1;continue;}
        if(ff == ss){
            if(arr2[ff]>1){
                arr2[ff] = -1;
            }
            else{
                arr2[ff] = 1;
            }
        }
        else{
            arr2[ss] = -1;
            arr2[ff]++;
        }
    }
    // for(auto it:arr2) ans+=it;
    for(auto it:arr2){
        ans += max(it,0);
        // cout << it << endl;
    }
    cout << ans << endl;
    return 0;
}