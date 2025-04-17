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
int queens[15];

bool check(int row,int col)
{
	for(int pr = 0 ; pr < row ; pr++)
	{
		int pc = queens[pr];

		if(pc == col || abs(row - pr) == abs(col - pc) || abs(row-pr) + abs(col - pc) == 3)
		{
			return 0;
		}
	}
	return 1;
}
int rec(int level)
{
	// returns no of ways to place queens from [level to ... n]
	// give that queens are already placed from [0 to ... lev-1]
	
	// base case
	if(level == n) 
	{
		return 1;
	}

	// choices 
	int ans = 0;
	for(int i=0;i<n;i++)
	{
		if(check(level,i))
		{
			// place the queen
			queens[level] = i;
			// calculate the answer
			ans += rec(level+1);
			// unplace
			queens[level] = -1;
		}
	}
	return ans;
}
void solve()
{
	cin >> n;
	memset(queens,-1,sizeof(queens));
	cout << rec(0);
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