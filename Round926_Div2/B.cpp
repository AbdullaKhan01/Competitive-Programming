// #include<bits/stdc++.h>
// #define mod 1000000007
// #define mod2 998244353
// #define ceil(a,b) ((a+b-1)/b)
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
// signed main(){
    
//     ll tt;
//     cin >> tt;
//     while(tt--)
//     {
//         int n,k;
//         cin >> n >> k;
//         string s;
//         cin >> s;
//         int one = 0;
//         int zero = 0;
//         for(int i=0;i<n;i++){
//             if(s[i] == '1') one++;
//             else zero++;
//         }
//         // sort(all(s));
//         string ans = "";
//         if(k <= one){
            
//             for(int i=0;i<n;i++){
//                 if(s[i] == '1'){
//                     if(k){
//                         k--;continue;
//                     }
//                     else ans += "1";
//                 }
//                 else{
//                     ans+= "0";
//                 }
//             }
//         }
//         else{
//             int g = k - one;
//             int finalneed = zero - g;
//             for(int i=0;i<finalneed;i++){
//                 ans+="0";
//             }
//         }
//         cout << ans << endl;
//         // while(k--){
//         //     if(one >= k) one-=k,k=0;
//         //     else k-=one,one = 0;
//         //     if(k > 0){zero-=k;}
//         // }
//         // string ans = "";
//         // for(int i=0;i<n;i++){
//         //     if(s[i] == '1'){
//         //         if(one){
//         //             ans+="1";
//         //             one--;
//         //         }
//         //     }
//         //     else{

//         //     }
//         // }
//     }
//     return 0;
// }
#include<bits/stdc++.h>
#define mod 1000000007
#define mod2 998244353
#define ceil(a,b) ((a+b-1)/b)
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
signed main(){
    
    ll tt;
    cin >> tt;
    while(tt--)
    {
        int n;
        cin >> n;
        vi arr(n);
        int sum = 0;
        rep(i,0,n){
            cin >> arr[i];
            sum+=arr[i];
        }
        cout << (sum%2 == 0?"Bob":"Alice") << endl;
    }
    return 0;
}