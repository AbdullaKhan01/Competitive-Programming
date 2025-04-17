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
signed main(){
    
    
    int n;
    cin >> n;
    vi arr(n);
    input(arr);
    int ans = 1;
    int cnt = 0;
    int prev = 0;
    int cnt2 = 0;
    for(int i=0;i<n;i++){
        if(arr[i] == 1){
            // cout << "here";
            if(prev == 1)
                ans *= (cnt2+1);
            cnt2 = 0;
            cnt++;
            prev = 1;
        }
        else{
            cnt2++;
        }
    }
    if(cnt <= 1){
        cout << cnt << endl;
    }
    else cout << ans << endl;
    return 0;
}