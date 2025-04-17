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
/*


BASIC OBSERVATION -> a,b a % b == 0 a/b = x

// any x number can be made at most 2*x


8 6 6 2 -> 2 

a*2 = b*2

[a,b,c,d,e]


5 5 350 5 10

a b c d e

b % a == 0;
c % b == 0;


// a -> 0 - a
// b -> 0 - b
// c -> 0 - c

// e -> 0 - e
y -> 2y


*/
void solve()
{
	int n;
	cin >> n;
	vector<pair<int,int>> a(n);
	for(int i=0;i<n;i++)
	{
		cin >> a[i].first;
		a[i].second = i;
	}
	/*
	[3,2,5,5]
	[{3,0},{2,1},{5,2},{5,3}]
	[{2,1},{3,0},{5,2},{5,3}]
	[1 0 1 1]
	*/
	sort(a.begin(),a.end());
	vector<int> ans(n+1);
	ans[a[0].second] = 0;
	for(int i=1;i<n;i++)
	{
		// 7 3
		// 3 - 1
		int k = a[i].first;
		int ch = a[i-1].first;
		int rem = k % ch;
		int to_add = (ch-rem)%ch;
		int new_n = k + to_add;
		a[i].first = new_n;
		ans[a[i].second] = to_add; 
	}
	cout << n << endl;
	for(int i=0;i<n;i++)
	{
		cout << i+1 << " " << ans[i] << endl;
	}
}
signed main(){
	fast_io();
    ll tt;
    cin >> tt;
    while(tt--)
    {
        solve();
    }
    return 0;
}