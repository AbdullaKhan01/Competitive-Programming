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
vector<int> g[200100];
int dep[200100];
int par[200100];

int c1 = INT_MAX;
int c2 = INT_MAX;

int cnt = 0;
int given = -1;


vector<int> counter1,counter2;

// FIND the no of diameters of the Tree

// found centers 
// 1 center or 2 center

// different cases

// beware of edge case of 1 single node

void dfs(int node,int parent,int depth)
{
	dep[node] = depth;
	par[node] = parent;	



	if(dep[node] == given)
	{
		cnt++;
	} 

	for(auto v:g[node])
	{
		if(v != parent)
		{
			dfs(v,node,depth+1);
		}
	}


	if(parent == c1)
	{
		counter1.push_back(cnt);
		cnt = 0;
	}
	else if(parent == c2)
	{
		counter2.push_back(cnt);
		cnt = 0;
	}
}
void diameter()
{
	dfs(1,0,0);
	int end1 = 1;
	for(int i=1;i<=n;i++)
	{
		if(dep[i] > dep[end1])
		{
			end1 = i;
		}
	}
	dfs(end1,0,0);
	int end2 = 1;
	for(int i=1;i<=n;i++)
	{
		if(dep[i] > dep[end2])
		{
			end2 = i;
		}
	}

	// now we have got the end1 and end2 of the diameters
	int len = dep[end2];

	// cout << len << endl;
	int z = len/2;
	given = z;
	cnt = 0;
	if(len % 2 == 0)
	{
		// 1 center
		// to find center go len/2 up from end1 
		int node = end2;
		given = z;
		while(z--)
		{
			node = par[node];
		}
		// we have found the center
		c1 = node;
		
		dfs(c1,0,0);

		int ans = 0;
		int sum = 0;
		for(auto it:counter1)
		{
			ans += (it*sum);
			sum += it;
		}
		cout << max(1LL,ans) << endl;
	}
	else
	{
		// 2 centers
		int node = end2;
		given = z;
		while(z--)
		{
			node = par[node];
		}
		c1 = node;
		c2 = par[c1];
		// cout << c1 << " " << c2 << endl;
		
		dfs(c1,c2,0);
		dfs(c2,c1,0);

		int ans = 0;
		int sum = 0;
		for(auto it:counter1) sum += it;
		for(auto it:counter2) ans += (it*sum);

		cout << max(1LL,ans) << endl;
	}
	
}
void solve()
{
	cin >> n;	
	for(int i=0;i<n-1;i++)
	{
		int a,b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	diameter();
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