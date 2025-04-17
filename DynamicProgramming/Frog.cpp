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
 		vll arr(n+1,0);
 		arr[0] = 1;
 		for(ll i=0;i<n;i++){
 			if(i+1<=n) arr[i+1] += arr[i];
 			if(i+2<=n) arr[i+2] += arr[i];
 		}
 		cout << arr[n];        
    }
    return 0;
}