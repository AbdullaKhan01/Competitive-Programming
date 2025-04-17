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
	int n,q;
	cin >> n >> q;
	vi a(n);
	input(a);
	// we want to utilize the IQ optimally so 
	// we assume that in the ending point our 
	// IQ becomes 0 this means we have optimally 
	// used the IQ otherwise if some IQ is left then 
	// maybe it could have been used to test some contest
	// which may increase our answer

	// now consider the situation in reverse order
	// our IQ can increase uptil q

	// so if a[i] <= IQ then just test it

	// if a[i] > Q then we can either test this contest
	// and increase our IQ only if IQ+1 <= q;

	int iq = 0;
	string ans(n,'0');
	for(int i=n-1;i>=0;i--)
	{
		if(a[i] <= iq)
		{
			ans[i] = '1';
		}
		else
		{
			// a[i] > iq
			if(iq < q)
			{
				ans[i] = '1';
				iq++;
			}
		}
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