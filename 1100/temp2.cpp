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

int maximumSumSubArray(vi& arr,int n){
	int best = 0, sum = 0;
 	for(int k = 0; k < n; k++) {
		sum = max(arr[k],sum+arr[k]);
		best = max(best,sum); 
	}
	return best;	
}
ll modAdd(ll a,ll b){
    ll p = (a%mod + b%mod)%mod;
    if(p < 0) p+=mod;
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
int inv(int a,int m = mod) {
  return a <= 1 ? a : m - (m/a) * inv(m % a) % m;
}
int gpSum(int a,int r,int n)
{
	int ans = modMul(a,modSub(binpow(r,n),1));
	ans = modMul(ans,inv(n-1));
	return ans;
}
void solve()
{
	int n,k;
	cin >> n >> k;
	vi arr(n);
	int ans = 0;
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
		ans = modAdd(ans,arr[i]);
	}
	int s = maximumSumSubArray(arr,n);

	int g = gpSum(1,2,k);

	ans = modAdd(ans,modMul(g,s));
	// a s s 2s 4s 8s 
	// s + 2s + 4s + 8s + 16s 
	// a + s + s(1 + 2 + 4 + 8 + 16)
	// sum of a gp
	// a * r^n - 1

	// 12 12 24 48
	cout << ans << endl;
}
signed main(){
	fast_io();
    ll tt;
    cin >> tt;
    while(tt--)
    {
        solve();
    }
    return 0;
}