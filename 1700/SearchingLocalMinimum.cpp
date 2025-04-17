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
int n;
int ask(int x)
{
	cout << "? " << x << endl;
	int a;
	cin >> a;
	return a;
}
void solve()
{
	cin >> n;
	if(n == 1)
	{
		cout << "! " << 1 << endl;
		return ;
	}
	int s = 1 , e = n;
	while(s <= e)
	{
		int mid = (s+e)/2;
		int a = ask(mid);
		int b;
		if(mid+1 <= n)
		{
			b = ask(mid+1);
		}
		else
		{
			b = ask(mid-1);
			swap(a,b);
		}
		if(a < b)
		{
			e = mid-1;
		}
		else
		{
			s = mid+1; 
		}
	}
	cout << "! " << min(s,n) << endl;
}
signed main(){
	fast_io();
    int tt = 1;
    // cin >> tt;
    while(tt--)
    {
    	solve();
    }
    return 0;
}