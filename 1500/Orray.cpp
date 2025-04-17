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
//         int n;
//         cin >> n;
//         multiset<int> ms;
//         for(int i=0;i<n;i++)
//         {
//         	int x;
//         	cin >> x;
//         	ms.insert(x);
//         }
//         vi ans;
//         int orray = *ms.rbegin();
//         ms.erase(ms.find(orray));
//         ans.pb(orray);


//         for(int i=0;i<32;i++)
//         {
//         	if(ms.empty()) break;
//         	int num = *ms.begin();
//         	int max = orray;
//         	for(auto it:ms)
//         	{
//         		if((orray | it) >= max)
//         		{
//         			max = (orray | it);
//         			num = it;
//         		}
//         	}
//         	ans.pb(num);
//         	orray |= num;
//         	ms.erase(ms.find(num));
//         }
        
//         while(!ms.empty())
//         {
//         	int x = *ms.begin();
//         	ms.erase(ms.find(x));
//         	ans.pb(x);
//         }
        
//         output(ans);
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
    int n,q;
    cin >> n >> q;
    vi arr(n),pref(n+1);
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
        pref[i+1] = pref[i] + arr[i];
    }
    while(q--)
    {
        int l,r;
        cin >> l >> r;
        cout << pref[r] - pref[l-1] << endl;
    }
    return 0;
}