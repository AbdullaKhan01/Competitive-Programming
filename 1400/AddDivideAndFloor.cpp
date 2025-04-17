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
VERDICT -> ACCEPTED
*/
signed main(){
	fast_io();
	ll tt;
	cin >> tt;
	while(tt--)
	{
	    int n;
	    cin >> n;
	    vi arr(n);
	    input(arr);
	    if(n == 1)
	    {
	    	cout << 0 << endl;
	    	continue;
	    }
	    int a = *min_element(all(arr));
	    int b = *max_element(all(arr));

	    // int x = a,y = b;
	    if(a == b)
	    {
	    	cout << 0 << endl;
	    	continue;
	    }
	    vi ans;
	    // vi ans2;
	    while(b > a)
	    {
	    	b = (a+b) / 2;
	    	ans.push_back(a);
	    }
	    // ans.pb(b%2 == 0?1:2);
	    cout << ans.size() << endl;
	    if(ans.size() <= n)
	    {
	    	output(ans);
	    	cout << endl;
	    }
	}
    return 0;
}