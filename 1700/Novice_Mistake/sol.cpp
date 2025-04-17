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
//         if(n == 1)
//         {
//         	cout << 9999 << endl;
//         	for(int i=2;i<=10000;i++)
//         	{
//         		cout << i << " " << i-1 << endl;
//         	}
//         	continue;
//         }
//         string temp = "";
//         for(int i=0;i<20;i++)
//         {
//         	string s = to_string(n);
//         	temp = temp+s;
//         }

//         vector<vector<int>>ans;
//         // a = 10000 303030303030303030 - b 123456 
//         for(int st = 1;st<=10000;st++)
//         {
//         	// a - b = st;
//         	// b = a - st

//         	// na - b = na - a + st;
//         	// (n-1)a + st = (st)n

//         	string num = temp.substr(0,st);
//         	// cout << st << " " << num << endl;
//         	int x = stoi(num);

//         	int sz = to_string(n).size();
//         	int fact = n;
//         	// cout << fact << " " << sz << endl;
//         	if(n % sz == 0) fact/=sz;
//         	else continue;
//         	// int x = num;
//         	// cout << st << " " << fact << endl;
//             if((fact - 1) == 0) continue;
            
//         	if((x - st) % (fact-1) == 0)
//         	{
//         		int a = (x-st)/(fact-1);
//         		int b = a - st;
//         		a = a/sz;
//         		if(a > 10000) break;
//         		if(b >= 1 && b<=min(1LL*10000,a*n))
//         			ans.push_back({a,b});
//         	}
//         }
//         cout << ans.size() << endl;
//         for(auto it:ans)
//         {
//         	cout << it[0] << " " << it[1] << endl;
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
void solve()
{
    int n;cin >> n;
    // n * a - b <= 1e6 
    // this means  n*a - b has only 1 to 6 digits
    string s = to_string(n);
    while(s.size() < 10){
        s += s;
    }
    vector<pair<int,int>> ans;
    for(int a=1;a<=10000;a++){
        int j = n * a;
        int l = to_string(n).size() * a;
        for(int remaining = 1; remaining<=6;remaining++){
            string m = s.substr(0,remaining);
            int val = stoll(m);
            int b = n * a - val;
            int was_b = l - remaining;
            if(b == was_b && b >= 1 && b <= min(10000LL,j)){
                ans.push_back({a,b});
            }
        }   
    }
    cout << ans.size() << endl;
    for(auto it : ans){
        cout << it.first << " " << it.second << endl;
    }
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