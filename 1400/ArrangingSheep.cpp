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
vector<int> factors(int n){
    vector<int> ans;
    for(int i=1;i*i<=n;i++){
        if(n% i == 0){
            ans.push_back(i);
            if(n/i != i){
                ans.push_back(n/i);
            }
        }
    }
    sort(all(ans));
    return ans;
} 
long long lcm (long long a, long long b) {
    return a / __gcd(a, b) * b;
}
signed main(){
    
    int n;
    cin >> n;
    vi p = factors(n);
    // cout << p.size() << endl;
    int ans = n;    int s=1 , ss=n;
    for(int i=1;i<p.size();i++){

        int x1 = p[i];
        int y1 = n/x1;
        // cout << x1 << " " << y1 << endl;
        int x = lcm(x1,y1);
        if(x == n){
            int e = max(x1,y1);
            if(e <= ans){
                ans = e;
                ss = e;
                s = min(x1,y1);
            }
        }
        
    }
    cout << s << " " << ss << endl;
    return 0;
}