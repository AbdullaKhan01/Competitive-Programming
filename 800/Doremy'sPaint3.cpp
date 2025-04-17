#include<bits/stdc++.h>
using namespace std; 

int main(){ 
    int tt;
    cin >> tt; 
    while(tt--){
        int n;
        cin >> n;
        set<int> s;
        while(n--){
            int x;cin >> x;
            s.insert(x);
        }
        if(n<=2 || s.size() == 1){
            cout << "YES" << endl;
            continue;
        }
        if(n==3 && s.size() == 2){
            cout << "YES" << endl;
            continue;
        }   
        cout << "NO" << endl;
    }
    return 0;
}