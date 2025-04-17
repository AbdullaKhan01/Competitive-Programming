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
    while(tt--){
        ll a,b;
        cin >> a >> b;
        if(a%2==0 && a*2 <=b) cout << a*2;
        else if(b%2 == 0 && b*2 <=a) cout << b*2;
        else cout << a*b << endl;

    }
    return 0;
}