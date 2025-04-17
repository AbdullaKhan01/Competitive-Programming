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
	int n,l,k;
	cin >> n >> l >> k;
	vi d(n);
	for(int i=0;i<n;i++)
	{
		cin >> d[i];
	}
	vi a(n);
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
	}
	d.push_back(l);
	a.push_back(0);

	int INF = 1e18;
	vector<vector<int>>dp(n+1,vector<int>(k+1,INF));
	dp[0][0] = 0;
	for(int i=1;i<=n;i++)
	{
		//remove at most k signs
		for(int j=0;j<=k;j++)
		{
			// get the previous non removed sign
			for(int m=i-1;m>=0;m--)
			{
				// no of signs between them will be removed
				// removed sign = b/w i and m == 
				int removed = i - m - 1;
				if(removed <= j)
				{
					// then we are in valid state

					// how many signs not removed = j - removed
					dp[i][j] = min(dp[i][j],dp[m][j-removed] + (d[i] - d[m])*a[m]);
				}
			}
		}
	}
	cout << *min_element(all(dp.back()));
}
signed main(){
	fast_io();
    solve();
    return 0;
}