// #include<bits/stdc++.h>
// #define mod 1000000007
// #define mod2 998244353
// #define ceil(a,b) ((a+b-1)/b)
// #define floor(a,b)((a-b+1)/b)
// #define fast_io() ios::sync_with_stdio(0);cin.tie(0);
// #define ll long long
// #define int long long
// #define vi vector<int>
// #define all(x) (x).begin(),(x).end()
// #define rall(x) (x).rbegin(),(x).rend()
// #define input(x) for(auto &a:x) cin >> a;
// #define output(x) for(auto a:x) cout << a <<" ";
// #define rep(i,a,n) for(int i=(a);i<n;i++)
// #define pb push_back
// #define ppb pop_back
// #define pf push_front
// #define ppf pop_front
// #define ff first
// #define ss second
// #define si set<int>
// #define pii pair<int,int>
// #define mii map<int,int>
// #define msi map<string,int>
// #define yes "YES"
// #define no "NO"
// #define endl '\n'
// using namespace std; 
// /* 
// for fast input output use printf and scanf;
// */
// const int inf = 100;
// void solve()
// {
// 	string s;
// 	cin >> s;
// 	int n = s.size();
// 	int r = -inf;
// 	bool flag = true;
// 	for(int i=0;i<n;i++)
// 	{
// 		if(s[i] == '.') continue;
// 		int num = s[i] - '0';
// 		int left = max(0LL,i-num);
// 		int right = min(n-1,i+num);
// 		if(left <= r)
// 		{
// 			flag = false;
// 			break;
// 		}
// 		else r = right;
// 	}
// 	if(flag)
// 	{
// 		cout << "safe" << endl;
// 	}
// 	else
// 	{
// 		cout << "unsafe" << endl;
// 	}
// }
// signed main(){
// 	fast_io();
//     int tt = 1;
//     cin >> tt;
//     while(tt--)
//     {
//     	solve();
//     }
//     return 0;
// }

// #include<bits/stdc++.h>
// #define mod 1000000007
// #define mod2 998244353
// #define ceil(a,b) ((a+b-1)/b)
// #define floor(a,b)((a-b+1)/b)
// #define fast_io() ios::sync_with_stdio(0);cin.tie(0);
// #define ll long long
// #define int long long
// #define vi vector<int>
// #define all(x) (x).begin(),(x).end()
// #define rall(x) (x).rbegin(),(x).rend()
// #define input(x) for(auto &a:x) cin >> a;
// #define output(x) for(auto a:x) cout << a <<" ";
// #define rep(i,a,n) for(int i=(a);i<n;i++)
// #define pb push_back
// #define ppb pop_back
// #define pf push_front
// #define ppf pop_front
// #define ff first
// #define ss second
// #define si set<int>
// #define pii pair<int,int>
// #define mii map<int,int>
// #define msi map<string,int>
// #define yes "YES"
// #define no "NO"
// #define endl '\n'
// using namespace std; 
// /* 
// for fast input output use printf and scanf;
// */
// void solve()
// {
// 	int n;
// 	cin >> n;
// 	map<string,pair<int,int>>mp;
// 	for(int i=0;i<n;i++)
// 	{
// 		string s;int a;
// 		cin >> s >> a;
// 		if(a == 0) mp[s].first++;
// 		else mp[s].second++;
// 	}
// 	int ans = 0;
// 	for(auto it:mp)
// 	{
// 		ans += max(it.second.first,it.second.second);
// 	}
// 	cout << ans << endl;
// }
// signed main(){
// 	fast_io();
//     int tt = 1;
//     cin >> tt;
//     while(tt--)
//     {
//     	solve();
//     }
//     return 0;
// }

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
	vector<int> a;
	multiset<int> ms;
	for(int i=0;i<n;i++)
	{
		int x;cin >> x;
		if(x <= k) a.pb(x);
		else ms.insert(x);
	}
	while(ms.size() >= 2)
	{
		int u = *ms.begin();
		ms.erase(ms.find(u));
		int v = *ms.begin();
		ms.erase(ms.find(v));

		int quo = u - k;
		a.pb(k);
		int nv = v - quo;
		if(nv <= k) a.pb(nv);
		else ms.insert(nv);
	}
	int ans = 0;
	for(auto it:ms) a.push_back(it);
	for(auto it:a) ans += it;
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