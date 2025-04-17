#include<bits/stdc++.h>
#define ll long long
#define int long long
#define SHAKYA ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ceil(a,b) ((a+b)-1)/b
#define vi vector<int>
#define ppb pop_back()
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define mod 1e9+7
#define rall(x) (x).rbegin(),(x).rend()
#define input(x) for(auto &a:x) cin >> a;
#define output(x) for(auto a:x) cout << a <<' ';
#define rep(i,n) for(i=0;i<n;i++)
#define end cout << endl;
using namespace std; 

signed main(){
    SHAKYA
    ll tt;
    cin >> tt;
    while(tt--) {
        int n,k;
        cin >> n >> k;
        int s = 0, e = n-1;
        vi vec(n);
        input(vec);
        int c = 0; bool p = false;
        while(s <  e && k > 0)  {
            if(vec[s] == 0) {
                c++;
                s++;
            }
            else if(vec[e] == 0) {
                c++;
                e--;
            }
            if(!p){
                vec[s]--;
                p = true;
            }
            else {
                vec[e]--;
                p = false;
            }
            k--;
        }
        cout << c << endl;
    }
    return 0;
}