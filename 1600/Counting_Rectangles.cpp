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
int g[1001][1001];
void solve()
{
	memset(g,0,sizeof(g));
	int n,q;
	cin >> n >> q;
	for(int i=0;i<n;i++)
	{
		int h,w;
		cin >> h >> w;
		g[h][w] += h * w;
	}
	for(int h=1;h<=1000;h++)
	{
		for(int w=1;w<=1000;w++)
		{
			g[h][w] = g[h][w] + g[h-1][w] + g[h][w-1] - g[h-1][w-1];
		}
	}
	while(q--)
	{
		int h1,w1,h2,w2;
		cin >> h1 >> w1 >> h2 >> w2;
		if(h2 - h1 == 1 || w2 - w1 == 1)
		{
			cout << 0 << endl;
		}
		else
		{
			// we have some rectangle area to calculate

			// rectangle 

			int ans = g[h2-1][w2-1] - g[h1][w2-1] - g[h2-1][w1] + g[h1][w1];

			cout << ans << endl;
		}
	}
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