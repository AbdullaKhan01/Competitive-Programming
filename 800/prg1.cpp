#include<bits/stdc++.h>
using namespace std; 

int main(){ 
    int tt;
    cin >> tt; 
    while(tt--){
        int n;
        cin >> n;
        int k = n;
        set<int> s;
        while(n--){
            int x;cin >> x;
            s.insert(x);
        }
        // for(auto i:s){
        //     cout << i << endl;
        // }
        // cout << s.size() << " " << n << endl;
        if(s.size() == 1 || s.size()==2 && k%2==0){
            cout << "Yes" << endl;
            continue;
        }
        if(s.size()==2 && k==3){
            cout << "Yes" << endl;
            continue;
        }   
        cout << "No" << endl;
    }
    return 0;
}
/*
7
5
1 1 1 2 1
4
1 2 3 2
4
1 1 2 2
4
1 1 2 3
5
1 2 1 2 1
5
1 1 3 3 1
5
1 2 1 2 3
*/