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
pair<double,double> p[101];

double sq(double x)
{
	return x*x;
}
double cost(int x,int y)
{
	double dist = sqrt(sq(p[x].first-p[y].first) + sq(p[x].second - p[y].second));
	return sin(dist);
}

void solve()
{
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> p[i].first >> p[i].second;
	}
	double dp[n+1][n+1];
	for(int len = 3;len<=n;len++)
	{
		for(int l=1;l+len-1<=n;l++)
		{
			int r = l + len - 1;

			if(len == 3)
			{
				 dp[l][r] = 0;
				 continue;
			}

			double ans = 1e9;
			//compute
			for(int x = l+1;x<= r-1;x++)
			{
				if(x == l+1)
				{
					ans = min(ans,cost(l+1,r)+dp[l+1][r]);
				}
				else if(x == r-1)
				{
					ans = min(ans,cost(l,r-1)+dp[l][r-1]);
				}
				else
				{
					ans = min(ans,cost(l,x)+cost(x,r)+dp[l][x]+dp[x][r]);
				}
			}
		}
	}
	cout << dp[1][n] << endl;
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