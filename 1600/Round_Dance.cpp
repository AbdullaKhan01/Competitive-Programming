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

// Approach -> jo bhi close circle hoga wo to max
// aur min dono me contribute karega +1 ka aur jo
// open circle hoga wo close to ho hi sakta hai to wo
// max me to contribute karega hi but wo wait karega
// baaki open circles ka to merge with them so end
// me saare open circles ko ek me merge kar denge


vector<set<int>>g;
void dfs(int node,vector<int> &vis,int &alpha)
{
	vis[node] = 1;
	if(g[node].size() == 1) alpha = 1;	
	for(auto v:g[node])
	{
		if(!vis[v])
		{
			dfs(v,vis,alpha);
		}
	}
}
void solve()
{
	int n;
	cin >> n;
	vector<int> a(n+1);
	g.assign(n+1,set<int>());
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	for(int i=1;i<=n;i++)
	{
		// cout << a[i] << endl;
		g[i].insert(a[i]);
		g[a[i]].insert(i);
	}
	// sort(all(g),[&](set<int>&a,set<int>&b){
	// 	if(a.size() == b.size()) return true;
	// 	return a.size() > b.size();
	// });
	vector<int> vis(n+1,0);
	int cnt = 0;
	int x = 0 , y = 0;
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			int a = 0;
			dfs(i,vis,a);
			if(!a)
			{
				// full
				x++;
				y++;
			}
			else
			{
				// half
				y++;
				cnt++;
			}
		}
	}
	if(cnt >= 1) x++;
	cout << x << " " << y << "\n";
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