#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
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
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
    tree_order_statistics_node_update>
    ordered_set;
/* 
for fast input output use printf and scanf;
*/
struct greet
{
	ordered_set g;

	void add(int l)
	{
		g.insert(l);
	}
	int ans(int end)
	{
		// no of elements <= end
		auto it = g.upper_bound(end);
		if(it == g.end()) 
			return g.size();
		else 
			return g.order_of_key(*it);
	}
};
signed main(){
	fast_io();
	ll tt;
	cin >> tt;
	while(tt--)
	{
	    int n;
	    cin >> n;
	    vector<pair<int,int>>a(n);
	    for(int i=0;i<n;i++)
	    {
	    	cin >> a[i].ff >> a[i].ss;
	    }
	    sort(all(a));
	    int k = 0;
	    greet gt;
	    for(int i=n-1;i>=0;i--)
	    {

	    	int e = a[i].ss;
	    	k += gt.ans(e);
	    	gt.add(e);
	    }
	    cout << k << endl;
	}
    return 0;
}