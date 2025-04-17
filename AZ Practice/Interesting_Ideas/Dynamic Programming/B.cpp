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
	int n,m;
	cin >> n >> m;
	if(n == 1 && m == 1)
	{
		cout << 1 << endl;
		cout << 1 << endl;
		return ;
	}
	{
		int a = n - m;
		int b = m - 1;
		int f = a % 2;
		int fs = b % 2;
		if(a!=0 && b!=0 && f == fs)
		{
			if(f == 0)
			{
				int m1 = (1 + m) / 2;
				int m2 = (n + m) / 2;
				cout << 5 << endl;
				cout << 1 << " " << m1 << " " << m << " " << m+1 << " " << m2+1 << endl; 	
			}
			else
			{
				cout << 3 << endl;
				cout << 1 << " " << m << " " << m+1 << endl;
			}
		}
		else cout << -1 << endl;
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