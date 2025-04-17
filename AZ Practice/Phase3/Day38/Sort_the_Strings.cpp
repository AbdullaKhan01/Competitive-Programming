// // #include<bits/stdc++.h>
// // #define mod 1000000007
// // #define mod2 998244353
// // #define ceil(a,b) ((a+b-1)/b)
// // #define floor(a,b)((a-b+1)/b)
// // #define fast_io() ios::sync_with_stdio(0);cin.tie(0);
// // #define ll long long
// // #define int long long
// // #define vi vector<int>
// // #define all(x) (x).begin(),(x).end()
// // #define rall(x) (x).rbegin(),(x).rend()
// // #define input(x) for(auto &a:x) cin >> a;
// // #define output(x) for(auto a:x) cout << a <<" ";
// // #define rep(i,a,n) for(int i=(a);i<n;i++)
// // #define pb push_back
// // #define ppb pop_back
// // #define pf push_front
// // #define ppf pop_front
// // #define ff first
// // #define ss second
// // #define si set<int>
// // #define pii pair<int,int>
// // #define mii map<int,int>
// // #define msi map<string,int>
// // #define yes "YES"
// // #define no "NO"
// // #define endl '\n'
// // using namespace std; 
// // /* 
// // for fast input output use printf and scanf;
// // */
// // const int inf = 1e18;
// // int n;
// // vector<string> a;
// // vector<string> rev;
// // int c[100100];
// // int ld[100100][2][2];
// // int dp[100100][2];
// // int rec(int level,int flag)
// // {
// // 	//base case
// // 	if(level == n) return 0;

// // 	//cache check

// // 	// compute
// // 	// level is the index and flag denotes if the last string
// // 	// is reversed or not

// // 	// compare it with the level - 1 th string
// // 	int ans = inf;
// // 	if(ld[level][0][flag])
// // 	{
// // 		// can go to next level by either not reversing
// // 		// the current string or by reversing the current
// // 		// string
// // 		ans = rec(level+1,0);
// // 	}
// // 	if(ld[level][1][flag])
// // 	{
// // 		ans = min(ans,c[level] + rec(level+1,1));
// // 	}
// // 	// save and return
// // 	return dp[level][flag] = ans;
// // }
// // void solve()
// // {
// // 	cin >> n;
// // 	for(int i=0;i<n;i++)
// // 	{
// // 		cin >> c[i];
// // 	}
// // 	a.resize(n);
// // 	rev.resize(n);
// // 	for(int i=0;i<n;i++)
// // 	{
// // 		cin >> a[i];
// // 		rev[i] = a[i];
// // 		reverse(all(rev[i]));
// // 	}
// // 	for(int i=1;i<n;i++)
// // 	{
// // 		ld[i][0][0] = (a[i] > a[i-1]);
// // 		ld[i][0][1] = (a[i] > rev[i-1]);
// // 		ld[i][1][0] = (rev[i] > a[i-1]);
// // 		ld[i][1][1] = (rev[i] > rev[i-1]);
// // 	}
// // 	for(int i=0;i<=n;i++)
// // 	{
// // 		dp[i][0] = -1;
// // 		dp[i][1] = -1;
// // 	}
// // 	// cout << ld[1][]
// // 	// cout << rec(1,0) << endl;
// // 	// cout << c[0] + rec(1,1) << endl;
// // 	int ans = min(rec(1,0),c[0] + rec(1,1));
// // 	if(ans == inf)
// // 	{
// // 		cout << -1 << endl;
// // 	}
// // 	else
// // 	{
// // 		cout << ans << endl;
// // 	}
// // }
// // signed main(){
// // 	fast_io();
// //     int tt = 1;
// //     cin >> tt;
// //     while(tt--)
// //     {
// //     	solve();
// //     }
// //     return 0;
// // }


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
// const int inf = 1e18;
// int n;
// vector<string> a;
// vector<string> rev;
// int c[100100];
// int dp[100100][2];
// int rec(int level,int flag)
// {
// 	//base case
// 	if(level == n) return 0;

// 	//cache check
// 	if(dp[level][flag] != -1)
// 	{
// 		return dp[level][flag];
// 	}
// 	// compute
// 	// level is the index and flag denotes if the last string
// 	// is reversed or not

// 	// compare it with the level - 1 th string
// 	string temp;
// 	if(flag) temp = rev[level-1];
// 	else temp = a[level-1];

// 	string s = a[level];
// 	string t = rev[level];
// 	int ans = inf;
// 	if(temp <= s)
// 	{
// 		// can go to next level by either not reversing
// 		// the current string or by reversing the current
// 		// string
// 		ans = rec(level+1,0);
// 	}
// 	if(temp <= t)
// 	{
// 		ans = min(ans,c[level] + rec(level+1,1));
// 	}
// 	// save and return
// 	return dp[level][flag] = ans;
// }
// void solve()
// {
// 	cin >> n;
// 	for(int i=0;i<n;i++)
// 	{
// 		cin >> c[i];
// 	}
// 	a.resize(n);
// 	rev.resize(n);
// 	for(int i=0;i<n;i++)
// 	{
// 		cin >> a[i];
// 		rev[i] = a[i];
// 		reverse(all(rev[i]));
// 	}
// 	for(int i=0;i<=n;i++)
// 	{
// 		dp[i][0] = -1;
// 		dp[i][1] = -1;
// 	}
// 	int ans = min(rec(1,0),c[0] + rec(1,1));
// 	if(ans == inf)
// 	{
// 		cout << -1 << endl;
// 	}
// 	else
// 	{
// 		cout << ans << endl;
// 	}
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
#define output(x) for(auto a:x) cout << a <<" ";cout<<endl;
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
int n,k;
string a,b;
int rec(int level,set<int> st)
{ // size of st will be at max 10

	// what will rec(level,st) return
	// it tells us maximum no of pairs (l,r)
	// from level to n which have same substring 
	// in string a & b under the condition that
	// there are at most K different elements in 
	// the set Q



	// pruning 

	//base case


	//cache check

	//compute
	int ans = 0;

	// current choices on a level
	// if some elements matches then just increase cnt

	// if does not match then either put it in set
	// or don't put it in set

	// either take the element on the current level
	int take = 0 , notTake = 0;
	{
		// take
		if(st.find(a[level]) != st.end())
		{

		}
	}
	// or not take 

	//save and return
}
void solve()
{
	cin >> n >> k;
	cin >> a >> b;
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