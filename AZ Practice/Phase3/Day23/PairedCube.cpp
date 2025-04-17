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

int N = 1e6+1;
int sp[1001000];
void init()
{
	for(int i=2;i<=N;i++)
	{
		sp[i] = i;
	}
	for(int i=2;i<=N;i++)
	{
		if(sp[i] == i) // that means its a prime
		{
			for(int j=2*i;j<=N;j+=i)
			{
				if(sp[j] == j)
				{
					sp[j] = i;
				}
			}
		}
	}
}
vector<int> primeFact(int x)
{
	vector<int> ans;
	while(x > 1)
	{
		ans.push_back(sp[x]);
		x /= sp[x];
	}
	return ans;
}
vector<pair<int,int>> getPrimeFact(int x)
{
	vector<pair<int,int>> ans;
	map<int,int> mp;
	vector<int> l = primeFact(x);
	for(auto it:l)
	{
		mp[it]++;
	}
	for(auto it:mp)
	{
		ans.push_back({it.first,it.second});
	}
	return ans;
}
bool isCube(int l)
{
	int mn = cbrt(l);
	if(mn * mn * mn == l) return 1;
	return 0;
}
void solve()
{
	int n;
	cin >> n;
	vector<int> a(n);
	int val = 0;
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
		val += a[i] == 1;
	}
	map<vector<pair<int,int>>,int>mp;
	int ans = 0;
	// cout << val << endl;
	for(int i=0;i<n;i++)
	{
		int e = a[i];
		if(isCube(e))
		{
			cout << val << endl;
			ans += 2*val;

		}
		vector<pair<int,int>> temp = getPrimeFact(e);

		vector<pair<int,int>> k;
		// cout << a[i] << endl;
		// for(auto it:temp) cout << it.first << ": " << it.second << " ";
		// for(auto it:temp) cout << it.first << ": " << it.second << " ";
		
		for(auto it:temp)
		{
			int a1 = it.first;
			int a2 = it.second;
			int want = (a2 % 3 == 0 ? 0 : 3 - a2 % 3);
			k.push_back({a1,want});
		}
		// cout << endl;
		// for(auto it:k) cout << it.first << ": " << it.second << " ";
		// cout << endl;
		if(mp[k] > 0)
		{
			// cout << a[i] << endl;
			ans += 2*mp[k];	
		}
		
		mp[temp]++;
	}
	cout << ans << endl;
}
signed main(){
	fast_io();
    int tt = 1;
    init();
    // cin >> tt;
    while(tt--)
    {
    	solve();
    }
    return 0;
}