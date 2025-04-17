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
int dp[100100];
int rec(int x)
{
	if(x == 0)
	{
		return 0;
	}
	// cache check
	if(dp[x] != -1)
	{
		return dp[x];
	}
	// compute
	int ans = 0;
	for(int m=0;(1<<m) <= x;m++)
	{
		if(rec(x - (1<<m)) == 0)
		{
			ans = 1;
			break;
		}
	}
	//save and return 
	return dp[x] = ans;
}
void solve()
{
	int n;
	cin >> n;
	// memset(dp,-1,sizeof(dp));
	// for(int i=0;i<=12;i++)
	// {
	// 	cout << i << " -> " << rec(i) << endl;
	// }
	if(n % 3 == 0)
	{
		cout << "Abhishek\n";
	}
	else cout << "Vivek\n";
	// cout << rec(n) << endl;
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