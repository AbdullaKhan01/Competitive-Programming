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
void solve()
{
	int n,a,b;
	cin >> n >> a >> b;
	vector<int> vec(n);
	for(int i=0;i<n;i++){
		cin >> vec[i];
	}
	multiset<int> ms;
	vector<int> pref(n+1);
	for(int i=1;i<=n;i++){
		pref[i] = pref[i-1] + vec[i-1];
	}
	int ans = -1e18;
	for(int i=1;i<=n;i++){
		// pref[r] = pref[i]
		if(i - a >= 0){
			ms.insert(pref[i - a]);
		}
		if(i - b - 1  >= 0){
			ms.erase(ms.find(pref[i - b - 1]));
		}
		// we want pref[r] - pref[l-1] to be max
		if(ms.empty()) continue;
		int sum = pref[i] - *ms.begin();
		ans = max(ans,sum);
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