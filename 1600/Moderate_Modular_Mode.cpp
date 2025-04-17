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
long long lcm (long long a, long long b) {
    return a / __gcd(a, b) * b;
}
void solve()
{
	int x,y;
	cin >> x >> y;
	int n = 0;
	if(x > y)
	{
		n = lcm(x,y) + y;
	}
	else
	{
		// x <= y
		if(y % x == 0)
		{
			n = x;
		}
		else
		{
			// y % x != 0
			// find greatest multiple of x <= y
			int g = x * (y/x);
			// just print mid point
			n = g + (y - g) / 2;
		}
	}
	if(n % x == y % n)
	{
		cout << n << endl;
	}
	else cout << -1 << endl;
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