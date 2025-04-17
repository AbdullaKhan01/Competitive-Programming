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
Q). Given an array and a number k

we have to divide the array into k subarrays such that
summation of max of all subarrays is minimum

*/
int n,k;
int a[1001];
int dp[1001][101];

int rec(int i,int x)
{
	// rec i,x return the minimum of sum of maximum of subarrays
	// which are ending at the index i and have been partitioned
	// into exactly x subarrays

	// pruning
	if(x < 0)
	{
		//invalid
		return 1e9;
	}
	// base case
	if(i == -1)
	{
		if(x == 0) 
		{
			return 0;
		}
		else 
		{
			//invalid
			return 1e9;
		}
	}
	// cache check
	if(dp[i][x] != -1)
	{
		return dp[i][x];
	}
	// transition
	int max_seen = a[i];
	int ans = 1e9;
	for(int j=i-1;j>=-1;j--)
	{
		ans = min(ans,rec(j,x-1) + max_seen);
		max_seen = max(max_seen,a[j]);
	}
	// save and return
	return dp[i][x] = ans;
}
void solve()
{
	cin >> n >> k;
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
	}	
	memset(dp,-1,sizeof(dp));
	cout << rec(n-1,k) << endl;
}
signed main(){
	fast_io();
    int tt = 1;
    // cin >> tt;
    while(tt--)
    {
    	solve();
    }
    return 0;
}