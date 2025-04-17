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

0 
5
0
7

*/
string temp = "narek";

bool fal(char ch)
{
	return !(ch == 'n'|| ch == 'a'|| ch == 'r'|| ch == 'e'|| ch == 'k');
}
void solve()
{
	int n,m;
	cin >> n >> m;
	// no of string length of each string

	const int inf = 1e9;
	vector<int> dp(5,-inf);
	dp[0] = 0;



	// dp[i] = max ans such that last string
	// was pref(0,i] of temp

	// means pref(0,0] = ""
	// means pref(0,1] = "n"
	// means pref(0,2] = "na"
	// means pref(0,3] = "nar"
	// means pref(0,4] = "nare"

	vector<string> a(n);
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
	}

	vector<int> p;
	for(int i=0;i<n;i++)
	{
		p = dp;
		for(int j=0;j<5;j++)
		{
			int cnt = 0;
			int idx = j;
			for(auto it:a[i])
			{
				if(fal(it)) continue;
				cnt--;
				if(it == temp[idx])
				{
					idx++;
					if(idx == 5)
					{
						cnt+=10;
						idx = 0;
					}
				}
			}

			p[idx] = max(p[idx],dp[j] + cnt);
			
		}
		dp = p;
		// cout << endl;
		// output(dp);
		// cout << endl;
		// cout << endl;
		// cout << endl;
	}
	cout << *max_element(all(dp)) << endl;
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