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
// bool solve(ll mid,ll a,ll b){
// 	// cout << mid << " " << a << " " << b << endl;
// 	ll x = b--;
// 	while(--mid && b>=2 && a <= x){
// 		x+=(--b);
// 	}
// 	// cout << mid << " ";
// 	// if(mid > 0) return false;
// 	// cout << x << endl;
// 	// return false;
// 	if(x == a) return true;
// 	if(a > x) return false;
// 	if(a < x){
// 		ll z = x - a;
// 		ll m = b - 1;
// 		return z>=m;
// 	}
// 	// cout << b << " " << x << " " << a << endl; 
// 	// return (b-1)>=x-a;
// }
ll apsum(ll first,ll last,ll diff){
	ll no_ele = (last - first + 1 )/diff;
	ll sum = ((no_ele) * (first+last))/2;
	return sum;
}
int solve(ll mid,ll a,ll b){
	ll n = mid - 1 ;
	// cout << mid << endl;
	ll min = ((n*n+1)/2) + (mid+1);
	ll max = apsum(b-mid,b-2,1) + b;
	// cout << min << " " << max << endl;
	if(a<min) return -1;
	else if(a>max) return 1;
	return 0;
	// return min<=a && a<=max;

}
int main(){
    ll a,b;
    cin >> a >> b;
    if(a == 1){
    	cout << 0 << endl;
    	return 0;
    }
    ll s = 1,e=b;
    ll mid = (s+e)/2;
    ll ans = -1;
    while(s<=e){
    	ll solved = solve(mid,a,b);
    	if(solved == 0){
    		// cout << "YES" << endl;
    		ans =  mid;
    		e = mid-1;
    	}
    	else if(solved == 1){
    		// cout << "NO" << endl;
    		s = mid+1;
    	}
    	else{
    		e = mid - 1;
    	}
    	mid = (s+e)/2;
    }
    cout << ans << '\n';
    return 0;
}