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
	int n,k;
	cin >> n >> k;
	vector<int> a(n);
	vector<int> f(k+1,0);
	set<int> st;
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
		st.insert(a[i]);
		if(a[i] < k) f[a[i]]++;
	}
	sort(all(a));
	bool flag = true;
	for(int i=1;i<k;i++)
	{
		int it = i;
		// some no of factorials are present
		int next = it + 1;
		if(f[it] % next != 0)
		{
			flag = false;
			break;
		}
		else
		{
			f[next] += (f[it]/next);
		}
	}
	cout << (flag ? "Yes" : "No") << endl;
}
signed main(){
	fast_io();
    int tt = 1;
    // cin >> tt;
    while(tt--)
    {
    	solve();
    }
    return 0;
}