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
int n;
vector<int> a;
vector<pair<int,int>> back;
int rec(int level,int mini,int maxi){
	if(level == n){
		return max(maxi,abs(mini));
	}
	//compute
		int val1 = mini + a[level];
		int val2 = maxi + a[level];
		int val3 = abs(mini + a[level]);
		int val4 = abs(maxi + a[level]);
		int nmaxi = max({val1,val2,val3,val4});
		int nmini = min({val1,val2,val3,val4});
		back[level].first =  nmini;
		back[level].second = nmaxi;
	// return
	return rec(level+1,nmini,nmaxi);
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
void solve()
{
	cin >> n;
	a.assign(n,0);
	back.assign(n,{0,0});
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	rec(0,0,0);
	// for(int i=0;i<n;i++){
	// 	cout << back[i].first << " " << back[i].second << endl;
	// }
	vector<map<int,int>> score(n);
	score[0][0 + a[0]]++;
	score[0][abs(0 + a[0])]++;
	auto change = [&](int val,int idx){
		int a1 = val + a[idx];
		int a2 = abs(val + a[idx]);
		score[idx][a1]=modAdd(score[idx][a1],score[idx-1][val]);
		score[idx][a2]=modAdd(score[idx][a2],score[idx-1][val]);
	};
	for(int i=1;i<n;i++){
		int v1 = back[i-1].first;
		int v2 = back[i-1].second;
		change(v1,i);
		if(v1 != v2)
		change(v2,i);
	}
	cout << score[n-1][max(back[n-1].first,back[n-1].second)] << endl;
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