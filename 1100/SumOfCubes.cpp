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
// bool check(int n)
// {
// 	if(n < 1) return false;
// 	int a = cbrt(n);
// 	return (a * a * a == n);
// }
// signed main(){
// 	fast_io();
//     ll tt;
//     cin >> tt;
//     while(tt--)
//     {
//         // a3 + b3 = x
//         // a3 = x - b3
//         // a = cbrt(x-b3) 
//         // cbrt(x-b3) can be at most 10^4
//         int x;
//         cin >> x;
//         bool flag = false;
//         for(int a=1;a<=1e4;a++)
//         {
//         	int z = x - (a*a*a);
//         	if(check(z))
//         	{
//         		flag = true;
//         		break;
//         	}
//         }
//         cout << (flag?yes:no) << endl;
//     }
//     return 0;
// }
#include<bits/stdc++.h>
#define SHAKYA ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ceil(a,b) ((a+b)-1)/b
#define vi vector<int>
#define ppb pop_back()
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define mod 1000000007
#define sumAll(x) accumulate(x.begin(),x.end(),0ull)
#define rall(x) (x).rbegin(),(x).rend()
#define input(x) for(auto &a:x) cin >> a;
#define output(x) for(auto a:x) cout << a <<' ';
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std; 
 
void solve() {
    int s = 1, e = 1e6;
    int ans = -1;
    while(s <= e) {
        int mid = s+(e-s)/2;
 
        cout << mid << endl;
        // fflush(stdout);

        string a; cin >> a;
        if(a != ">=") {
            e = mid-1;
        }
        else {
            ans = mid;
            s = mid+1;
        }
    }
 
    cout << "! " << ans << endl;
}
 
signed main(){
    SHAKYA
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        solve();
    }
    return 0;
}