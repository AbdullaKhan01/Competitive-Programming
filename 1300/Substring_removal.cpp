#include<bits/stdc++.h>
// #define mod 1000000007
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
// void x(){
// 	int n;
// 	cin >> n;
// 	cout << (n * (n+1))/2<< endl;
// }
int inv(int a,int p=mod-2){
	int result = 1;
	while(p>0){
		if(p&1)
			result = a*result %mod;
		a = a * a %mod;
		p >>= 1;
	}
	return result;
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
ll modDiv(ll a,ll b){
	ll p = modMul(a,inv(b));
	return p;
}
void solve()
{

	// aaabaaa
	int n;string s;
	cin >> n >> s;
	if(s.front() == s.back()){
		// all elements equal 
		set<char> st;
		for(auto it : s) st.insert(it);
		if(st.size() == 1){
			int ans = modDiv(modMul(n,n+1),2) + 1;
			cout << ans << endl;
		}
		// some elements different
		else{
			int cnt1 = 0;
			int cnt2 = 0;
			int idx = 0;
			while(s[idx++] == s.back()) cnt1++;
			idx = n-1;
			while(s[idx--] == s.back()) cnt2++;
			int ans = modMul(cnt1+1,cnt2+1);
			cout << ans << endl;
		}
	}
	else{
		int cnt = 0;
		char prev = s.front();
		int idx = 0;
		while(s[idx++] == prev){
			cnt++;
		}
		idx = n-1;
		prev = s.back();
		while(s[idx--] == prev){
			cnt++;
		}
		cout << cnt+1 << endl;
	}
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