#include<bits/stdc++.h>
#define mod 1000000007
#define mod2 998244353
#define ceil(a,b) ((a+b-1)/b)
#define floor(a,b)((a-b+1)/b)
#define fast_io() ios::sync_with_stdio(0);cin.tie(0);
#define ll long long
// #define int long long
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
	int n,m,q;
	cin >> n >> m >> q;
	vector<vector<int>>a(n,vector<int>(m));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin >> a[i][j];
		}
	}
	vector<vector<int>> l(m);
	for(int j=0;j<m;j++)
	{
		int orry = 0;
		l[j].push_back(-1);
		for(int i=0;i<n;i++)
		{
			orry |= a[i][j];
			l[j].push_back(orry);
		}
		sort(all(l[j]));
	}
	for(int i=0;i<q;i++)
	{
		int tt;cin >> tt;
		int left=1,right=n;
		while(tt--)
		{
			int a;char b;int c;

			cin >> a >> b >> c;
			a--;
			// int l,r;
			
			if(b == '>')
			{
				auto it = upper_bound(all(l[a]),c) - l[a].begin();
				left = max(left,it);
			}
			else if(b == '<')
			{
				auto it = lower_bound(all(l[a]),c) - l[a].begin();
				right = min(right,it-1);
			}
		}
		if(left <= right && left >= 1 && left <= n)
		{
			cout << left << endl;
		}
		else
		{
			cout << -1 << endl;
		}
	}
	
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