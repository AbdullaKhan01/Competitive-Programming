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
// ll modAdd(ll a,ll b){
//     ll p = (a%mod + b%mod)%mod;
//     return p;
// }
// ll modSub(ll a,ll b){
//     ll p = (a%mod - b%mod)%mod;
//     if(p<0) p+=mod;
//     return p;
// }
// ll modMul(ll a,ll b){
//     ll p = (a%mod * b%mod)%mod;
//     return p;
// }
// void solve()
// {
// 	string s;
// 	cin >> s;
// 	string temp = "chokudai";
// 	map<char,pair<int,int>> mp;
// 	for(int i=1;i<8;i++)
// 	{
// 		mp[temp[i]] = {i,i-1};
// 	}
// 	vector<int> dp(8,0);
// 	for(int i=0;i<s.size();i++)
// 	{
// 		if(s[i] == 'c')
// 		{
// 			dp[0]++;
// 		}
// 		else
// 		{
// 			int curr = mp[s[i]].first;
// 			int prev = mp[s[i]].second;
// 			dp[curr] = modAdd(dp[curr],dp[prev]);
// 		}
// 	}
// 	cout << dp[7] << endl;

// }
// signed main(){
// 	fast_io();
//     int tt = 1;
//     // cin >> tt;
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
ll modAdd(ll a,ll b){
    ll p = (a%mod + b%mod)%mod;
    return p;
}
ll modSub(ll a,ll b){
    ll p = (a%mod - b%mod)%mod;
    if(p<0) p+=mod;
    return p;
}
ll modMul(ll a,ll b){
    ll p = (a%mod * b%mod)%mod;
    return p;
}
void solve()
{
	string s;
	cin >> s;
	int n = s.size();
	int ans = (s[0]-'0')%4 == 0;
	for(int i=1;i<n;i++)
	{
		int a = s[i] - '0';
		int b = stoll(s.substr(i-1,2));
		if(a % 4 == 0) ans++;
		if(b % 4 == 0) ans += i;
	}
	cout << ans << endl;	
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