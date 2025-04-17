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
const int inf = 6 * 1e18;

int add(int n,int pos)
{
	while(1LL & (n >> pos))
	{
		// n &= ~(1 << pos); 
		pos++;
	}
	for(int i=0;i<pos;i++)
	{
		n &= ~(1LL << i);
	}
	int k = n | (1LL << pos);
	
	return k;
}
void solve()
{
	int n,x;
	cin >> n >> x;
	int left = n , right = inf;
	for(int i=0;i<63;i++)
	{
		// all the bits
		int n_bit = 1 & (n >> i);
		int x_bit = 1 & (x >> i);

		if(n_bit == 0 && x_bit == 0) continue;
		if(n_bit == 0 && x_bit == 1)
		{
			cout << -1 << endl;
			return ;
		}
		if(n_bit == 1)
		{
			// we have to do something
			int g = add(n,i);
			if(x_bit == 0)
			{
				// greater than equal to 
				left = max(left,g);
			}
			else
			{
				// x_bit is 1
				// less than equal to 
				right = min(right,g-1);
			}
		}
	}
	if(left <= right)
	{
		cout << left << endl;
	}
	else
	{
		cout << -1 << endl;
	}
}
void helper(int a,int b)
{
	int ans = a;
	for(int i=a;i<=b;i++)
	{
		ans &= i;
	}
	cout << ans << endl;
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