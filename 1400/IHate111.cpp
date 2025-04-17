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
// bool solve(int tar,vector<int>&arr,int index){
//     // cout << tar << " " << index << endl;
//     if(tar == 0) return true;
//     if(tar < 0) return false;
//     if(index >= arr.size()) return false;
    
//     int take = false;
//     take = solve(tar-arr[index],arr,index);
//     int notTake = solve(tar,arr,index+1);

//     return take || notTake;

// }

// signed main(){
	
//     ll tt;
//     cin >> tt;
//     while(tt--)
//     {
//         int n;
//         cin >> n;
//         vector<int> arr = {11,111};
//         if(n >= 1100){
//             cout << yes << endl;
//         }
//         else{
//             cout << (solve(n,arr,0)?yes:no) << endl;
//         }
//     }
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int t;
//     cin >> t;
//     while(t--){
//         int n, k;
//         cin >> n >> k;
//         int a[n];
//         int mini = INT_MAX;
//         for (int i = 0; i < n; i++)
//         {
//             cin >> a[i];
//             mini = min(mini, a[i]);
//         }
//         int temp = a[k-1];
//         int cnt = 0;
//         for (int i = 0; i < n; i++)
//         {
//             if(a[i] > temp){
//                 temp = i;
//                 break;
//             }
//         }
//         if(mini == a[k-1]) cnt = 0;
//         else if(temp < k-1){
//             cnt = k - 1 - temp;
//         }
//         else{
//             cnt = temp - 1;
//         }
//         cout << cnt << endl;
        
//     }
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
int win(vector<int>&vec,int k) {
    int maxi = INT_MIN;
    int i = 0 , numWin = 0;
    for(; i < vec.size();i++) {
        maxi = max(maxi,vec[i]);
        if(vec[i] == k) break;
        
    }
    i++;
    if(maxi == k&&i!=1) numWin++;


    else if(maxi!=INT_MIN && i!=1) return 0;
    for(; i < vec.size();i++) {
        if(vec[i] > k)break;
        else numWin++;
    }
    return numWin;
}
signed main(){
    fast_io();
    ll tt;
    cin >> tt;
    while(tt--)
    {
        int n,k;
        cin >> n >> k;
        vector<int> arr(n);
        input(arr);
 
        int cow = arr[k-1];
        swap(arr[0],arr[k-1]);
            

        // output(arr);
        // cout << endl;

        int cnt = win(arr,cow); 
        // cout << cnt << endl;

        swap(arr[0],arr[k-1]);

        // output(arr);
        // cout << endl;

        int maxi=INT_MIN;
        int index = -1;
        for(int i=0;i<n;i++){
            if(arr[i] > maxi){
                maxi = arr[i];
                index = i;
            }
        }
        swap(arr[index],arr[k-1]);

        // output(arr);
        // cout << endl;

        int cnt2 = win(arr,cow);
        // cout << cnt2 << endl;
        
        cout << max(cnt,cnt2) << endl;
    }
    return 0;
}