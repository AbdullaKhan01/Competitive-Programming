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
void dfs(int a,vector<int>&g,vector<int>&vis,vector<int>&ans,string s)
{
	// int n = s.size();
	int cnt = 0;
	int st = a;

	// cout << "starting with " << a << endl;
	do
	{
		// cout << st << " ";
		cnt+=(s[st-1] == '0');
		st = g[st];
	}while(st != a);
	// cout << cnt << endl;
	st = a;
	do
	{
		vis[st] = 1;
		ans[st] = cnt;
		st = g[st];
	}while(st != a);
	// cout << endl;
}
void solve()
{
	int n;
	cin >> n;
	vector<int> p(n,0);
	for(int i=0;i<n;i++)
	{
		cin >> p[i];
	}
	string s;
	cin >> s;
	vector<int> g(n+1);
	for(int i=1;i<=n;i++)
	{
		g[i] = p[i-1];
	}
	vector<int> visited(n+1,0);
	vector<int> ans(n+1,0);
	for(int i=1;i<=n;i++)
	{
		if(!visited[i])
		{
			// cout << i << " ok " << endl;
			dfs(i,g,visited,ans,s);
		}
		// cout << i << "ok" << endl;	
	}
	for(int i=1;i<=n;i++)
	{
		cout << ans[i] << " ";
	}
	cout << endl;
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