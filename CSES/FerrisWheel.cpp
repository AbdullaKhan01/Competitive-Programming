// // // #include<bits/stdc++.h>
// // // #define mod 1000000007
// // // #define mod2 998244353
// // // #define ceil(a,b) ((a+b-1)/b)
// // // #define ll long long
// // // #define int long long
// // // #define vi vector<int>
// // // #define all(x) (x).begin(),(x).end()
// // // #define rall(x) (x).rbegin(),(x).rend()
// // // #define input(x) for(auto &a:x) cin >> a;
// // // #define output(x) for(auto a:x) cout << a <<" ";
// // // #define rep(i,a,n) for(int i=(a);i<n;i++)
// // // #define pb push_back
// // // #define ppb pop_back
// // // #define pf push_front
// // // #define ppf pop_front
// // // #define ff first
// // // #define ss second
// // // #define si set<int>
// // // #define pii pair<int,int>
// // // #define mii map<int,int>
// // // #define msi map<string,int>
// // // #define yes "YES"
// // // #define no "NO"
// // // #define endl '\n'
// // // using namespace std; 
// // // signed main(){
	
// // //     int n,w;
// // //     cin >> n >> w;
// // //     vector<int> a(n);
// // //     multiset<int> ms;
// // //     for(int i=0;i<n;i++)
// // //     {
// // //         cin >> a[i];
// // //         ms.insert(a[i]);
// // //     }
// // //     int cnt = 0;
// // //     while(!ms.empty())
// // //     {
// // //         cnt++;
// // //         int val = *ms.rbegin();
// // //         ms.erase(ms.find(val));
// // //         int now = w - val;
// // //         if(ms.empty()) break;
// // //         auto it = ms.upper_bound(now);
// // //         if(it != ms.begin())
// // //         {
// // //             int n_val =  *(--it);
// // //             ms.erase(ms.find(n_val));    
// // //         }
        
// // //     }
// // //     cout << cnt << endl;
// // //     return 0;
// // // }


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
// // void solve()
// // {
// //     int m;cin >> m;
// //     vector<int> lps(m);
// //     lps[0] = 0;
// //     string pat;cin >> pat;
// //     int i = 0 , j = 1;
// //     while(i < m){
// //         if(pat[i] == pat[j])
// //         {
// //             i++;
// //             lps[i] = j;
// //             j++;
// //         }
// //         else
// //         {
// //             // there is a mismatch
// //             if(i != 0)
// //             {
// //                 i = lps[i-1];
// //             }
// //             else
// //             {
// //                 lps[j] = 0;
// //                 j++;
// //             }
// //         }
// //     }
// //     output(lps);
// // }
// // signed main(){
// //     fast_io();
// //     int tt = 1;
// //     // cin >> tt;
// //     while(tt--)
// //     {
// //         solve();
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
// void solve()
// {
//     int n;cin >> n;
//     vector<int> a(n);
//     int gcd = 0;
//     for(int i=0;i<n;i++)
//     {
//         cin >> a[i];
//         gcd = __gcd(gcd,a[i]);
//     }
//     cout << gcd << endl;
// }
// //
// signed main(){
//     fast_io();
//     int tt = 1;
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
void solve()
{
    int n,m,k;
    cin >> n >> m >> k;
    int cnt = 0;
    int ans = 0;
    string a;
    cin >> a;
    int x = 2 * m + k - 1;
    for(int i=0;i<n;i++)
    {
        if(a[i] == '0') cnt++;
        else
        {
            if(cnt > 0)
            {
                // possibly do something
                if(cnt >= m)
                {
                    int v = ceil(cnt,x);
                    ans += v;
                }
            }
            cnt = 0;
        }
    }
    if(cnt >= m)
    {
        ans += ceil(cnt,x);
    }
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