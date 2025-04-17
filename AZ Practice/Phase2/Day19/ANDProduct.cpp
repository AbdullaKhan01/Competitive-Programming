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
// 	vector<int> a(n),b(n);
// 	for(int i=0;i<n;i++)
// 	{
// 		cin >> a[i] >> b[i];
// 	}
// 	for(int i=0;i<n;i++)
// 	{
// 		int l = a[i] , r = b[i];
// 		int ans = 0;
// 		for(int j=0;j<32;j++)
// 		{
// 			// if jth bit of l is 0 then continue;
// 			if(!(1 & (l>>j))) continue;
// 			// jth bit is set
// 			// jth bit flips after 2^(j) steps
// 			int steps = 1<<j;
// 			if(steps >= r-l >= steps) continue;
// 			// which position we are currently standing in ?
// 			int pos = l % steps;

// 		}
// 	}
// }
// signed main(){
// 	fast_io();
//     ll tt=1;
//     // cin >> tt;
//     while(tt--)
//     {
//         solve();
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
signed main(){
	fast_io();
    int n;
    cin >> n;
    if(n % 2 == 0 && n != 2)
    {
    	cout << "YES";
    }
    else
    {
    	cout << "NO";
    }
    return 0;
}


//