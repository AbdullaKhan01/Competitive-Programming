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
#define FOR(i,n) for(int i=0;i<n;i++)
#define print(x) cout << (x); 
using namespace std; 

int main(){
    ll tt;
    cin >> tt;
    while(tt--)
    {
        string s;cin >> s;
        int a = s[1]-'0';
        char b = s[0];
        FOR(i,8){
            if(i+1==a) continue;
            cout << b << i+1 << '\n';
        }
        for(char i='a';i<='h';i++){
            if(i==b) continue;
            cout << i << a << '\n';
        }
    }
    return 0;
}