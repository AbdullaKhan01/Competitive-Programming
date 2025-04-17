#include<bits/stdc++.h>
#define ll long long
using namespace std; 

int main(){ 
    int tt;
    cin >> tt;
    while(tt--){
        int n;
        cin >> n;
        vector<ll> ans(n);
        for(auto &a:ans){
            cin >> a;
        }
        sort(ans.begin(),ans.end());
        ll num = 1,count=0;
        for(int i=0;i<n;i++){
            if(ans[i]<num){
            }
            else if(ans[i]==num){
                num++;
            }
            else{
                count+=(ans[i]-num);
                num++;
            }
        }
        cout << count << endl;    
    } 
    /*
    1 1 1 4 4 5
    0  
    */
    return 0;
}