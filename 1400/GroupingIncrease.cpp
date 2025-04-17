#include<bits/stdc++.h>
#define mod 1000000007
#define mod2 998244353
#define ceil(a,b) ((a+b-1)/b)
#define ll long long
#define ll long long
#define lli long long int
#define vi vector<int>
#define vll vector<ll>
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define input(x) for(auto &a:x) cin >> a;
#define llmax(a,b) max(1LL*(a),1LL*(b))
#define output(x) for(auto a:x) cout << a <<" ";
#define FOR(i,n) for(i=0;i<n;i++)
using namespace std; 

int main(){
    ll tt;
    cin >> tt;
    while(tt--)
    {
        ll n;
        cin >> n;
        vll arr(n);
        input(arr);
        ll prev1=INT_MAX,prev2 = INT_MAX;
        ll ans = 0;
        for(int i=0;i<n;i++){
            ll temp = arr[i];
            if(prev1>prev2){
                swap(prev1,prev2);
            }
            if(temp<=prev1){
                prev1 = temp;
            }
            else if(temp>prev1 && temp<=prev2){
                prev2 = temp;
            }
            else if(temp > prev2){
                prev1 = temp;
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}