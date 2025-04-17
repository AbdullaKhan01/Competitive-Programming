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
int pref[100100][31];
int n;
void clear()
{
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<31;j++)
		{
			pref[i][j] = 0;
		}
	}
}
void solve()
{
	cin >> n;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		for(int j=0;j<32;j++)
		{
			if(1 & (a[i]>>j))
			{
				pref[i][j]=1;
			}

		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<31;j++)
		{
			pref[i][j] += pref[i-1][j];
		}
	}
	/*

	001
	010
	011
	100
	101


	*/
	int q;
	cin >> q;
	while(q--)
	{
		int l,r;
		cin >> l >> r;
		// solve for each bit separately
		int x1 = 0,x2=0,x3=0;
		// for xor if no of 0's > 1/2
		// for or if no of 1's not equal to r-l+1
		// for and if and no if 1
		for(int i=0;i<31;i++)
		{
			int range = r - l + 1;
			int no_of_ones = pref[r][i] - pref[l-1][i];
			// int no_of_zeroes = 31 - no_of_ones;
			// cout << no_of_ones << " " << no_of_zeroes << endl;
			if(2 * no_of_ones < range)
			{
				x1 += (1LL<<i);
			}
			if(no_of_ones != range)
			{
				x2 += (1LL<<i);
			}
			if(no_of_ones)
			{
				x3 += (1LL<<i);
			}

		}
		int ans = x1 + x2 + x3;
		cout << ans << "\n";
	}
}
signed main(){
	fast_io();
    ll tt;
    cin >> tt;
    while(tt--)
    {
        solve();
        clear();
    }
    return 0;
}