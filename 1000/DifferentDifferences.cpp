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
#define llmin(a,b) min(1LL*(a),1LL*(b))
#define output(x) for(auto a:x) cout << a <<" ";
#define FOR(i,n) for(i=0;i<n;i++)
using namespace std; 

int main(){
    ll tt;
    cin >> tt;
    while(tt--)
    {
     	ll n,k;
     	cin >> k >> n;
     	ll s = 1,j=0;
     	ll x = k;
     	while(x--){
     		cout << s << " ";
     		j++;
     		if(n-s<k-1)
     			break;
     		s = s+j;
     	}
     	for(int i=0;i<k-j;i++){
     		cout << ++s << " ";
     	}
     	cout << endl;
    }
    return 0;
}