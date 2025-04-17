#include<bits/stdc++.h>
#define mod 1000000007
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
int inv(int a,int p=mod-2){
	int result = 1;
	while(p>0){
		if(p&1)
			result = modMul(a,result);
		a = modMul(a,a);
		p >>= 1;
	}
	return result;
}

void solve()
{
	int n,m;
	cin >> n >> m;
	map<int,int> mp;
	for(int i=0;i<n;i++){
		int x;
		cin >> x;
		mp[x]++;
	}
	vector<int> a;
	for(auto it : mp){
		a.push_back(it.first);
	}
	int ans = 0;
	int cnt = 1;
	set<pair<int,int>> st;
	for(int i=0;i<(int)a.size();i++){
		if(st.empty()){
			st.insert({a[i],mp[a[i]]});
			cnt = modMul(cnt,mp[a[i]]);
		}
		else{
			while((st.size() >= m )|| (!st.empty() && st.rbegin()->first < (a[i]-1))){
				auto it = st.begin();
				cnt = modMul(cnt,inv(it->second));
				st.erase(it);
			}
			cnt = modMul(cnt,mp[a[i]]);
			st.insert({a[i],mp[a[i]]});
		}
		if(st.size() == m){
			ans = modAdd(ans,cnt);
		}
	}
	cout << ans << endl;
}
signed main(){
	fast_io();
    int tt = 1;
    cin >> tt;
    while(tt--)
    {
    	solve();
    }
    return 0;
}