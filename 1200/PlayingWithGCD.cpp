#include<bits/stdc++.h>
#define mod 1000000007
#define mod2 998244353
#define ceil(a,b) ((a+b-1)/b)
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
long long lcm (long long a, long long b) {
    return a / __gcd(a, b) * b;
}
signed main(){
	
    ll tt;
    cin >> tt;
    while(tt--)
    {
        int n;
        cin >> n;
        vi arr(n);
        input(arr);
        if(n == 1){
            cout << "YES" << endl;
        }
        else{
            vector<int> p(n+1,0);
            for(int i=1;i<=n-1;i++){
                p[i] = lcm(arr[i-1],arr[i]);
            }
            // output(arr);
            // cout << endl;  
            // output(p); 
            // cout << endl;
            bool flag = true;
            // for(int i=1;i<n-1;i++){
            //     if(arr[i-1] == 1 || arr[i] == 1) continue;
            //     int m = __gcd(arr[i-1],arr[i]);
            //     cout << m << p[i] << endl;
            //     if(p[i] != m){
            //         flag = false;
            //         break;
            //     }
            // }
            for(int i=1;i<n-1;i++){
                if(arr[i] != __gcd(p[i],p[i+1])){
                    flag = false;
                    break;
                }
            }
            cout << (flag?yes:no) << endl;
        }
    }
    return 0;
}