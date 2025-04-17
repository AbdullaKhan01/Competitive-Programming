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
// int solve(vector<vi>&segments,int k)
// {
// 	int rightMost = 0;
//     int flag = 1;
//     int n = segments.size();
//     for(int i=0; i < n ; i++)
//     {
//         if(rightMost + segments[i][1] >= segments[i][0])
//         {
//             rightMost = min(rightMost+k,segments[i][1]);
//         }
//         else
//         {
//             return -1;
//         }
//     }
//     return flag;
// }
// signed main(){
// 	fast_io();
//     ll tt;
//     cin >> tt;
//     while(tt--)
//     {
//         int n;
//         cin >> n;
//         vector<vector<int>>segments(n,vector<int>(2,0));
//         rep(i,0,n)
//         {
//         	cin >> segments[i][0] >> segments[i][1];
//         }
//         int s = 1 , e = 1e9;
//         int ans = INT_MAX;
//         while(s <= e)
//         {
//         	int mid = (s+e)/2;
//         	int a = solve(segments,mid);
//         	if(a == 1)
//         	{
//         		ans = min(ans,mid);
//         		e = mid - 1;
//         	}
//         	else if(a == 0)
//         	{
//         		e = mid - 1;
//         	}
//         	else if(a == -1)
//         	{
//         		s = mid + 1;
//         	}
//         }
//         cout << ans << endl;
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
    ll tt=1;
    // cin >> tt;
    while(tt--)
    {
        int n,k;
        cin >> n;
        n*=2;
        k = n/2;
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
        if(n/2 % 2 == 0)
        {
            cout << "NO" << endl;
            continue;
        }
        cout << yes << endl;
        output(arr);
        cout << endl;
    }
    return 0;
}