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
vector<string> a;
int n;
int dp[100100][3];

// 2 means same
// 1 means i+1
// 0 means i-1

int votes(char a,char b,char c)
{
	int tot = (a=='A') + (b == 'A') + (c == 'A');
	return tot >= 2;
}


int rec(int i,int aage)
{
	//pruning 
	//base case
	if(i >= n) return 0;
	// cache check
	if(dp[i][aage] != -1)
	{
		return dp[i][aage];
	}
	// compute

	// there can be 5 options
	int op1 = 0 , op2 = 0 , op3 = 0;
	int op4 = 0 , op5 = 0;

	if(aage == 2)
	{
		//op1 * 
		//    **
		int m1 = votes(a[0][i],a[1][i],a[1][i+1]);
		int m4 = votes(a[0][i],a[0][i+1],a[1][i]);
		op1 = m1 + rec(i+1,1);
		op4 = m4 + rec(i+2,0);
	}
	int s = (aage == 2 ? 0 : aage == 1 ? 1 : -1);
	if(i+2 < n && i+2+s < n)
	{
		int m21 = votes(a[0][i],a[0][i+1],a[0][i+2]);
		int idx = i + s;
		int m22 = votes(a[1][idx],a[1][idx+1],a[1][idx+2]);
		int tot = m21 + m22;
		op2 = tot + rec(i+3,aage);
	}

	if(aage == 1 && i+1 < n)
	{
		int m3 = votes(a[0][i],a[0][i+1],a[1][i+1]);
		op3 = m3 + rec(i+2,2);
	}

	if(aage == 0)
	{

		int m5 = votes(a[0][i],a[1][i],a[1][i-1]);
		op5 = m5 + rec(i+1,2);
	}

	int ans = max({op1,op2,op3,op4,op5});
	// save and return
	return dp[i][aage] = ans;
}
void solve()
{
	cin >> n;
	a.resize(n);
	for(int i=0;i<2;i++)
	{
		cin >> a[i];
	}
	memset(dp,-1,sizeof(dp));
	cout << rec(0,2) << endl;
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