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
	int n;
	cin >> n;

	int matches = n * (n-1) / 2;
	int wins = matches/n;

	// cout << wins << endl;
	vector<vector<int>> ans(n+1,vector<int>(n+1,-1));
	vector<int> w(n+1,0);
	if(n % 2 == 0)
	{
		for(int i=2;i<=n;i+=2)
		{
			ans[i-1][i] = 0;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(ans[i][j] == -1)
			{
				if(w[i] < wins)
				{
					ans[i][j] = 1;
					w[i]++;
				}
				else
				{
					ans[i][j] = -1;
					w[j]++;
				}
			}
		}
	}

	for(int i=1;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			cout << ans[i][j] << " ";
		}
	}
	cout << endl;
	// there are total (n * (n-1))/2 games;

	// all teams 
	// 4 teams

	// matches : 

	/*
	(1,2) 0 (1,3) 1 (1,4) 4
	(2,3) 2 (2,4) 
	(3,4) 3 

	// total matches = n*(n-1)/2 
	// total wins = total matches / n = n * [(n-1)/2]
	// draws = total matches - total wins

	5 teams = 5 * 4 / 2 = 10 matches 
	wins = 10/2 = 5;
	draws = 0

	6 teams = 6 * 5 / 2 = 15 matches
	wins per team = 15/6 = 2 
	// draws in total = 3

	// (1,2) 0 (1,3) 1 (1,4) 1 (1,5) 5 (1,6) 6
	// (2,3) 2 (2,4) 2 (2,5) 5 (2,6) 6
	// (3,4) 0 (3,5) 3 (3,6) 3
	// (4,5) 4 (4,6) 4
	// (5,6) 0
	*/
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