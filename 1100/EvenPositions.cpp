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
	int n;
	cin >> n;
	string s;
	cin >> s;
	// if get's closed then close it

	// _(_)_)
	// (_)_

	int ans = 0;
	vector<pair<char,int>> st;
	for(int i=0;i<n;i++)
	{
		if(s[i] == '(') st.push_back({'(',i});
		else if(s[i] == ')')
		{
			ans += (i - st.back().second);
			st.pop_back();
		}
		else
		{

		}
	}
	cout << ans << endl;
    // 


	// (_())_)
}
signed main(){
	fast_io();
    ll tt;
    cin >> tt;
    while(tt--)
    {
        solve();

        // 1 2 3 4 5 6
        // 1 
        // 1 2 
        // 1 3 
        // 1 
    }
    return 0;
}