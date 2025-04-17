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
const int N = 4e4+1;
vector<vector<int>> dp(500,vector<int>(N+1));
vector<int> pal;
void generate()
{
	for(int i=1;i<N;i++)
	{
		string s = to_string(i);
		string p = s;
		reverse(all(p));
		if(s == p)
		{
			pal.pb(i);
		}
	}
}
ll modAdd(ll a,ll b){
    ll p = (a%mod + b%mod)%mod;
    return p;
}
ll modSub(ll a,ll b){
    ll p = (a%mod - b%mod)%mod;
    if(p<0) p+=mod;
    return p;
}
ll modMul(ll a,ll b){
    ll p = (a%mod * b%mod)%mod;
    return p;
}
int f(int ind,int T,vector<int>&arr)
{
	if(ind == 0)
	{
		return !(T%arr[0]);
	}
	int notTake = f(ind-1,T,arr);
	int take = 0;
	if(arr[ind] <= T) take = f(ind,T-arr[ind],arr);
	return notTake + take;
}
int mem(int ind,int T)
{
	if(ind == 0)
	{
		return !(T%pal[0]);
	}
	int notTake = mem(ind-1,T);
	int take = 0;
	if(pal[ind] <= T) take = mem(ind,T-pal[ind]);
	return dp[ind][T] = modAdd(notTake,take);
}
int tab(int n,int val)
{
	for(int T=1;T<=val;T++)
	{
		dp[0][T] = (T % pal[0] == 0);
	}
	for(int idx=1 ; idx < n ; idx++)
	{
		for(int T=1;T<=val;T++)
		{
			int notTake = dp[idx-1][T];
			int take = 0;
			if(pal[idx] <= T) take = dp[idx][T-pal[idx]];
			dp[idx][T] = modAdd(take,notTake);
		}
	}
	return dp[n-1][val];
}
signed main(){
	fast_io();
	generate();
  	// cout << pal.size() << endl;
  	// int n = pal.size();
  	// for(int i=1;i<N;i++)
  	// {
  	// 	mem(n-1,i);
  	// }
  	ll tt;
  	cin >> tt;
  	while(tt--)
  	{
  	    int T;
  	    cin >> T;
  	    cout << tab(pal.size(),T) << endl;
  	}
    return 0;
}