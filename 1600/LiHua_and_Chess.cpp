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
// #define endl '\n'
using namespace std; 
/* 
for fast input output use printf and scanf;
*/
int ask(int a,int b)
{
	cout << "? " << a << " " << b << endl;
	int p;cin >> p;
	return p;
}
void out(int a,int b)
{
	cout << "! " << a << " " << b << endl;
}
void solve()
{
	int n,m;
	cin >> n >> m;
	int g = ask(1,1);g++;
	int k = 1e9;
	int l = 1e9;
	if(g <= m) k = ask(1,g);
	if(g <= n) l = ask(g,1);
	if(k <= l)
	{
		out(1+k,g);
	}
	else 
	{
		out(g,l+1);
	}
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