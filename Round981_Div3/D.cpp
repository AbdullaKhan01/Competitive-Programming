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
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> pref(n+1,0);
	int cnt = 0;
	// int j = 0;
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
		// int x;
		// cin >> x;
		// if(x == 0) cnt++;
		// else a.push_back(x);
		// pref[i+1] = pref[i] + a[i];
	}
	for(int i=0;i<n;i++)
	{
		// cout << a[i] << " ";
		pref[i+1] = pref[i] + a[i];
	}
	// cout << endl;
	set<int> st;
	st.insert(0);
	int prev = 0;
	// int cnt = 0;
	for(int i=1;i<=n;i++)
	{
		// pref[r] = pref
		if(st.count(pref[i]-prev))
		{
			// cout << "found for " << i << endl;
			prev = pref[i];
			cnt++;
			set<int> nst;
			nst.insert(0);
			st = nst;

		}
		else st.insert(pref[i] - prev);
	}
	cout << cnt << endl;
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