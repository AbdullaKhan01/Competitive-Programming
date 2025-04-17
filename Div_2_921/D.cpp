#include <bits/stdc++.h>
#define ll long long
#define int long long
using namespace std; 

signed main(){
    ll tt = 1;
    cin >> tt;
    while(tt--) {
        int n, x, y;
        cin >> n >> x >> y;
        
        if (x == 0 || y == 0) {
            cout << 0 << endl; 
            continue;
        }
        
        vector<int> vec(n);
        for(auto &i: vec) cin >> i;
        map<pair<int,int>,int>mp;
        int count = 0;
        for(int i = 0; i < n; i++) {
            // int c1 = ;
            // int c2 = ;
            // // pair<int,int>p = make_pair(c1,c2);
            count+=mp[{(x-vec[i]%x)%x,(y+vec[i]%y)%y}];
            mp[{vec[i]%x,vec[i]%y}]++;
        }
        cout << count << endl;
    }
    return 0;
}