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
void solve()
{
	// so the problem just asks us to generate the
	// nth row of the pascal triangle which is a known
	// thing

	// nth row = nC0 nC1 nC2 nC3 nC4 
	// but we cannot generate these numbers as they 
	// can be large we just want the parity of the numbers
	// of the nth row

	// so if we can just determine the parity of any 
	// ncr then we can solve the problem

	// so ncr = n!/r! * n-r! 
	// if we cancel n-r! from above and below for eg
	// n! = n * n-1 * n-2 * ... * n-r!

	// so we have to determine parity of n*n-1*n-2*.../r!

	// since any dividing by 
	
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