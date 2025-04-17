#include<bits/stdc++.h>
#define ll long long
using namespace std; 

int main(){ 
    int tt;
    cin >> tt;
    while(tt--){
        int n;
        cin >> n;
        vector<ll> arr(n);
        for(auto &a:arr){
            cin >> a;
        }
        int a=arr[0];
        int ans = 0;
        ll last = arr[0];
        for(int i=1;i<n;i++){
            if(arr[i]%2==0 && last%2==0 || arr[i]%2!=0 && last%2!=0){
                ans = max(ans,a);
                a = arr[i];
            }
            if(arr[i]>=0){
                
            }

        }
    } 
    return 0;
}