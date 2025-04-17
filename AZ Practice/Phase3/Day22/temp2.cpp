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
1 1 1 1 1
2 4 8 6 2
3 9 7 1 3
4 6 4 6 4
5 5 5 5 5 
6 6 6 6 6
7 9 3 1 7
8 4 2 6 8
9 1 9 1 9

*/
vector<vector<int>> a = {{0,0,0,0,0},{0,1,1,1,1},
{0,2,4,8,6},{0,3,9,7,1},{0,4,6,4,6},{0,5,5,5,5},
{0,6,6,6,6},{0,7,9,3,1},{0,8,4,2,6,8},{0,9,1,9,1}};
string solve(int m,vector<string> &s)
{
	
	m = m % 4;
	int n = s.size();
	int sum = 0;
	for(int i=0;i<n;i++)
	{
		string st = s[i];
		int x = 1;
		for(auto it:st)
		{
			string temp = to_string(it);
			int p = temp.back() - 48;
			x = (x * a[p][m]);
			x%=10;
		}
		sum += x;
	}
	if(sum % 2 == 0) return "EVEN";
	else return "ODD";
}
signed main(){
	fast_io();
    int tt = 1;
    // cin >> tt;
    vector<string> a = {"azbde","abcher","acegk"};
    int m = 3;
    while(tt--)
    {
    	cout << solve(m,a) << endl;
    }
    return 0;
}