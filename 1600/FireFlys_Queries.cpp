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
int ask(int x,int n,int sum,vector<int>&pref)
{

		int total = x;
		int full = total/n;
		int ans = full * sum;
		int half = total - (full*n);
		int idx = full;
		int right = n - idx;
		// int left = idx;
		if(half > 0)
		{
			// take half elements from idx;
			ans += pref[min(n,idx+half)] - pref[idx];
			half = max(0LL,half-right);
		}
		if(half > 0)
		{
			ans += pref[half];
		}
		return ans;
}
void solve()
{
	int n,q;
	cin >> n >> q;
	vector<int> a(n),pref(n+1,0);
	int sum = 0;
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
		sum += a[i];
		pref[i+1] = pref[i] + a[i];
	}
	// cout << sum << endl;
	while(q--)
	{

		int l,r;
		cin >> l >> r;
		int ans = ask(r,n,sum,pref) - ask(l-1,n,sum,pref);
		cout << ans << endl;
	}

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