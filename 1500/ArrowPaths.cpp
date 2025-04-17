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
signed main(){
	fast_io();
    // >><<
    // >>><

    // dp[i][j] == can we win if are starting to move 
    // from the point (i,j)

    ll tt;
    cin >> tt;
    while(tt--)
    {
        int n;
        cin >> n;
        string a,b;
        cin >> a >> b;
        vector<vector<int>> dp(2,vector<int>(n+1));
        dp[0][n-1] = 1;
        dp[1][n-1] = 1;

        for(int col=n-2;col>=0;col--)
        {
        	for(int row=0;row<2;row++)
        	{
        		{
        			// calculate dp[row][col]
        			if(row == 0)
        			{
        				if(a[col+1] == '>' && col+2 <= n)
        					dp[row][col] = dp[row][col+2];
        				if(b[col] == '>')
        					dp[row][col] = max(dp[row][col],dp[row+1][col+1]);
        			}
        			else
        			{
        				if(b[col+1] == '>' && col+2 <= n)
        					dp[row][col] = dp[row][col+2];
        				if(a[col] == '>')
        					dp[row][col] = max(dp[row][col],dp[row-1][col+1]);
        			}
        		}
        	}
        }
        cout << (dp[0][0]?yes:no) << '\n';
    }
    return 0;
}