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
// signed main(){
//     fast_io();
//     ll tt;
//     cin >> tt;
//     while(tt--)
//     {
//         int n;
//         cin >> n;
//         vi arr(n);
//         input(arr);
//         vi gcdS;
//         for(int i=1;i<n;i++)
//         {
//             gcdS.pb(__gcd(arr[i],arr[i-1]));
//         }
//         output(gcdS);
//         cout << endl;
//         int gg = gcdS.size();
//         int rm = -1;
//         for(int i=1;i<gg;i++)
//         {
//             if(gcdS[i]<gcdS[i-1])
//             {
//                 if(i == gg-1)
//                 {
//                     continue;
//                 }
//                 else
//                 {
//                     int m = gcdS[i+1];
//                     if(m >= gcdS[i-1]) rm = i;
//                     else rm = i-1;
//                 }
//                 break;
//             }
//         }
//         if(rm == -1)
//         {
//             cout << yes << endl;
//         }
//         else
//         {
//             gcdS.erase(gcdS.begin()+rm);
//             bool flag = true;
//             for(int i=1;i<gcdS.size();i++)
//             {
//                 if(gcdS[i] < gcdS[i-1]) flag = false;
//             }
//             cout << (flag?yes:no) << endl;
//         }
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
    ll tt;
    cin >> tt;
    while(tt--)
    {
        int n;
        cin >> n;
        vi arr(n);
        input(arr);
        vi g;
        for(int i=1;i<n;i++)
        {
            g.pb(__gcd(arr[i-1],arr[i]));
        }
        output(g)
        cout << endl;
        vi pref(n,1);
        vi suff(n,1);
        int flag = true;
        for(int i=0;i<n;i++)
        {
            if(i <= 2) pref[i] = 1;
            else
            {
                int g1 = g[i-3];
                int g2 = g[i-2];
                flag = flag && (g2>=g1);
                pref[i] = flag;
            }
        }
        flag = true;
        for(int i=n-1;i>=0;i--)
        {
            if(i >= n-3) suff[i] = 1;
            else
            {
                int g1 = g[i+2];
                int g2 = g[i+3];
                flag = flag && (g2>=g1);
                suff[i] = flag;
            }
        }
        output(pref);
        cout << endl;
        output(suff);
        cout << endl;
    }
    return 0;
}