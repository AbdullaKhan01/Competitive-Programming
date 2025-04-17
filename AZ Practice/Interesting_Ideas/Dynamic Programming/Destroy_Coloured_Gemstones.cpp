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
vector<int> a;
int dp[505][505];
int rec(int l,int r)
{
	//pruning
	// if(l > r) return 0;
	//base case
	if(l >= r)
	{
		return 1;
	}
	// cache check
	if(dp[l][r] != -1)
	{
		return dp[l][r];
	}
	// compute
	int ans = 1e9;
	int a1 = 1 + rec(l+1,r);
	int a2 = 1e9;
	if(a[l] == a[l+1]) a2 = 1 + rec(l+2,r);
	ans = min({ans,a1,a2});
	for(int mid=l+1;mid<=r;mid++)
	{
		if(a[l] == a[mid])
		{
			int cost = rec(l+1,mid-1);
			if(mid + 1 <= r)
				cost += rec(mid+1,r);
			ans = min(ans,cost);
		}
	}
	// save and return
	return dp[l][r] = ans;
}
void solve()
{
	cin >> n;
	a.resize(n);
	memset(dp,-1,sizeof(dp));
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
	}
	cout << rec(0,n-1) << endl;
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