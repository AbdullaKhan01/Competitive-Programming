#include<bits/stdc++.h>
#define mod2 1000000007
#define mod 998244353
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
void solve()
{
	int n;cin >> n;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	int ans = 0;
	// we can calculate the answer bit by bit
	for(int bit = 0; bit < 31; bit++){
		// for ith bit
		int cnt[2] = {1,0};
		int sum[2] = {0,0};
		bool x = 0;
		for(int i=0;i<n;i++){
			if(a[i] & (1 << bit)){
				x = (x+1) % 2;
			}
			int tot = modSub(modMul(cnt[x ^ 1],(i+1)),sum[x ^ 1]);
			ans = modAdd(ans,modMul(tot,(1 << bit)));
			cnt[x]++;
			sum[x] += (i+1);
		}
	}
	cout << ans << endl;
}
signed main(){
	fast_io();
    int tt = 1;
    // cin >> tt;
    while(tt--)
    {
    	solve();
    }
    return 0;
}