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
	string s1,s2,s3;
	cin >> s1 >> s2 >> s3;
	int a = s1.size() , b = s2.size() , c = s3.size();
	int dp[a+1][b+1][c+1];
	// what does dp[i][j][k] denote
	// dp[i][j][k] -> max length subsequence of the string
	// s1(0,i) && s2(0,j) && s3(0,k);
	// dp[1][1][1]
	// dp[a][b][c]
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++)
		{
			for(int k=1;k<=c;k++)
			{
				// not take
				dp[i][j][k] = max({dp[i-1][j][k],dp[i][j-1][k],dp[i][j][k-1]});
				if(s1[i-1] == s2[j-1] && s2[j-1] == s3[k-1])
				{
					// take
					// cout << "updating for " << i << " " << j << " " << k << endl;
					dp[i][j][k] = max(dp[i][j][k],1+dp[i-1][j-1][k-1]);
				}
			}
		}
	}
	cout << dp[a][b][c] << endl;
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