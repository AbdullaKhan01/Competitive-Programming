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

void solve2(string &s)
{
        int n = s.size();
 
        if (n == 0)
        {
            cout << 0 << endl;
            return ;
        }
 
        vector<int> dp(n + 1, 0); // dp[i] will store the number of ways to decode the first i characters.
        dp[0] = 1;
        dp[1] = (s[0] != '0') ? 1 : 0;
        for (int i = 2; i <= n; i++)
        {
            if (s[i - 1] == '0')
            {
                if (s[i - 2] != '1' || s[i - 2] != '2')
                {
                    continue;
                }
            }
 
            if (s[i - 1] != '0')
            {
                dp[i] = dp[i - 1];
            }
 
            if (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6'))
            {
                dp[i] += dp[i - 2];
            }
        }
 
        cout << dp[n] << endl;
}
void solve(string &s)
{

	int n = s.size();
	vector<int> dp(n+1,0);
	dp[0] = dp[1] = 1;
	bool flag = true;
	for(int i=2;i<=n;i++)
	{
		int d1 = s[i-1] - '0';
		int d2 = s[i-2] - '0';
		if(d1 != 0)
			dp[i] += dp[i-1];
		int ap = 10*d2 + d1;
		if(ap <= 26 && d2 != 0)
		{
			dp[i] += dp[i-2];
		}
		if(d1 == 0)
		{
			if(d2 == 1 || d2 == 2) continue;
			else flag = false;
		}
	}
	if(flag == false)
	{
		cout << 0 << " ";
	}
	else cout << dp[n] << " ";
}
signed main(){
	fast_io();
    string tt;
    cin >> tt;
    while(tt != "0")
    {
    	solve(tt);
    	solve2(tt);
    	cin >> tt;
    }
    return 0;
}