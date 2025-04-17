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
	int n,m,q;
	cin >> n >> m >> q;
	vector<int> a;
	for(int i=0;i<m;i++)
	{
		int x;
		cin >> x;
		a.push_back(x);
	}
	while(q--)
	{
		int p;
		cin >> p;
		if(p <= a[0])
		{
			cout << a[0]-1 << endl;
		}
		else if(p >= a.back())
		{
			cout << n - a.back() << endl;
		}
		else
		{
			auto it = lower_bound(a.begin(),a.end(),p);
			int r = *it;
			it--;
			int l = *it;
			int g = (r+l)/2;
			cout << min(r-g,g-l) << endl;
		}

	}
}
signed main(){
	fast_io();
    int tt = 1;
    cin >> tt;
    while(tt--)
    {
    	// solve2();
    	solve();
    }
    return 0;
}