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
        ll a,b,c,m;
        cin >> a >> b >> c >> m;
        bool flag = false;
        ll ap = a-1;
        ll bp = b-1;
        ll cp = c-1;
        if(m >= ap+bp+cp){
        	cout << (m==(ap+bp+cp)?"YES":"NO") << endl;
        }
        else if(m<=ap){
        	ll rem
        }
    }
    return 0;
}