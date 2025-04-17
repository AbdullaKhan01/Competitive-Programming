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

// Given a tree find the value of
// 1. min(abs(val[x]-val[y]))
// 2. max(abs(val[x]-val[y]))
// for each node 


// for max just maintain min and max for each node from their
// ancestors

vector<int> g[100100];
int ans[100100];
int val[100100];

multiset<int> ms;
void insert(int x)
{
	ms.insert(x);
}
void remove(int x)
{
	ms.erase(ms.find(x));
}
int query(int x)
{
	int ans = 1e9;
	auto it = ms.lower_bound(x);
	if(it != ms.end())
	{
		ans = min(ans,abs(*it-x));
	}
	if(it != ms.begin())
	{
		it--;
		ans = min(ans,abs(*it-x));
	}
	return ans;
}
void dfs(int node,int parent)
{
	ans[node] = query(val[node]);
	insert(val[node]);
	for(auto v:g[node])
	{
		if(v != parent)
		{
			dfs(v,node);
		}
	}
	remove(val[node]);
}
void solve()
{
	
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