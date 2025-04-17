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
const int N = 2e5+5; 
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
		fact[i] = modMul(i,fact[i-1]);
	}
	i--;
	invfact[i] = pw(fact[i],p-2);
	for(i--;i>=0;i--){
		invfact[i] = modMul(invfact[i+1],(i+1));
	}

}
int ncr(int n,int r){
	if(r > n || n < 0 || r < 0) return 0;
	return modMul(modMul(fact[n],invfact[r]),invfact[n-r]);
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


void solve()
{
	int n,k;
        cin >> n >> k;
        vi arr(n);
        for(int i=0;i<n;i++) cin >> arr[i];
        int z = 0 , o = 0;
    	int ans = 0;
    	int a = ceil(k,2);
    	int rem_places = k - a;
    	for(int i=0;i<n;i++)
    	{
    		if(arr[i] == 0){
    			z++;
    			continue;
    		}
    		else o++;
    		

    		// we need exactly a 1's and rest all can be 1's or 0's

    		if(o >= a)
    		{

    			// choose a 1's from o 1's
    			cout << i << endl;
    			int total = z + o;
    			int g = ncr(o,a);
    			int rest = max(0LL,total - a);

    			int alpha = max(rest,rem_places);
    			int beta = min(rest,rem_places);

    			// int m = binpow(2,rest);
    			int m = ncr(alpha,beta);
    			// cout << invfact[z] << " " << invfact[o-a] << endl;
    			int a1 = modMul(g,m);

    			int alo = modMul(binpow(2,z),invfact[z]);
    			int vlo = modMul(binpow(2,o-a),invfact[o-a]);

    			cout << alo << " " << vlo << endl;
    			int k = modMul(modMul(a1,alo),vlo);
    			// cout << "here" << a1 << " " << modMul(a1,invfact[z]) << endl;
    			// int k = ((a1 * invfact[z])%mod*invfact[o-a])%mod;
    			cout << total << " " << g << " " << rest << " " << m << " " << k << endl;
    			ans = modAdd(ans,k);
    		}
    	}
    	cout << ans%mod << endl;
}
signed main(){
	fast_io();
	init();
    ll tt;
    cin >> tt;
    while(tt--)
    {
		solve(); 
		// cout << modMul(6,invfact[2]) << endl;       
    }
    return 0;
}