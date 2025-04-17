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
// 	fast_io();
//     ll tt;
//     cin >> tt;
//     while(tt--)
//     {
//         int n,x;
//         cin >> n >> x;
//         int k = x;
//         vi arr(n),brr(n);
//         vector<pair<int,int>> crr;
//         rep(i,0,n)
//         {
//             cin >> arr[i];
//             crr.push_back({arr[i],i});
//         }
//         rep(i,0,n)
//         {
//             cin >> brr[i];
//         }
//         sort(all(crr));
//         sort(all(brr));
//         vector<int> ans(n,-1);
//         bool flag = true;
//         int idx = 0;
//         int cnt = 0;
//         for(int i = n-1 ; i >= 0; i--)
//         {
//             if(x > 0)
//             {
//                 if(brr[idx] >= crr[i].first) flag = false;
//                 else ans[crr[i].second] = brr[idx];
//                 x--;
//                 cnt++;
//             }
//             else if(x == 0)
//             {
//                 idx = n-1;
//                 while(i>=0)
//                 {
//                     if(crr[i].first > brr[idx]) cnt++;
//                     ans[crr[i].second] = brr[idx--];
//                     i--;
//                 }
//                 break;
//             }
//             idx++;
//         }
        
//         if(cnt == k && flag)
//         {
//             cout << yes << endl;
//             output(ans);
//             cout << endl;
//         }
//         else
//         {
//             cout << no << endl;
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
    // for(int gap = 4 ; gap >=0;gap--)
    // {
    //     for(int i = 0; i < gap;i++){
    //         printf(" ");
    //     }
    //     for(int star = 1 ; star<=5-gap;star++)
    //     {
    //         printf("* ");
    //     }
    //     printf("\n");
    // }
    // for(int gap = 0 ; gap<=4;gap++)
    // {
    //     for(int i=0;i<gap;i++)
    //     {
    //         printf(" ");
    //     }
    //     for(int i=0;i<4;i++)
    //     {
    //         printf("* ");
    //     }
    //     cout << endl;
    // }


    for(int gap = 3 ; gap >=  0 ; gap--)
    {
        for(int i=0;i<gap;i++)
        {
            printf(" ");
        }
        for(int j=0;j<4-gap;j++)
        {
            printf("* ");
        }
        cout << endl;
    }
    for(int gap = 1 ; gap <=  3 ; gap++)
    {
        for(int i=0;i<gap;i++)
        {
            printf(" ");
        }
        for(int j=0;j<4-gap;j++)
        {
            printf("* ");
        }
        cout << endl;
    }
    
    return 0;
}