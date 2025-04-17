#include<bits/stdc++.h>
#define mod 1000000007
#define mod2 998244353
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
    string ans = "";
    for(int i=2;i<=sqrt(tt);i++){
        while(tt%i == 0){
            tt/=i;
            ans+=to_string(i);
            ans.push_back('*');
        }
    }
    if(tt != 1) ans+=to_string(tt);
    else ans.pop_back();
    // cout << tt << endl;
    cout << ans << endl;
    return 0;
}