#include<bits/stdc++.h>
#define mod 1000000007
#define mod2 998244353
#define ceil(a,b) ((a+b-1)/b)
#define floor(a,b)((a-b+1)/b)
#define fast_io() ios::sync_with_stdio(0);cin.tie(0);
#define ll long long
// #define int long long
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
// This is an interactive problem
void solve()
{
	int n;
	cin >> n;
	auto ask = [&](int l,int r)
	{
		cout << "? " << l << " " << r << endl;
		int p;cin >> p;
		return p;
	};

	string ans(n,'0');
	int flag = false;
	int j = 1;
	int prev = 0;
	while(j < n)
	{
		j++;
		int v = ask(1,j);
		if(flag)
		{
			// answer is non zero
			if(v == prev) ans[j-1] = '0';
			else ans[j-1] = '1';
			prev = v;
		}
		else
		{
			if(v != 0)
			{
				flag = true;
				ans[j-1] = '1';
				for(int i=0;i<j-1;i++)
				{
					if(i >= j-1-v) ans[i] = '0';
					else ans[i] = '1';
				}
				prev = v;
			}
			else continue;
		}
	}
	if(flag == false)
	{
		cout << "! IMPOSSIBLE" << endl;
	}
	else cout << "! " << ans << endl;

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