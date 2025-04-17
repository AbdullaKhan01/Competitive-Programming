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
	int a = 0;
	int b,c,d;
	cin >> b >> c >> d;
	for(int i=0;i<62;i++)
	{
		bool bit_d = d & (1LL << i);
		bool bit_c = c & (1LL << i);
		bool bit_b = b & (1LL << i);

		if(bit_d == 1)
		{
			if(bit_b == 0 && bit_c == 1)
			{
				break;
			}
			if(bit_b == 0 && bit_c == 0)
			{
				a |= (1LL << i);
			}
		}	
		if(bit_d == 0)
		{

			if(bit_b == 0 && bit_c == 1)
			{
				a |= (1LL << i);
			}
			if(bit_b == 1 && bit_c == 1)
			{
				a |= (1LL << i);
			}
			if(bit_b == 1 && bit_c == 0)
			{
				break;
			}
		}	
	}
	if(a >= 0 && a <= (1LL<<61) && (((a | b ) - (a & c)) == d))
	{
		cout << a << endl;
	}
	else
	{
		cout << -1 << endl;
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