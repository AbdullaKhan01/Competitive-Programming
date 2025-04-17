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
void solve3()
{
	int l,r,L,R;
	cin >> l >> r >> L >> R;
	int cnt = 0;
	for(int ro=2;ro<=100;ro++)
	{
		// ro-1 alice ro bob
		int m = ro-1;
		if((m >= l && m <= r) && (ro >= L && ro <= R))
		{
			cnt++;
			continue;
		}
		if((m >= L && m <= R) && (ro >= l && ro <= r))
		{
			cnt++;
		}
		// ro-1 bob ro alice
	}
	cout << max(cnt,1LL) << endl;
}
void solve2()
{
	int l,r,L,R;
	cin >> l >> r >> L >> R;
	int cnt = 0;
	int a = min(l,L) , b = max(r,R);
	int c = max(l,L) , d = min(r,R);
	// cout << a << " " << b << endl;
	cout << c << " " << d << endl;
	for(int i=c;i<=d;i++)
	{
		int next = i+1;
		int prev = i-1;
		if((next >= a && next <= b) || (prev>=a && prev<=b))
		{
			cnt++;
		}
	}
	cout << max(cnt,1LL) << endl;
}
void solve()
{
	int l,r,L,R;
	cin >> l >> r >> L >> R;
	// if(L >= r || l >= R)
	// {
	// 	cout << 1 << endl;
	// 	return ;
	// }
	int lower = min(l,L) , upper = max(r,R);
	int left = max(l,L) , right = min(r,R);

	int k = right - left + 2;

	if(left == lower) k--;
	if(right == upper) k--;

	cout << k << endl;
	return ;
}
signed main(){
	fast_io();
    ll tt;
    cin >> tt;
    while(tt--)
    {
        // solve();
        // solve2();
        solve3();
    }
    return 0;
}