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
const int inf = 1e18;

int solve(vector<int>&a,vector<vector<int>>&brr,vector<int>& dp,int n)
{
	vector<int> temp = brr[n];
	int sum = 0;

	for(int i=0;i<temp.size();i++)
	{
		if(dp[temp[i]] != inf)
		{
			sum += min(a[temp[i]],dp[temp[i]]);
		}
		else
		{
			dp[temp[i]] = min(a[temp[i]],solve(a,brr,dp,temp[i]));
			sum += dp[temp[i]];
		}
	}

	return sum;
}
signed main(){
	fast_io();
	// intuition -> simple graph + dp question
	// if the portion value is yet not calculated 
	// then calculate it and store min value in dp array
	// and then use it optimally
    ll tt;
    cin >> tt;
    while(tt--)
    {
        int n,k;
        cin >> n >> k;
        vector<int> dp(n+1,inf);
        vi a(n+1);
        for(int i=1;i<=n;i++) cin >> a[i];
        for(int i=0;i<k;i++)
        {
        	int x;
        	cin >> x;
        	dp[x] = 0;
        }
        // for(int i=1;i<=n;i++)
        // {
        // 	dp[i] = min(dp[i],a[i]);
        // }
        vector<vector<int>> brr(n+1,vector<int>(0));
        for(int i=1;i<=n;i++)
        {
        	int l;
        	cin >> l;
        	if(l == 0) dp[i] = min(dp[i],a[i]);
        	else
        	{
        		while(l--)
        		{
        			int x;
        			cin >> x;
        			brr[i].push_back(x);
        		}
        	}
        }
        for(int i=1;i<=n;i++)
        {
        	if(dp[i] == inf)
        	{
        		dp[i] = min(a[i],solve(a,brr,dp,i));
        	}
        }
        for(int i=1;i<=n;i++)
        {
        	cout << dp[i] << " ";
        }
        cout << endl;
    }
    return 0;
}