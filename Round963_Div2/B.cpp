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
//         vi arr(n);
//         input(arr);
//         sort(all(arr));
//         int z = arr.back();
//         multiset<int>left,right;
//         for(int i=0;i<n-1;i++)
//         {
//         	int l = z-arr[i];
//         	int x = ceil(l,k);
//         	{
//         		if(x % 2 != 0)
//         		{
//         			if(arr[i] + (x-1)*k + k - 1 >= z)
//                     {
//                         x--;
//                     }
//                     else x++;
//         		}
//         		int l = arr[i] + (x*k);
//         		int r = l + k - 1;
//         		left.insert(l);
//         		right.insert(r);
//         	}
//         }
//     	left.insert(z);
//     	right.insert(z+k-1);
//     	if(*(left.rbegin()) > *(right.begin()))
//     	{
//     		cout << -1 << endl;
//     	}
//     	else
//     	{
//     		cout << *left.rbegin() << endl;
//     	}
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
        int n;
        cin >> n;
        vector<vector<int>>arr(n,vector<int>(n));
        int sum = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++) cin >> arr[i][j],sum+=arr[i][j];
        }
        int mini = INT_MAX;
        for(int i=0;i<n;i++)
        {
            mini = min(mini,arr[i][n-i-1]);
        }
        sum -= mini;
        cout << sum << endl;    
    }
    return 0;
}

/*
. . . . . .  
. . . . . .
. . . . . .
. . . . . . 
. . . . . .
. . . . . .

*/