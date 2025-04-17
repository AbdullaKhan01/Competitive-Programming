// // 4 7 5 1 2 6 3
// 	// 6 2 1 4 7 3 5

// 	// 1 2 3 4 5
// 	// 3 5 4 2 1
// 	// (1,1) (1,2) (1,3) (1,4) (1,5) - 1
// 	// (2,2) (2,3) (2,4) (2,5) - 0
// 	// (3,3) (3,4) (3,5) - 0
// 	// (4,4) (4,5) - 0
// 	// (5,5) - 0


// 	// (1,5) -> good

// 	// 1 4 5
// 	// 1-4 * 1-5 * 4-5 

// 	// 3 * 4 * 1

// 	// 1 4 9
// 	// 4-1 * 9-4 * 9-1
// 	// 3 * 5 * 8 
// 	// 15 * 8 = 120 % 7 = 

// 	// every number will be multiplied by the abs diff of 
// 	// all the elements previous to it

// 	// a b c

// 	// a b c d
// 	// b-a * c-b * c-a * d-c * d-b * d-a

// 	// ddd - dda - dbd + dba - dcd + dca + cbd - cba  

// 	// ddd - dd(a-b-c) + d(ab+bc+ca) - cba

// 	// cc - bc - ac + ab
// 	// cc - c(b + a) + ab

// 	// b-a * c-b * c-a 9-4 * 9-1 =  	
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
void solve3(int n,string s,int st,vector<int>&ans)
{
	if(n == 0)
	{
		ans.push_back(stoll(s));
		return ;
	}
	for(int i=st;i<=9;i++)
	{
		s.push_back(i + 48);
		solve3(n-1,s,i,ans);
		s.pop_back();
	}
}
void solve2()
{
	int n;
	cin >> n;
	vector<int> a(n);
	map<int,int> mp;
	int sum = 0;
	int g = -1;
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
		sum += a[i];
		mp[a[i]] = 1;
	}
	for(int i=0;i<n;i++)
	{
		int n_sum = sum - a[i];
		if(n_sum % 2 != 0) continue;
		int finder = n_sum / 2;
		if(mp.find(finder) != mp.end())
		{
			// cout << a[i] << endl;
			g = max(g,a[i]);
		}
	}
	cout << g << endl;
}
void solve()
{

	int n,x;
	cin >> n >> x;
	int cost[n];
	for(int i=0;i<n;i++)
	{
		cin >> cost[i];
	}
	map<int,int> mp;
	int cnt = 0;
	for(int i=0;i<n;i++)
	{
		int finder = x - (cost[i]%x);
		cnt += mp[finder];
		mp[cost[i]%x]++;
	}
	cout << cnt << endl;
}

signed main(){
	fast_io();
	vector<int> ans;
	for(int i=1;i<10;i++)
	{
		solve3(i,"",1,ans);
	}
	cout << ans.size() << endl;
    return 0;
}