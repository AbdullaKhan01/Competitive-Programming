#include<bits/stdc++.h>
#define ll long long
// #define int long long
using namespace std; 

signed main(){
    ll tt = 1;
    cin >> tt;
    while(tt--) {
        int n; 
        cin >> n;
        // cout << n << endl;
        // vector<vector<int>>vec(n,vector<int>(n,-1));
        vector<string>vec(n);

        for(int i = 0; i < n; i++) {
            cin >> vec[i];
        }

        int row=0;
        bool milgya = false;
        int count = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
            	// cout << vec[i][j] << " ";
                if(vec[i][j] == '1') {
                    count++;
                    milgya = true;
                }
            }
            // cout << endl;
            if(milgya) {
                row = i;
                break;
            }
        }
        // cout << milgya << endl;
        int c2 = 0;
        for(int i = 0; i < n; i++) {
            if(vec[row+1][i] == '1'){
                c2++;
            }
        }
        if(count == c2) cout << "SQUARE\n";
        else cout << "TRIANGLE\n";

 
    }
    return 0;
}