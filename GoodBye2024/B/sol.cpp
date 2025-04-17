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
	int n;cin >> n;
	vector<int> pref(2*n + 2,0);
	vector<pair<int,int>> a;
	vector<int> cnt(2*n + 2,0);
	for(int i=0;i<n;i++){
		int l,r;cin >> l >> r;
		if(l == r) pref[l]=1,cnt[l]+=1;
		a.push_back({l,r});
	}	
	for(int i=1;i<(int)pref.size();i++){
		pref[i] += pref[i-1];
	}
	for(int i=0;i<n;i++){
		int l = a[i].first;
		int r = a[i].second;
		if(l == r){
			if(cnt[l] > 1) cout << 0;
			else cout << 1;
		}
		else{
			if(pref[r] - pref[l-1] == (r - l + 1)){
				cout << 0;
			}
			else cout << 1;	
		}
		
	}
	cout << endl;
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