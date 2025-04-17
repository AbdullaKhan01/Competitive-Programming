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
	Last Contest -> Before Break
*/
void solve()
{
	int n,m,v;
	cin >> n >> m >> v;
	vector<int> a(n);
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
	}
	vector<int> pref(n),suff(n+1,0);
	int sum = 0;
	for(int i=n-1;i>=0;i--)
	{
		sum += a[i];
		suff[i] = suff[i+1];
		if(sum >= v)
		{
			sum = 0;
			suff[i]++; 
		}
	}
	sum = 0;
	for(int i=0;i<n;i++)
	{
		sum += a[i];
		if(i > 0) pref[i] = pref[i-1];
		if(sum >= v)
		{
			sum = 0;
			pref[i]++;
		}
	}
	// output(pref);cout << endl;
	// output(suff);cout << endl;
	const int inf = 1e9;
	vector<int> l(n+1,inf);
	int gg = 0;
	vector<int> psum(n,0);
	int flag = false;
	int ans = 0;
	for(int i=0;i<n;i++)
	{
		
		psum[i] += a[i];
		if(i > 0) psum[i] += psum[i-1];
		gg+=a[i];
		l[pref[i]] = min(l[pref[i]],i);
		int g = suff[i+1];
		int needed = abs(m - g);
		if(needed == 0)
		{
			// ans = max(ans,gg);
		}
		// cout << i << " " << g << " " << needed << endl;
		// 
		int k = l[needed];

		if(k != inf)
		{
			// we can take the subarray from i to k+1
			flag = true;
			ans = max(ans,gg - psum[k]);
		}
	}
	if(flag)
	{
		cout << ans << endl;
	}
	else
	{
		cout << -1 << endl;
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