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
	// Longest Increasing Subsequence

	// 
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
	}
	vector<int> flis,blis;
	vector<int> f(n),b(n);
	for(int i=0;i<n;i++)
	{
		if(flis.empty() || flis.back() < a[i])
		{
			flis.push_back(a[i]);
			f[i] = flis.size();
		}
		else
		{
			auto it = lower_bound(flis.begin(),flis.end(),a[i]);
			*it = a[i];
			f[i] = it - flis.begin() + 1;
		}
	}

	for(int i=n-1;i>=0;i--)
	{
		if(blis.empty() || blis.back() < a[i])
		{
			blis.push_back(a[i]);
			b[i] = blis.size();
		}
		else
		{
			auto it = lower_bound(blis.begin(),blis.end(),a[i]);
			*it = a[i];
			b[i] = it - blis.begin() + 1;
		}
	}

	int ans = 0;
	for(int i=0;i<n;i++)
	{
		int inc = f[i] - 1;
		int dec = b[i] - 1;
		if(inc != 0 && dec != 0)
		ans = max(ans,inc + dec + 1);
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