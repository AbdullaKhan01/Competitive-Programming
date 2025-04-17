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
bool isSquare(ll n){
	ll x = sqrt(n);
	// cout << x << " " << n << endl;
	return (x*x)==n;
}
int main(){
    ll tt;
    cin >> tt;
    while(tt--)
    {
        ll x,y;
        cin >> x >> y;
        if(x==0 && y==0){
        	cout << 0 << endl;
        	continue;	
        }
        ll m = x*x + y*y ;
        // cout << m << endl;
        cout << (isSquare(m)?1:2) << endl;
    }
    return 0;
}