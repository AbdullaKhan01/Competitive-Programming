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
const int inf = 1e18;
// vector<int> pref;
int dp[300300][11];
int rec(int level,int k){
	// pruning
	// base case
	if(level >= n) return 0;
	// cache check
	if(dp[level][k] != inf){
		return dp[level][k];
	}
	// compute 
	// we can we 0 to k transitions
	int op1 = rec(level+1,k);
	int ans = INT_MAX;
	for(int i=1;i<=k;i++){
		int mini = a[level];
		int sum = a[level];
		if(level + i < n){
			for(int j = 1;j <= i;j++){
				mini = min(mini,a[level + j]);
				sum += a[level + j];
			}
			//
			// decrease = sum - (i+1)*mini
			int decrease =  ((i+1) * mini) - sum;
			ans = min(ans,decrease + rec(level + i + 1,k - i)); 
		}
	}
	// save and return
	return dp[level][k] = min(op1,ans);
}
void solve()
{
	int k;
	cin >> n >> k;
	a.resize(n);
	for(int i=0;i<=n;i++){
		for(int j=0;j<11;j++){
			dp[i][j] = inf;
		}
	}
	// pref.resize(n);
	int sum = 0;
	for(int i=0;i<n;i++){
		cin >> a[i];
		sum += a[i];
	}
	int mini = rec(0,k);
	// cout << mini << endl;
	cout << sum + mini << endl;


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