// // #include<bits/stdc++.h>
// // #define int long long
// // #define fast_io() ios::sync_with_stdio(0);cin.tie(0);

// // #define endl '\n'
// // using namespace std; 
// // /* 
// // for fast input output use printf and scanf;
// // */
// // int n;
// // vector<int> a;
// // int check(int mid)
// // {
// //     int prev = 0;
// //     int cnt = 0;
// //     for(int i=0;i<n;i++)
// //     {
// //         if(a[i] > mid) return -1;
// //         // a[i] <= mid
// //         if(prev + a[i] > mid)
// //         {
// //             return -1;
// //         }
// //         else if(prev + a[i] == mid)
// //         {
// //             if(prev == 0)
// //             {
// //                 continue;
// //             }
// //             else
// //             {
// //                 prev = 0;
// //                 cnt++;
// //             }
// //         }
// //         else
// //         {
// //             // prev + a[i] < mid
// //             if(prev == 0)
// //             {
// //                 prev += a[i];
// //             }
// //             else prev+=a[i],cnt++;
// //         }
// //         // cout << i << " " << cnt << endl;   
// //     }
// //     if(prev == 0 || prev == mid) return cnt;
// //     else return -1;
// // }
// // void solve()
// // {
// //     cin >> n;
// //     a.resize(n);
// //     int sum = 0;
// //     for(int i=0;i<n;i++)
// //     {
// //         cin >> a[i];
// //         sum += a[i];
// //     }
// //     int s = 0 , e = sum;
// //     int ans = -1;
// //     while(s <= e)
// //     {
// //         int mid = (s+e)/2;
// //         int k = check(mid);
// //         if(k == -1)
// //         {
// //             s = mid + 1;
// //         }
// //         else
// //         {
// //             e = mid - 1;
// //             ans = k;
// //         }
// //     }
// //     cout << ans << endl;
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
// int n,k;
// vector<int> a;
// void solve()
// {
//     cin >> n >> k;
//     a.resize(n);
//     for(int i=0;i<n;i++)
//     {
//         cin >> a[i];
//     }
//     sort(a.begin(),a.end());
//     int greatest = a.back();
//     vector<pair<int,int>> ms(n);
//     int lmax = -1 , rmin = 1e9;
//     for(int i=0;i<n-1;i++)
//     {
//         // a[i] + x * 2k >= greatest
//         // x * 2k >= greatest - a[i]
//         // x >= (greatest - a[i])/2k   
//         int x = ceil(greatest-a[i],2*k);
//         int l = a[i] + x*2*k;
//         int r = l + k - 1;
//         ms[i].first = l;
//         ms[i].second = r;
//         lmax = max(lmax,l);
//         rmin = min(rmin,r);
//     }
//     if(lmax > rmin)
//     {
//         cout << -1 << endl;
//     }
//     else 
//     {
//         cout << lmax << endl;
//     }
// }
// signed main(){
//     fast_io();
//     int tt = 1;
//     cin >> tt;
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
class Solution { 
private: 
    void dfs(pair<int,int>p,map<pair<int,int>,int>&mp,vector<vector<char>>& board){ 
        int a=p.first; 
        int b=p.second; 
        auto it1=mp.find({a,b+1}); 
        if(it1!=mp.end()){ 
            pair<int,int>w={a,b+1}; 
            mp[{a,b+1}]=1; 
            dfs(w,mp,board); 
        } 
        auto it2=mp.find({a,b-1}); 
        if(it2!=mp.end()){ 
            pair<int,int>x={a,b-1}; 
            mp[{a,b-1}]=1; 
            dfs(x,mp,board); 
        } 
        auto it3=mp.find({a+1,b}); 
        if(it3!=mp.end()){ 
            pair<int,int>y={a+1,b}; 
            mp[{a+1,b}]=1; 
            dfs(y,mp,board); 
        } 
        auto it4=mp.find({a-1,b}); 
        if(it4!=mp.end()){ 
            pair<int,int>z={a-1,b}; 
            mp[{a-1,b}]=1; 
            dfs(z,mp,board); 
        } 
    } 
public: 
    void solve(vector<vector<char>>& board) { 
        map<pair<int,int>,int>mp; 
        int m=board.size(); 
        int n=board[0].size(); 
        for(int i=0;i<m;i++){ 
            for(int j=0;j<n;j++){ 
                mp[{i,j}]=0; 
            } 
        } 
        for(int i=0;i<m;i++){ 
            if(mp[{i,0}]==0){ 
                mp[{i,0}]=1; 
                pair<int,int>p={i,0}; 
                dfs(p,mp,board); 
            } 
        } 
        for(int i=0;i<n;i++){ 
            if(mp[{0,i}]==0){ 
                mp[{0,i}]=1; 
                pair<int,int>p={0,i}; 
                dfs(p,mp,board); 
            } 
        } 
        for(int i=0;i<m;i++){ 
            if(mp[{i,n-1}]==0){ 
                mp[{i,n-1}]=1; 
                pair<int,int>p={i,n-1}; 
                dfs(p,mp,board); 
            } 
        } 
        for(int i=0;i<n;i++){ 
            if(mp[{m-1,i}]==0){ 
                mp[{m-1,i}]=1; 
                pair<int,int>p={m-1,i}; 
                dfs(p,mp,board); 
            } 
        } 
        for(int i=0;i<m;i++){ 
            for(int j=0;j<n;i++){ 
                if(mp[{i,j}]==1){ 
                    cout<<'X'<<" "; 
                } 
                else{ 
                    cout<<board[i][j]<<" "; 
                } 
            } 
            cout<<endl; 
        } 
    } 
};
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