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
int binpow(int a, int b, int m=1e9+7) {
    a %= m;
    int res = 1;
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
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	vector<int> ans(4,0);
	for(int i=0;i<31;i++)
	{
		vector<int> cnt(2,0);
		int bit = 1<<i;
		for(int j=0;j<n;j++)
		{
			cnt[(a[j] >> i) & 1]++;
		}
		int z = cnt[0];
		int o = cnt[1];
		// xor of all pairs
		ans[0] = modAdd(ans[0],modMul(bit,modMul(z,o)));
		// xor of all subsets
		int zerof = binpow(2,z) - 1;
		int onef = binpow(2,o-1);
		int contri = modAdd(onef,modMul(onef,zerof));
		if(o == 0) contri = 0;
		ans[1] = modAdd(ans[1],modMul(bit,contri));
		// and of all pairs
		int x,y;
		if(o % 2 == 0) x = o/2 , y = o-1;
		else x = o , y = (o-1)/2;
		ans[2] = modAdd(ans[2],modMul(bit,modMul(x,y)));
		// and of all subsets
		ans[3] = modAdd(ans[3],modMul(bit,binpow(2,o)-1));
	}
	for(int i=0;i<4;i++)
	{
		cout << ans[i] << " \n"[i+1==4];
	}
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