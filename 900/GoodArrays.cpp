#include<bits/stdc++.h>
#define ll long long
using namespace std; 
int main(){ 
    int tt;
    cin >> tt;
    while(tt--){
        int n;
        cin >> n;
        if(n==1){
            ll x;cin >> x;
            cout << "NO" <<endl;
            continue;
        }
        int k = n;
        ll a = (n*(n+1))/2;
        ll sum = 0;
        ll count = 0;
        bool found = false;
        while(n--){
            ll x;
            cin >> x;
            count+=(x==1);
            if(!found)
                sum+=x;
            if(sum>=a){
                found = true;
            }
        }
        if(found){
            cout << "YES" << endl;
            continue;
        }
        else{
        ll y = sum - (2*count);
        if(y>=(k-count)){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
        }
    }
    return 0;
}