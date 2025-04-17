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
//         int x;
//         cin >> x;
//         int n = x;
//         double ss = (double)(x/2);
//         string s;
//         cin >> s;

//         // cout 
//         vector<pair<int,int>>pref(n+1,{0,0});
//         for(int i=1;i<=n;i++){
//         	pref[i].first = pref[i-1].first + (s[i-1]=='0');
//         	// pref[i].second = pref[i-1].second + (s[i]=='1');
//         }
//         for(int i=n-1;i>=0;i--){
//         	pref[i].second = pref[i+1].second + (s[i] == '1');
//         }
//         pref[0].second = pref[1].second;
//         pref[n].first = pref[n].first;
//         double ans = (double)(INT_MAX);
//         int index = INT_MAX;
//         // double l = double(n);
//         cout << ss << endl;
//         for(int i=0;i<=n;i++){
//         	int left = pref[i].first;
//         	int right = pref[i].second;
//         	cout << left << " " << right << endl;
//         	int left_residents = i;
//         	int right_residents = n - left_residents;
//         	int a,b;
//         	a = ceil(left_residents,2);
//         	b = ceil(right_residents,2);
//         	if(left >= a && right >= b){
        		
//         		double k = abs(ss-i);
//         		cout << i << "here" << k << endl;
//         		if(k < ans){
//         			ans = k;
//         			index = i;
//         		}
//         		if(k == ans){
//         			index = min(index,i);
//         		}
//         	}
//         }
//         cout << index << endl; 
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
        if(n%2 != 0 || n<=3){
            cout << -1 << endl;
        }
        else cout << ceil(n,6) << " " << n/4 << endl;
    }
    return 0;
}