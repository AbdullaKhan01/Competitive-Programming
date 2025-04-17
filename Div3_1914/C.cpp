#include<bits/stdc++.h>
#define ll long long
#define int long long
#define yes "YES"
#define no "NO"
using namespace std; 

signed main(){
    ll tt = 1;
    cin >> tt;
    while(tt--) {
        int n, m ,k;
        cin >> n >> m >> k;
        vector<int>v1(n);
        vector<int>v2(m);
        for(int i = 0; i < n; i++)
            cin >> v1[i];       
        for(int i = 0; i < m; i++){
            cin >> v2[i];
        }
        vector<bool>vis1(k+1,false);
        vector<bool>vis(k+1,false);
        int s1 = 0, s2 = 0;
        for(int i = 0; i < n; i++){
            if(v1[i] <= k && vis[v1[i]] == false ){
                s1++;
                vis[v1[i]] = true;
            }
        }
        for(int i = 0; i < m; i++){
            if(v2[i] <= k && vis1[v2[i]] == false ){
                s2++;
                vis1[v2[i]] = true;
            }
        }
        // cout << s1 << " " << s2 << endl;
        if(s1 < (k/2) || s2 < (k/2)) {
            cout << no << endl;
            continue;
        }
        bool check = true;
        for(int i = 1; i <= k; i++) {
            if(vis[i] == false && vis1[i] == false){
                check = false;
                break;
            }
        } 
        if(check) cout << yes << endl;
        else cout << no << endl;


    }
    return 0;
}