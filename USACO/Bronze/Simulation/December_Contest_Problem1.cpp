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
	vector<int> c(4),a(4);
	for(int i=1;i<4;i++)
	{
		cin >> c[i] >> a[i];
	}
	for(int i=1;i<=100;i++)
	{
		int b1 = i % 3 == 0 ? 3: i%3;
		int b2 = (b1+1) % 3 == 0 ? 3 : (b1+1) % 3;

		
		int maxAdd = min(c[b2]-a[b2],a[b1]);
		// cout << b1 << " " << b2 << " " << maxAdd << endl;
		//increase amount and decrease amount
		a[b2] += maxAdd;
		a[b1] -= maxAdd;

		// for(int i=1;i<=3;i++)
		// {
		// 	cout << a[i] << " \n"[i+1==4];
		// }
	}
	for(int i=1;i<=3;i++)
	{
		cout << a[i] << "\n";
	}
}
signed main(){
	fast_io();
    solve();
    return 0;
}