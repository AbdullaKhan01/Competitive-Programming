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
	int n,k;
	cin >> n >> k;
	vector<int> a(n);
	map<int,vector<int>> mp;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	sort(all(a));
	for(int i=0;i<n;i++){
		mp[a[i] % k].push_back(a[i]);
	}
	int ans = 0;
	int cnt = 0;
	for(auto it : mp){
		vector<int> temp = it.second;
		if(temp.size()%2 == 0){
			for(int i=1;i<(int)temp.size();i+=2){
				ans += (temp[i] - temp[i-1]);
			}
		}
		else{
			cnt++;
			int sz = temp.size();
			vector<int> pref(sz);
			vector<int> suff(sz);
			for(int i=1;i<sz;i+=2){
				if(i - 2 >= 0) pref[i] += pref[i-2];
				pref[i] += temp[i] - temp[i-1];
			}
			for(int i=sz-2;i>=0;i-=2){
				if(i + 2 < sz) suff[i] += suff[i+2];
				suff[i] += temp[i+1] - temp[i];
			}
			int mini = 1e18;
			for(int i=0;i<sz;i++){
				int gg = 0;
				if(i%2 == 0){
					if(i-1 >= 0) gg += pref[i-1];
					if(i+1 < sz) gg += suff[i+1];
				}
				else{
					if(i-2 >= 0) gg += pref[i-2];
					if(i+2 < sz) gg += suff[i+2];
					if(i-1 >= 0 && i+1 < sz){
						gg += temp[i+1] - temp[i-1];
					} 
				}
				mini = min(mini,gg);
			}
			ans += mini;
		}
	}
	cout << (cnt > 1 ? -1 : ans/k) << endl;

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