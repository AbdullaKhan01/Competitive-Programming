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
// signed main(){
	
//     ll tt;
//     cin >> tt;
//     while(tt--)
//     {
//         int n;
//         cin >> n;
//         string s;
//         cin >> s;
//         int st = 0;
//         int e = 0;
//         if(n == 1){
//         	if(s[0] == 'B'){
//         		cout << 1 << endl;
//         	}
//         	else{
//         		cout << 0 << endl;
//         	}
//         	continue;
//         }
//         for(int i=0;i<n;i++){
//         	if(s[i] == 'B'){
//         		st = i;
//         		break;
//         	}
//         }
//         for(int i=n-1;i>=0;i--){
//         	if(s[i] == 'B'){
//         		e = i;
//         		break;
//         	}
//         }
//         // cout << st << " " << e << endl;
//         if(st == 0 && e == 0){
//         	cout << 0 << endl;
//         }
//         else if(st == e){
//         	cout << 1 << endl;
//         }
//         else{
//         	cout << e-st+1 << endl;
//         }
//     }
//     return 0;
// }
#include<bits/stdc++.h>
#define ll long long
#define int long long
using namespace std; 

signed main(){
    ll tt = 1;
    cin >> tt;
    while(tt--) {
        int n; cin >> n;
        string a; cin >> a;
        int c = 0;
        for(auto i: a) {
            if(i == 'B')
            c++;
        }
        if(c == 0 || c == 1){
            cout << c << endl;
            continue;
        }
        int i = 0,j=n-1;
        for(i = 0;i < n; i++){
            if(a[i] == 'B')
                break;
        }
        for(j;j>=0;j--){
            if(a[j] == 'B')
                break;
        }
        cout << j-i+1 << endl;
 
    }
    return 0;
}