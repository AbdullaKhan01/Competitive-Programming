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

// VERDICT -> ACCEPTED
bool has(string a,string b)
{
	return (a[0] == b[0] )||( a[0] == b[1] )|| (a[1] == b[0]) || (a[1] == b[1]);	
}
void solve2()
{
	int n,q;
	cin >> n >> q;
	vector<string> v = {"BG","BR","BY","GR","GY","RY"};

	vector<string> x(n);
	input(x);
	map<string,int> mp;
	vector<vector<int>> ans(n,vector<int>(0,INT_MAX));

	mp[x[n-1]] = n-1;
	for(int i=n-2;i>=0;i--)
	{
		string t = x[i];
		for(auto it:v)
		{
			if(it == t) continue;
			if(has(t,it) && mp.find(it) != mp.end())
			{
				ans[i].push_back(mp[it]);
			}
		}
		mp[t] = i;
	}
	mp.clear();
	mp[x[0]] = 0;
	for(int i=0;i<n;++i)
	{
		string t = x[i];
		for(auto it:v)
		{
			if(it == t) continue;
			if(has(t,it) && mp.find(it) != mp.end())
			{
				ans[i].push_back(mp[it]);
			}
		}
		mp[t] = i;
	}
	// now process the queries
	while(q--)
	{
		int l,r;
		cin >> l >> r;
		l--;r--;
		if(has(x[l],x[r]))
		{
			cout << abs(r-l) << endl;
		}
		else
		{
			int p = INT_MAX;
			for(auto it:ans[l])
			{
				int dis = abs(l-it) + abs(r-it);
				p = min(p,dis);
			}
			if(p == INT_MAX) p = -1;
			cout << p << endl;
		}
	}
}
signed main(){
	fast_io();
	ll tt;
	cin >> tt;
	while(tt--)
	{
		solve2();  
	}
    
    return 0;
}