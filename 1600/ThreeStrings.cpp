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
const int inf = 1e9;
string a,b,c;
int dp[2002][2002];
int rec(int i,int j)
{
	//pruning
	if(i > a.size() || j > b.size()) return inf;
	//base case
	if(i == a.size() && j == b.size()) return 0;
	//cache check
	if(dp[i][j] != -1) return dp[i][j];
	//compute 
	int op1,op2,op3,op4;
	op1=op2=op3=op4=inf;
	if(c[i+j] == a[i]){
		op1 = rec(i+1,j);
	}
	if(c[i+j] == b[j]){
		op2 = rec(i,j+1);
	}
	op3 = 1 + rec(i+1,j);
	op4 = 1 + rec(i,j+1);
	//save and return
	return dp[i][j] = min({op1,op2,op3,op4});
}
void solve()
{
	cin >> a >> b >> c;
	// cout << a << b << c << endl;
	for(int i=0;i<=a.size();i++){
		for(int j=0;j<=b.size();j++){
			dp[i][j] = -1;
		}
	}
	cout << rec(0,0) << endl;
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