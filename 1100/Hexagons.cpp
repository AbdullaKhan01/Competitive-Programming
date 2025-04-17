#include<bits/stdc++.h>
#define ll long long
using namespace std; 

int main(){ 
    ll n;
    cin >> n;
    ll ans = 1;
    ans += (n*(12+((n-1)*6)))/2;
    cout << ans << endl;
    return 0;
}