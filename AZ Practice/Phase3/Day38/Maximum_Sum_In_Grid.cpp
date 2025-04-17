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
int maximumSumSubArray(vi& arr){
	int best = -1e18;
	int n = arr.size();
	vector<int> dp(n+1,0);
	for(int i=1;i<=n;i++)
	{
		dp[i] = max(arr[i-1],arr[i-1] + dp[i-1]);
		best = max(best,dp[i]);
	}
	return best;
 	// for(int k = 0; k < n-1; k++) {
	// 	sum = max(arr[k],sum+arr[k]);
	// 	best = max(best,sum); 
	// }
	// return best;	
}
void solve()
{
	// #define int long long // int will be replaced with this line
	// int x;
	// cout << sizeof(x) << endl;
	// #undef int // after this int will be normal

	// int y;
	// cout << sizeof(y) << endl;

	/*
	
	THE concept of dimensional reduction is used here 
	since contraints are N*M <= 10^5 and N,M <= 10 ^ 5

	hence we get the observation here that 
	// min(N,M) will be <= sqrt(10^5) 

	so we can solve the question in max(N,M) * (min(N,M))^2
	   this much complexity 

	   how because max(N*M) * min(N,M) * min(N,M)

	   == 10^5 * sqrt(10^5) == N * sqrt(N)
	*/

	int n,m;
	cin >> n >> m;
	int a[n][m];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin >> a[i][j];
		}
	}
	// m < n;
	int ans = -1e18;
	if(m <= n)
	{
		for(int c1=0;c1<m;c1++)
		{
			vector<int> rowSum(n,0);
			for(int c2=c1;c2<m;c2++)
			{
				for(int r=0;r<n;r++)
				{
					rowSum[r] += a[r][c2];
				}
				ans = max(ans,maximumSumSubArray(rowSum));
			}
		}
	}
	else
	{
		for(int r1=0;r1<n;r1++)
		{
			vector<int> colSum(m,0);
			for(int r2=r1;r2<n;r2++)
			{
				for(int c=0;c<m;c++)
				{
					colSum[c] += a[r2][c];
				}
				ans = max(ans,maximumSumSubArray(colSum));
			}
		}
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