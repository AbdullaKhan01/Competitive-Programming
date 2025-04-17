#include<bits/stdc++.h>
#define mod 1000000007
#define mod2 998244353
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
signed main(){
	
    int n,l,r;
    cin >> n >> l >> r;
    vector<vector<int>>dp(n+1,vector<int>(3,0));
    int z = 0,o=0,t=0;
    if(r-l<=10){
    	for(int i=l;i<=r;i++){
    		z+=(i%3==0);
    		o+=(i%3==1);
    		t+=(i%3==2);
    	}
    }
    else{
    	int p = 3 * ceil(l,3);
    	int rr = 3 * (r / 3);
    	// cout << p << " " << rr << endl;
    	for(int i=l;i<p;i++){
    		o+=(i%3==1);
    		t+=(i%3==2);
    	}
    	for(int i=r;i>rr;i--){
    		o+=(i%3==1);
    		t+=(i%3==2);
    	}
    	z+=(rr-p)/3 +1;
    	o+=(rr-p)/3;
    	t+=(rr-p)/3;
    	// cout << z << o << t << endl;
    }
    dp[1][0] = z;
    dp[1][1] = o;
    dp[1][2] = t;

    for(int i=2;i<=n;i++){
    	dp[i][0] = modAdd(modAdd(modMul(dp[i-1][0],z),modMul(dp[i-1][1],t)),modMul(dp[i-1][2],o));
    	dp[i][1] = modAdd(modAdd(modMul(dp[i-1][0],o),modMul(dp[i-1][1],z)),modMul(dp[i-1][2],t));
    	dp[i][2] = modAdd(modAdd(modMul(dp[i-1][0],t),modMul(dp[i-1][1],o)),modMul(dp[i-1][2],z));
    }	
    cout << dp[n][0] << '\n';
    return 0;
}
// 9  0
// 10 1
// 11 2
// 12 0
// 13 1
// 14 2
// 15 0
// 16 1
// 17 2
// 18 0
// 19 1
// 20 2
// 21 0
// 22 1
// 23 2
// 24 0
// 25 1
// 26 2
// 27 0
// 28 1
// 29 2