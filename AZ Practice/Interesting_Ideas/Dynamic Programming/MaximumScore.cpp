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
int n,m;
int k;
void solve()
{
	cin >> n >> m;
	cin >> k;
	vector<string> a(n+1);
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		// cout << a[i] << endl;
	}
	// return ;
	int dp[n+1][m+1][k+1];
	memset(dp,-1,sizeof(dp));
	for(int i=0;i<m;i++)
	{
		int val = a[n][i] - '0';
		dp[n][i][val % k] = val;
	}
	for(int r=n-1;r>=1;r--)
	{
		for(int c=0;c<m;c++)
		{
			int num = a[r][c] - '0';
			for(int g=0;g<k;g++)
			{
				if(c-1 >= 0 && dp[r+1][c-1][g] != -1)
				{
					dp[r][c][(g+num)%k] = max(dp[r][c][(g+num)%k],dp[r+1][c-1][g] + num);
				}
				if(c+1 >= 0 && dp[r+1][c+1][g] != -1)
				{
					dp[r][c][(g+num)%k] = max(dp[r][c][(g+num)%k],dp[r+1][c+1][g] + num);
				}
			}
		}
	}
	int ans = -1;
	for(int i=0;i<m;i++)
	{
		ans = max(ans,dp[1][i][0]);
	}
	cout << ans << endl;
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