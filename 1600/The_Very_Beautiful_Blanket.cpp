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
int a[256][256];
void precompute()
{
	int n = 256;
	int m = 256;
	int idx = 0;
	for(int i=0;i<n;i+=2)
	{
		
		for(int j=0;j<m;j+=2)
		{
			a[i][j] = idx;
			a[i][j+1] = idx+1;
			a[i+1][j] = idx+2;
			a[i+1][j+1] = idx+3;
			idx+=4;
		}
	}
}
void solve()
{
	int n,m;
	cin >> n >> m;
	cout << n*m << endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}
signed main(){
	fast_io();
	precompute();
    int tt = 1;
    cin >> tt;
    while(tt--)
    {
    	solve();
    }
    return 0;
}