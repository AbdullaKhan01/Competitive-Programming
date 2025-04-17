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
vector<string> b(8);
int queens[8];

bool check(int row,int col)
{
	for(int pr=0;pr<row;pr++)
	{
		int pc = queens[pr];
		// same column or diagonal
		if(pc == col || abs(pr-row) == abs(pc-col))
		{
			return 0;
		}
	}
	return 1;
}
int build(int level)
{
	// returns total no of ways to place queens
	// from the levels [level....8]
	// if queens are already placed in levels[0...level-1]

	// base case
	if(level == 8)
	{
		return 1;
	}
	//recursive case

	// choices 
	int ans = 0;
	for(int i=0;i<8;i++)
	{
		//check
		if(b[level][i] != '*' && check(level,i))
		{
			// place 
			queens[level] = i;
			// cnt next
			ans += build(level+1);
			// unplace
			queens[level] = -1;
		}
	}
	return ans;
}
void solve()
{
	
	for(int i=0;i<8;i++)
	{
		cin >> b[i];
	}
	memset(queens,-1,sizeof(queens));
	int ans = build(0);
	cout << ans;
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