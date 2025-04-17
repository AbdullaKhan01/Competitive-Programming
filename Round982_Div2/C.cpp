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

int dfs(int idx,int size,map<int,int>&mp,map<int,vector<int>> &g,vector<int>&vis)
{
	// cout << "doing dfs" << endl;
	int add = idx;
	// cout << "on index " << idx << endl;
	vis[idx] = 1;
	int n_size = size + add;
	int ans = 0;
	if(g.find(n_size) != g.end())
	{
		vector<int> temp = g[n_size];
		for(auto v:temp)
		{
			if(!vis[v])
				ans = max(ans,dfs(v,n_size,mp,g,vis));
		}	
	}
	return add + ans;

}
void solve()
{

	int n;
	cin >> n;
	vector<int> a(n);
	map<int,int> mp;
	map<int,vector<int>> g;
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
		// 
		mp[a[i] + i] = i;
		g[a[i] + i].push_back(i);
	}
	int b = n;
	int maxi = 0;
	vector<int> vis(n+1,0);
	for(int i=1;i<n;i++)
	{
		if(a[i] == (n-i))
		{
			int ret = dfs(i,b,mp,g,vis);
			// cout << i << " returned " << ret << endl;
			maxi = max(maxi,ret);
		}
	}
	cout << b + maxi << endl;
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