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
pair<int,int> func(int l,int r,int k){
	int sz = r - l + 1;
	if(sz < k) return {0,0};
	// cout << l << " " << r << endl;
	int mid = (l + r)/2;
	pair<int,int> ans;
	if(sz % 2 == 0){
		pair<int,int> g = func(l,mid,k);
		int v = (2 * g.first) + (mid * g.second);
		ans.first = v;
		ans.second = g.second * 2;
	}
	else{
		// cout << mid << endl;
		pair<int,int> g = func(l,mid-1,k);
		int v = (2 * g.first) + ((mid) * (g.second+1));
		ans.first = v;
		ans.second = (g.second * 2) + 1;
		// func(l,mid-1,k);
	}
	// cout << "returning " << ans.first << " " << ans.second << endl;
	return ans;

}
void solve()	
{
	int n,k;
	cin >> n >> k;
	cout << func(1,n,k).first << endl;
	// int l = 21 + 14 + 7;
	// int ans = l + 4 * 28 + l;
	// cout << ans << endl;

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