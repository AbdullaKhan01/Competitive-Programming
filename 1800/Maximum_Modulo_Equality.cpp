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
const int MAX_N = 200'005;
const int LOG = 25;
int b[MAX_N];
int m[MAX_N][LOG]; // m[i][j] is minimum among all a[i...i + 2^j-1]
int bin_log[MAX_N];
int query(int L,int R)
{
	int length = R - L + 1;
	// int k = 31 - __builtin_clz(length);
	int k = bin_log[length];
	return __gcd(m[L][k],m[R - (1 << k) + 1][k]);
}
void precompute(int n)
{
	bin_log[1] = 0;
	for(int i=2;i<MAX_N;i++)
	{
		bin_log[i] = bin_log[i/2] + 1;
	}
	// precompute 
	for(int k=1;k<LOG;k++)
	{
		for(int i=0;i + (1 << k) - 1 < n;i++)
		{
			// change or and or gcd etc
			m[i][k] = __gcd(m[i][k-1],m[i + (1<<(k-1))][k-1]);
		}
	}
}
void solve()
{
	int n,q;
	cin >> n >> q;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	// build a sparse table
	// xmodm = ymodm
	// what does this statement means
	// (x-y)mod m = 0
	// this means that m is a divisor of x-y
	// now let's generalize this 
	// if a(l)modm = a(l+1)modm = a(l+2)modm .... = a(r)mod m
	// then (a(l+1)-a(l))mod m = (a(l+2)-a(l+1))modm ......
	// ... = (a(r)-a(r-1))mod m = 0
	// this means m is a divisor of all the numbers
	// a(l+1)-a(l) , a(l+2)-a(l+1) ,, ..... a(r)-a(r-1)
	// and since we want the number m to be maximum possible
	// so
	// m is the 
	//gcd of (a(l+1)-a(l) , a(l+2)-a(l+1) ,, ..... a(r)-a(r-1))
	// so basically we want to print the gcd of all those 
	// numbers in every query so we can build a sparse table
	// to do that

	// let's do this

	// 9 12 4 3
	for(int i=1;i<n;i++)
	{
		int val =  abs(a[i] - a[i-1]);
		m[i-1][0] = val;
	}
	precompute(n);
	while(q--){
		int l,r;
		cin >> l >> r;
		l--,r--;
		if(l==r) cout << 0 << " ";
		else{
			cout << query(l,r-1) << " ";
		}
	}
	cout << endl;
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