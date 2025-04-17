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
string s;
vector<string> d;
int dp[301];
int rec(int level)
{	// returns if it is possible to break 
	// the string s[level,n] with the help of dictionary

	//pruning

	//base case
	if(level == n) return 1;

	//cache check
	if(dp[level] != -1) return dp[level];

	//compute
	int ans = 0;
	for(auto it:d)
	{
		int j = it.size();
		if(level + j <= n)
		{
			
			string t = s.substr(level,j);
			if(t == it)
			{
				ans |= rec(level + j);
			}
		}
	}
	//save and return
	return dp[level] = ans;

}
void solve()
{
	int x;
	cin >> x;
	cin >> s;
	n = s.size();
	d.resize(x);
	for(int i=0;i<x;i++)
	{
		cin >> d[i];
	}	
	memset(dp,-1,sizeof(dp));
	int k = rec(0);
	cout << (k ? "Yes":"No") << endl;
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