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
		int n,m;
		cin >> n >> m;
		vector<int> a(n,-1);
		vector<pair<int,int>> s(m);
		vector<int> pref(n+1,0);
		for(int i=0;i<m;i++)
		{
			cin >> s[i].first >> s[i].second;
		}
		int q;
		cin >> q;
		vector<int> c(q);
		for(int i=0;i<q;i++)
		{
			cin >> c[i];
			c[i]--;
		}
		int ans = -1;

		int st = 0 , e = q;
		while(st <= e)
		{
			int mid = (st + e)/2;
			int cnt = 0;
			// we make the first mid changes
			for(int i=0;i<mid;i++)
			{
				a[c[i]] = 1;
			}
			// do the operations
			for(int i=0;i<=n;i++)
			{
				pref[i] = 0;
			}
			for(int i=0;i<n;i++)
			{
				pref[i+1] = pref[i] + a[i];
			}
			for(int i=0;i<m;i++)
			{
				int l = s[i].first;
				int r = s[i].second;
				int sum = pref[r] - pref[l-1];
				if(sum > 0) cnt++;
			}
			// then we reverse the first mid changes
			for(int i=0;i<mid;i++)
			{
				a[c[i]] = -1;
			}
			if(cnt > 0)
			{
				ans = mid;
				e = mid - 1;
			}
			else st = mid + 1;
		}
		cout << ans << "\n";
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