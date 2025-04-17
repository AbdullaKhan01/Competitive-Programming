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
	void print(queue<pair<int,int>>q)
	{
		while(!q.empty())
		{
			cout << "{"<< q.front().first << "," << q.front().second  << "} ";
			q.pop();
		}
		cout << endl;
	}
	void solve()
	{
		int n,eta;cin >> n >> eta;
		vector<pair<int,int>>a(n);
		for(int i=0;i<n;i++)
		{
			cin >> a[i].first >> a[i].second;
		}
		// 05 34 
		// mod(5 - s) <= 10
		// s >= 5-10 && s <= 5+10
		// s >= -5 && s <= 15
		sort(all(a));
		queue<pair<int,int>>q;
		multiset<int> ms;
		int ans = 0;
		for(int i=0;i<n;i++)
		{
			int e = a[i].first;
			// abs(e - s) <= eta
			// s >= e - eta
			int k = e - eta;
			// cout << a[i].first << endl;
			// cout << endl;
			while(!q.empty() && q.front().first < k)
			{
				int a = q.front().first;
				int b = q.front().second;
				q.pop();
				int calc = b - a;
				ms.erase(ms.find(calc)); 
			}
			// print(q);
			if(!ms.empty())
			{
				int val = *ms.rbegin();
				ans = max(ans,a[i].first + a[i].second + val);
			}
			int ncalc = a[i].second - (a[i].first);
			q.push({a[i].first,a[i].second});
			ms.insert(ncalc);
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