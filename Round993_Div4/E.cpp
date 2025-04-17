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
	int k,l1,r1,l2,r2;
	cin >> k >> l1 >> r1 >> l2 >> r2;
	vector<int> a;
	int maxi = 2e9;
	int g = 1;
	while(g <= maxi)
	{	
		a.push_back(g);
		g *= k;	
	}
	int ans = 0;
	for(int i=0;i<(int)a.size();i++){
		int val = a[i];
		int gg = r2/val;
		int tt = ceil(l2,val);
		int p = min(r1,gg);
		int q = max(tt,l1);
		ans+= max(0LL,(p-q+1));
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