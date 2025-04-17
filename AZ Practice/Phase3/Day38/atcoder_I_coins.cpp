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
int n;
int x;
double p[3000];
double dp[3000][3000];
double rec(int level,int heads)
{
	
	cout << fixed << setprecision(10);
	// if(score < 0) return 0;
	// cout << level << " " << score << endl;
	if(level == n)
	{
		return (heads > n - heads);
	}
	//cache check
	if(dp[level][heads] != -1) return dp[level][heads];
	//compute
	double ans = 0;
	double a = p[level] * rec(level+1,heads+1);
	double b = (1-p[level]) * rec(level+1,heads);
	
	// cout << level << " " << score << " " << a << " " << b << " " << a+b << endl;
	ans = (a+b);

	return dp[level][heads] = ans;
}
void solve()
{
	cin >> n;
	// x = n/2;
	// cout << fixed << setprecision(12);
	for(int i=0;i<n;i++)
	{
		cin >> p[i];
	}
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			dp[i][j] = -1;
		}
	}
	cout << rec(0,0) << endl;
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