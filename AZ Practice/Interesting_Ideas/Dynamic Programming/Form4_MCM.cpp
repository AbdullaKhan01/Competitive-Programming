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
// Matrix Chain Multiplication

int n;
int x[101],y[101];

int dp[101][101];
int back[101][101];
int rec(int l,int r)
{
	// base case
	if(l == r) 
	{
		return 0;
	}
	// cache check
	if(dp[l][r] != -1)
	{
		return dp[l][r];
	}
	// compute
	int ans = 1e9;
	for(int mid=l;mid<r;mid++)
	{
		// ans = min(ans,rec(l,mid) + rec(mid+1,r) + x[l] * y[mid] * y[r]);
		int cost = rec(l,mid) + rec(mid+1,r) + x[l] * y[mid] * y[r];
		if(cost < ans)
		{
			ans = cost;
			back[l][r] = mid;
		}
	}
	// save and return
	return dp[l][r] = ans;
}
int open_bracket[101];
int close_bracket[101];	
void generate(int l,int r)
{
	if(l == r) return ;

	int mid = back[l][r];

	open_bracket[l]++;
	close_bracket[r]++;
	generate(l,mid);
	generate(mid+1,r);
}
void solve()
{
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> x[i] >> y[i];
	}
	memset(dp,-1,sizeof(dp));
	// if cost could have been negative
	// then we would had to have another 
	// boolean array saved which tells us that 
	// is the position saved or not
	cout << rec(1,n) << endl;
	generate(1,n);
	for(int i=1;i<=n;i++)
	{
		for(int x=0;x<open_bracket[i];x++)
		{
			cout << "(";
		}
		cout << i << "";
		for(int x=0;x<close_bracket[i];x++)
		{
			cout << ")";
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