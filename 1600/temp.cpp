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
int inverse(int a,int p=mod-2){
	int result = 1;
	while(p>0){
		if(p&1)
			result = a*result % mod;
		a = a * a %mod;
		p >>= 1;
	}
	return result;
}
long long binpow(long long a, long long b, long long m=1e9+7) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
ll modAdd(ll a,ll b){
    ll p = (a%mod + b%mod)%mod;
    return p;
}
ll modSub(ll a,ll b){
    ll p = (a%mod - b%mod)%mod;
    if(p<0) p+=mod;
    return p;
}
ll modMul(ll a,ll b){
    ll p = (a%mod * b%mod)%mod;
    return p;
}
int solve(int a,int r,int n)
{
	// sum of gp = a * (r^n - 1) * (r-1)^-1

	int x = a;
	int y = binpow(r,n);
	int z = inverse(r-1);
	int ans = modMul(modMul(x,modSub(y,1)),z);
	return ans;
}
signed main(){
	fast_io();
	// 80 - 26 = 54
	// _ _ 
	// 2 + (2 * 3) + (2 * 3 * 3) + (2 * 3 * 3 * 3)


	// 1 + (1 * 2) + (1 * 2 * 2) + 
	// 1 + 2*1 + 2*1*2

	// == a(r^n-1)/(r-1)

	// a = 1 r = 2 n = 3


	//sum of gp with common difference d and 
	//and 

	// so how to quickly calculate this expression

	// so i finally got the idea
	// given some x = a

	// find 1 + 1*2 + 1*2*2

	// 10 ^ 4 - 10 ^ 6

	// a = 1 - 10 ^ 6
	// b = 1 - 10 ^ 4

	// answer = a - b
	ll tt;
	cin >> tt;
	while(tt--)
	{
	    int l,r,k;
	    cin >> l >> r >> k;
	    k = 9/k;
	    {
	    	int a = solve(k,k+1,l);
	    	int b = solve(k,k+1,r);
	    	int ans = modSub(b,a);
	    	cout << ans << endl;
	    }
	}
	// a3 + b3 == x
	// a3 == x - b3
	// a3 == cbrt(x-b3)
    return 0;
}