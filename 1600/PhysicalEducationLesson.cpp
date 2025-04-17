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
vector<int> factors(int k)
{
	vector<int> ans;
	for(int i=1;i*i<=k;i++)
	{
		if(k % i == 0)
		{
			ans.push_back(i);
			if(k/i != i) ans.push_back(k/i);
		}
	}
	return ans;
}
void solve()
{
	int p,k;
	cin >> p >> k;
	set<int> st;
	int p1 = p - k;
	int p2 = p + (k-2);
	int cnt = 0;
	// cout << p1 << " " << p2 << endl;
	for(auto it:factors(p1))
	{
		int m = p1/it;	
		// cout << m << " " << endl;	
		int l = m+2;
		if(l % 2 == 0 && l/2 >= k)
		{
			// cnt++;
			st.insert(l/2);
		}
	}
	for(auto it:factors(p2))
	{
		int m = p2/it;		
		int l = m+2;
		if(l % 2 == 0 && l/2 >= k)
		{
			// cnt++;
			st.insert(l/2);
		}
	}
	// cout << cnt << endl;
	cout << st.size() << endl;
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