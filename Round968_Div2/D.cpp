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
int sum(int n)
{
	return (n * (n+1)) / 2;
}
void solve()
{
	int n,m;
	cin >> n >> m;
	vector<set<int>>a(n);
	for(int i=0;i<n;i++)
	{
		int tt;
		cin >> tt;
		set<int> st;
		while(tt--)
		{
			int x;
			cin >> x;
			a[i].insert(x);
		}
	}
	multiset<int> ms;
	for(int i=0;i<n;i++)
	{
		set<int> gg = a[i];
		int k = a[i].size();
		vector<int> gap;
		for(int i=0;i<=k+2;i++)
		{
			if(gg.find(i) == gg.end())
			{
				gap.push_back(i);
			}
		}
		for(int i=0;i<2;i++)
		{
			cout << gap[i] << " ";
		}
		cout << endl;
		ms.insert(gap[1]);
	}
	for(auto it:ms)
	{
		cout << it << " ";
	}
	cout << endl;
	int i=0;
	int ans = 0;
	while(i <= m && !ms.empty())
	{
		auto it = ms.rbegin();
		if(i > *it)
		{
			ans += *it;
			ms.erase(ms.find(*it));
			i++;
		}
		else break;
	}
	if(i <= m)
	{
		ans += sum(m) - sum(i-1);	
	}
	
	cout << ans << endl;
}
signed main(){
	fast_io();
    ll tt;
    cin >> tt;
    while(tt--)
    {
        solve();
    }
    return 0;
}