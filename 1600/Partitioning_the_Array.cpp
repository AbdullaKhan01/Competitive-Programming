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
// VERDICT -> ACCEPTED
const int N = 2e5 + 1;
vector<int> factors(int n)
{
	vector<int> ans;
	for(int i=1;i*i<=n;i++)
	{
		if(n%i == 0)
		{
			ans.pb(i);
			if(n/i != i) ans.pb(n/i);
		}
	}
	sort(all(ans));
	return ans;
}
signed main(){
	fast_io();
    // precompute();
    // compute();
    ll tt;
    cin >> tt;
    while(tt--)
    {
        int n;
        cin >> n;
        int a[n];
        for(int i=0;i<n;i++)
        {
        	cin >> a[i];
        }
        int cnt = 0;
        for(int k=1;k<=n;k++)
        {
        	if(n%k == 0)
        	{
	        	int g = 0;
		    	for(int i=0;i+k<n;i++)
		        {
	        		g = __gcd(g,abs(a[i+k]-a[i]));
		        }
		        if(g != 1) cnt++;
		    }
        }
        cout << cnt << endl;
    }
    return 0;
}