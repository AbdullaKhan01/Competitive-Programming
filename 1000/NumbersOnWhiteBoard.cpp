#include<bits/stdc++.h>
using namespace std; 

int main(){ 
    int tt; cin >> tt;
    while(tt--){
        int n; cin >> n;
        cout << 2 << endl;
        int a = n, b = n-1;
        cout << a << " " << b-- << endl;
        n--;
        while(n-- && n > 0){
            cout << a-- << " " << b-- << endl;
        }
    } 
    return 0;
}