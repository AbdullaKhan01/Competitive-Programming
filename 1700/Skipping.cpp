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
vector<int> a,b;
set<int> st;
int dp[400400];
int rec(int i){
	if(i < 0) return 0;
	// max answer starting from the level i
	//pruning 
	//base case
	//cache check
	if(dp[i] != -1) return dp[i];
	//compute
	// take or not take
	int take = 0 , notTake = 0;	
	st.erase(i);
	auto it = st.upper_bound(b[i]);
	// cout << i << "ok" << *it << endl;
	if(it != st.begin()){
		it--;
		notTake = rec(*it);
	}
	take = a[i];
	if(i == 0 || st.count(i - 1))
		take += rec(i-1);
	// st.insert(i);
	return dp[i] = max(take,notTake);
}
void solve()
{
	cin >> n;
	a.resize(n);
	b.resize(n);
	for(int rep=0;rep<2;rep++)
	for(int i=0;i<n;i++){
		st.insert(i);
		cin >> ((rep==0)?a[i]:b[i]);
		if(rep == 1) b[i]--;
	}
	for(int i=0;i<=n;i++)
	{
		dp[i] = -1;
	}
	cout << rec(0) << endl;
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