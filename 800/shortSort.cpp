#include<bits/stdc++.h>
using namespace std; 

int main(){ 
    int tt;
    cin >> tt;
    while(tt--){
        string s;cin >> s;
        if(s == "cba" || s == "acb" || s == "abc" || s=="bac"){
            cout << "YES" << endl;
            continue;
        }
        cout << "NO" << endl;        
    } 
 return 0;
}