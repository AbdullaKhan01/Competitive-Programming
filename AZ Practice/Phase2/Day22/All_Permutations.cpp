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
vector<vector<int>> ans;
vector<int> curr;
map<int,int> mp;
int n,k;
void rec(int level)
{
	// make permutation for level from level to n
	// given that permutation for 0 to level is already made
	// base case
	if(level == n)
	{
		ans.pb(curr);
		return ;
	}

	// level == curr map element

	// choices -> all elements in map with frequency > 0
	for(auto it:mp)
	{
		if(it.second)
		{
			// no check everything is fine
			// take it
			mp[it.first]--;
			curr.push_back(it.first);
			rec(level+1);
			curr.pop_back();
			mp[it.first]++;
		}
	}
}
int fact(int n)
{
	int a = 1;
	for(int i=1;i<=n;i++)
	{
		a *= i;
	}
	return a;
}
void solve()
{

	cin >> n >> k;
	k--;
	for(int i=1;i<=n;i++)
	{
		mp[i]++;
	}
	rec(0);
	output(ans[k]);

}
signed main(){
	fast_io();
    int tt = 1;
    // cin >> tt;
    while(tt--)
    {
    	// solve();
    	cout << fact(13) << endl;
    }
    return 0;
}