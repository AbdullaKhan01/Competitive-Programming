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
void solve()
{
	cin >> n;
	vector<vector<int>>a(n+1,vector<int>(3,0));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<3;j++)
		{
			cin >> a[i][j];
		}
	}
	int ans = 0;
	for(int i=n-1;i>=0;i--)
	{
		for(int j=0;j<3;j++)
		{
			int maxi = INT_MIN;
			for(int k=0;k<3;k++)
			{
				if(k == j) continue;
				maxi = max(maxi,a[i+1][k]);
			}
			a[i][j] += maxi;
			if(i == 0) ans = max(ans,a[i][j]);
		}
	}
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