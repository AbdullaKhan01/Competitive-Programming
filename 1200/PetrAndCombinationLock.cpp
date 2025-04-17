#include<bits/stdc++.h>
#define ll long long
#define ll long long
#define lli long long int
#define vi vector<int>
#define vll vector<ll>
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define input(x) for(auto &a:x) cin >> a;
#define output(x) for(auto a:x) cout << a << " ";
#define FOR(i,n) for(i=0;i<n;i++)
using namespace std; 
/*
CODEFORCES 1200 Level Question
Petr and Combination Lock
*/
int main(){
    ll tt;
    cin >> tt;
    vi ans(tt);
    // input(ans);
    // output(ans);
    for(auto &a:ans) cin >> a;

    bool flag = false;
    for(int i=0;i<(1<<tt);i++){
        int sum = 0;
        for(int bit=0;bit<ans.size();bit++){
            if(i&(1<<bit)){
                sum+=ans[bit];
            }
            else{
                sum-=ans[bit];
            }
        }
        if(sum %360 == 0) {flag = true;break;}
    }
    cout << (flag?"YES":"NO")<<endl;
    return 0;
}