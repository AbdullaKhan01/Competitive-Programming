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
// void do_unique(vector<int>&arr){
//     vector<int>::iterator ip;
//     ip = unique(arr.begin(),arr.end());
//     arr.resize(distance(arr.begin(),ip));
// }
// int f2(vi arr,int n){
    
//         arr.push_back(-1);
//         for(int i=0;i<n;i++){
//             cin >> arr[i];
//         }
//         sort(arr.begin(),arr.end()-1);
//         set<int> s;

//         for(int i=0;i<n;i++){
//             if(arr[i] == arr[i+1]){
//                 s.insert(arr[i]);
//             }
//         }
//         arr.ppb();
//         do_unique(arr);

//         vector<int> gg;
        
//         for(int i=0;i<arr.size();i+=2){
//             s.insert(arr[i]);
//         }
//         for(auto it:s){
//             gg.pb(it);
//         }

//         sort(all(gg));

//         int ans = 0;
//         for(int i=0;i<gg.size();i++){
//             if(gg[i] != ans){
//                 break;
//             }
//             else{
//                 ans++;
//             }
//         }
//         return ans;
// }
    
// int f1(vi arr,int n){

//         arr.resize(n+2);
//         vi freq(n+1);
//         for(int i=0;i<n;i++){

//             freq[arr[i]]++;
//         }
//         bool mex = false;
//         for(int i=0;i<arr.size();i++){
//             if(freq[i] == 0 || (freq[i] == 1 && mex)){
//                 return i;
//             }
//             mex |= (freq[i] == 1);
//         }
//         return 0;
// }
// signed main(){
//     fast_io();
//     for(int i=0;i<50;i++){
//         vi arr;
//         for(int i=0;i<9;i++){
            
//             int ele = rand()%10;
//             arr.pb(ele);
            
//         }
//         int n = arr.size();
//         int a1 = f1(arr,n);
//         int a2 = f2(arr,n);
//         if(a1 != a2){
//             cout << a1 << " " << a2 << endl;
//             output(arr);
//             cout << endl;
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
        vi freq(n+1);
        for(int i=0;i<n;i++){
            cin >> arr[i];
            freq[arr[i]]++;
        }
        vector<int> g;
        bool flag = true;
        for(int i=0;i<freq.size();i++){
            if(freq[i] >= 2) g.pb(i);
            else if(freq[i] == 1){
                if(flag){
                    g.pb(i);
                    flag = !flag;
                }
            } 
        }
        sort(all(g));
        int ans = 0;
        for(int i=0;i<g.size();i++){
            if(g[i] != ans){
                break;
            }
            else{
                ans++;
            }
        }
        cout << ans << endl;

        
    }
    return 0;
}