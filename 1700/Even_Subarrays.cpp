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
const int N = 3e6 + 1;
int dp[N];

// VERDICT -> ACCEPTED

// just precompute the xor prefix array

// consider the case for all perfect squares from 1 to 1000

	

void solve()
{
	// precompute();
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> pref(n+1);
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
		pref[i+1] = pref[i] ^ a[i];

	}
	for(int i=0;i<=n;i++)
	{

	}

	dp[0] = 1;
	int cnt = 0;
	for(int i=1;i<=n;i++)
	{
		// we have pref[r]
		// we want pref[r] ^ pref[l-1] == perfect square
		// pref[l-1] == perfect square ^ pref[r]
		int pairs = i;
		for(int j = 0 ; j <= 1000;j++)
		{
			// pref[l]
			int finder = j*j ^ pref[i];
			if(dp[finder])
			{
				// cout << "true for " << j << endl;
			}
			pairs -= dp[finder];
		}
		// cout << i << " " << pairs << endl;
		cnt += pairs;
		dp[pref[i]]++;
	}
	cout << cnt << endl;
	for(int i=0;i<=n;i++)
	{
		dp[pref[i]] = 0;
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