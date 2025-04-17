#include<bits/stdc++.h>
#define ll long long
#define ll long long
#define lli long long int
#define vi vector<int>
#define vll vector<ll>
#define all(x) (x).begin(),(x).end()
#define FOR(i,n) for(i=0;i<n;i++)
using namespace std; 

int main(){
    ll tt;
    cin >> tt;
    while(tt--)
    {
        ll n,p;
        cin >> n >> p;
        string s;
        cin >> s;
        ll i=1;
        ll count =0;
        // ll ans = 0;
        vll ans(n,0);
        ans[n-1] = (s[n-1]=='B');
        for(int i=n-2;i>=0;i--){
            ans[i] = ans[i+1] + (s[i]=='B');
        }
        for(int i=0;i<n;i++){
            if(ans[i]==p){
                cout << 1 << endl;
                cout << i+1 << " A"<<endl;
            }
        }
        cout << endl;          
    }
    return 0;
}