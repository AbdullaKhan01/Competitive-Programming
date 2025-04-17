#include<bits/stdc++.h>
#define ll long long
using namespace std; 

int main(){ 
    int n;
    cin >>n;
    ll a = 2;
    ll ans = 0;
    while(n--){
        ans+= a;
        a*=2;
    }
    cout << ans << endl;
    return 0;
}