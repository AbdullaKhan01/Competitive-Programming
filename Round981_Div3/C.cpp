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
// void func(vector<int>&a,int n)
// {
// 	for(int i=1;i<=n/2;i++)
// 	{
		
// 		int curr = i;

// 		int idx = n - i + 1;
// 		int cnt = (a[i] == a[i-1]) + (a[i] == a[i+1]) + (a[idx] == a[idx-1]) + (a[idx] == a[idx+1]);
// 		int cnt2 = (a[curr] == a[idx-1]) + (a[curr] == a[idx+1]) + (a[idx] == a[curr-1]) + (a[idx] == a[curr+1]); 

// 		if(cnt2 < cnt)
// 		{
// 			swap(a[curr],a[idx]);
// 		}
// 	}
// }
// int solve(vector<int> a)
// {
// 	int n = a.size();
// 	func(a,n-2);
// 	int cnt = 0;
// 	int cnt2 = 0;
// 	for(int i=2;i<=n;i++)
// 	{
// 		if(a[i] == a[i-1]) cnt++;
// 	}
// 	swap(a[1],a[n-2]);
// 	for(int i=2;i<=n;i++)
// 	{
// 		if(a[i] == a[i-1]) cnt2++;
// 	}
// 	return min(cnt,cnt2);
// }
// signed main(){
// 	fast_io();

//     int tt = 1;
//     cin >> tt;

//     while(tt--)
//     {
//     	int n;
//     	cin >> n;
//     	vector<int> a(n+2,-1);
//     	for(int i=1;i<=n;i++)
//     	{
//     		cin >> a[i];
//     	}
//     	cout << solve(a) << endl;
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
	if(isnan(log(-10)))
	{
		cout << "yes" << endl;
	}
	else cout << "no" << endl;
	// cout << log(-10) << endl;
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