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
// // VERDICT -> ACCEPTED
// void solve()
// {
// 	int n,m;
// 	cin >> n >> m;
// 	vector<int> a(n);
// 	map<int,int> f;
// 	for(int i=0;i<n;i++){
// 		cin >> a[i];
// 		f[a[i]]++;
// 	}
// 	sort(all(a));
// 	int ans = 0;
// 	for(int i=0;i<n;i++){
// 		// single single element
// 		int fr = f[a[i]];
// 		int r = m / a[i];
// 		int cnt = a[i] * min(fr,r);
// 		ans = max(ans,cnt);
// 	}
// 	for(int i=1;i<n;i++){
// 		// x and x - 1
// 		if(a[i] > m) continue;
// 		int fr1 = f[a[i]];
// 		if(f.find(a[i] - 1) != f.end()){
// 			int first = a[i];
// 			int second = a[i] - 1;
// 			int fr2 = f[second];
// 			int r1 = m / first;
// 			int s1 = first * min(fr1,r1);
// 			int rem = m - s1;
// 			int r2 = rem / second;
// 			int s2 = second * min(fr2,r2);
// 			ans = max(ans,s1 + s2);

// 			// now we want to remove first and add some second
// 			int g = second - (m - s1 - s2);
// 			int rfreq = fr2 - min(fr2,r2);
// 			if(rfreq == 0 || g < 0) continue;
// 			if(g + 1 <= rfreq){
// 				if(g <= min(fr1,r1)){
// 					ans = m;
// 					break;
// 				}
// 			}
// 		}
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