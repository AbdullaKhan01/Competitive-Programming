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
string a,b;
int dp[41][41][41];
int rec(int l,int r,int i){
	int j = i + r - l;
	//base case
	if(l > r || i > j) return 0;
	if(l == r){
		return(a[l] == b[i]);
	}
	//cache check
	if(dp[l][r][i] != -1) return dp[l][r][i];
	//compute
		int ans = 0;
		if(a.substr(l,r - l + 1) == b.substr(i,j - i + 1)) ans = 1;
		else{
			// try to divide by some index
			for(int x = l ; x < r ; x++){
				// without swap
				ans |= rec(l,x,i) && rec(x+1,r,i+x-l+1);
				// with swap
				ans |= rec(l,x,j-x+l) && rec(x+1,r,i);
			}
		}
	//save and return
	return dp[l][r][i] = ans;
}
void solve()
{
	cin >> a >> b;
	memset(dp,-1,sizeof(dp));
	if(rec(0,a.size() - 1,0)){
		cout << "Yes" << endl;
	}
	else cout << "No" << endl;
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