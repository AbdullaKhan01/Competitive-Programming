#include<bits/stdc++.h>
#define ll long long
#define ll long long
#define lli long long int
#define vi vector<int>
#define vll vector<ll>
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define input(x) for(auto &a:x) cin >> a;
#define output(x) for(auto a:x) cout << a <<" ";
#define FOR(i,n) for(i=0;i<n;i++)
using namespace std; 

int main(){
    ll tt;
    cin >> tt;
    while(tt--)
    {
        ll a,b,c;
        cin >> a >> b >> c;
        ll z = max({a,b,c});
        if(a==b && a==c) cout << "1 1 1";
        else if(a==b) cout << "0 0 1";
        else if(b==c) cout << "1 0 0";
        else if(a==c) cout << "0 1 0";
        else{
            if(a == z) cout << "1 0 0";
            else if(b==z) cout << "0 1 0";
            else cout << "0 0 1";
        }
        cout << endl;
    }
    return 0;
}