#include<bits/stdc++.h>
// #define mod 1000000007
#define mod 998244353
#define ceil(a,b) ((a+b-1)/b)
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

const int N = 1e6+1; 
#define PRIME mod
int fact[N],invfact[N];
int pw(int a,int p=mod-2){
	int result = 1;
	while(p>0){
		if(p&1)
			result = a*result %mod;
		a = a * a %mod;
		p >>= 1;
	}
	return result;
}

void init(){
	int p = PRIME;
	fact[0] = 1;
	int i;
	for(i=1;i<N;i++){
		fact[i] = i * fact[i-1]%p;
	}
	i--;
	invfact[i] = pw(fact[i],p-2);
	for(i--;i>=0;i--){
		invfact[i] = invfact[i+1]*(i+1)%p;
	}

}
int ncr(int n,int r){
	if(r > n || n < 0 || r < 0) return 0;
	return fact[n] * invfact[r] % PRIME * invfact[n-r] % PRIME;
}
signed main(){
	
	init();
    int n;
    cin >> n;
    vi arr(2*n);
    input(arr);
    sort(all(arr));
    int ss=0;
    int tt=0;
    rep(i,0,n){
    	ss += arr[i];
    }
    rep(i,n,2*n){
    	tt += arr[i];
    }
    // cout << ss << " " << tt << endl;
    int q = (tt-ss) % mod;
    // cout << q << endl;
    // cout << ncr(2*n,n) << endl;
    cout << q * ncr(2*n,n) % mod;
    return 0;
}