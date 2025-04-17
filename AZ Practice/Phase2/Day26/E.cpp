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

void fill(vector<int> &a)
{
	for(int i=0;i<26;i++) a[i] = 0;
}
int amp(string s)
{
	int n = s.size();
	vector<vector<int>>prefOdd(n+1,vector<int>(26,0));
	vector<vector<int>>prefEven(n+1,vector<int>(26,0));
	vector<vector<int>>suffOdd(n+1,vector<int>(26,0));
	vector<vector<int>>suffEven(n+1,vector<int>(26,0));
	vector<int> prev(26,0);
	for(int i=1;i<=n;i+=2)
	{	
		char ch = s[i-1];
		prefOdd[i] = prev;
		prefOdd[i][ch-'a']++;
		prev = prefOdd[i];
	}
	fill(prev);
	for(int i=2;i<=n;i+=2)
	{
		char ch = s[i-1];
		prefEven[i] = prev;
		prefEven[i][ch-'a']++;
		prev = prefEven[i];
	}
	fill(prev);
	for(int i=n;i>=1;i-=2)
	{
		char ch = s[i-1];
		suffOdd[i] = prev;
		suffOdd[i][ch-'a']++;
		prev = suffOdd[i];
	}

	fill(prev);
	for(int i=n-1;i>=1;i-=2)
	{
		char ch = s[i-1];
		suffEven[i] = prev;
		suffEven[i][ch-'a']++;
		prev = suffEven[i];
	}

	int l = (n-1)/2;
	int ans = INT_MAX;
	for(int i=1;i<=n;i++)
	{
		// removing the ith character
		vector<int> a(26,0) , b(26,0) , c(26,0) , d(26,0);
		
		if(i % 2 == 0)
		{
			// even
			if(i - 2 >= 0) a = prefEven[i-2];
			if(i + 1 <= n) b = suffOdd[i+1];
			if(i - 1 >= 0) c = prefOdd[i-1];
			if(i + 2 <= n) d = suffEven[i+2];
		}
		else
		{
			// odd
			if(i - 2 >= 0) a = prefOdd[i-2];
			if(i + 1 <= n) b = suffEven[i+1];
			if(i - 1 >= 0) c = prefEven[i-1];
			if(i + 2 <= n) d = suffOdd[i+2];
		}

		int g = 0;
		int p = 0;
		for(int i=0;i<26;i++)
		{
			p = max(p,a[i] + b[i]);
		}
		g += l - p;
		p = 0;
		for(int i=0;i<26;i++)
		{
			p = max(p,c[i] + d[i]);
		}
		g += l - p;

		ans = min(ans,1 + g);
	}
	return ans;
}
void solve()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	if(n % 2 == 0)
	{
		map<int,int> mp;
		int ans = 0;
		for(int i=0;i<n;i+=2) mp[s[i]]++;
		int p = 0;
		for(auto it:mp) p = max(p,it.second);
		
		ans += n/2 - p;

		mp.clear();
		for(int i=1;i<n;i+=2) mp[s[i]]++;
		p = 0;
		for(auto it:mp) p = max(p,it.second);
		ans += n/2 - p;

		cout << ans << endl;
	}
	else
	{
		// cout << "doing" << endl;
		if(n == 1)
		{
			cout << 1 << endl;
			return ;
		}
		cout << amp(s) << endl;
	}
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