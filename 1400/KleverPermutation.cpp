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
//         int n,k;
//         cin >> n >> k;
//         int ind = k;
//         int a = n , b = 1;
//         vi arr(n,-1);
//         vi used(n+1,-1);
//         int idx = 0;
//         bool flag = true;
//         for(int i = ind ; i < n ; i++)
//         {
//         	if(flag)
//         	{
//         		arr[i] = a;
//                 used[a] = 1;
//         		a-=2;
//         		arr[idx] = arr[i]-1;
//                 used[arr[i]-1] = 1;
//         	}
//         	else
//         	{
//         		arr[i] = b;
//                 used[b] = 1;
//         		b+=2;
//         		arr[idx] = arr[i] + 1;
//                 used[arr[i]+1] = 1;
//         	}
//         	flag = !flag;
//         	idx++;
//         }
//         idx = 0;
//         // for(int i=0;i<n;i++)
//         // {
//         //     if(arr[i] == -1)
//         //     {
//         //         while(used[idx] != -1)
//         //         {
//         //             idx++;
//         //         }
//         //         arr[i] = idx+1;
//         //     }
//         // }
//         output(arr);
//         cout << endl;
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
        int n,k;
        cin >> n >> k;
        int l = 1 , r = n;
        vi arr(n);
        for(int i=0;i<k;i++)
        {
            for(int j=i;j<n;j+=k)
            {
                if(i%2 == 0)
                {
                    arr[j] = l++;
                }
                else 
                {
                    arr[j] = r--;
                }
            }
        }
        output(arr);
        cout << endl;
    }
    return 0;
}