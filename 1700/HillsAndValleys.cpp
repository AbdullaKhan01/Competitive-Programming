#include<bits/stdc++.h>
#define ll long long
using namespace std; 

int main(){ 
    ll tt;
    cin >> tt;
    while(tt--){
        ll n;
        cin >> n;
        vector<ll> arr(n);
        for(int i=0;i<n;i++){
            cin >> arr[i];
        }
        vector<ll>mp(n,0);
        ll ans =0;
        ll count =0;
        for(int i=1;i<n-1;i++){
            if(arr[i]>arr[i-1] && arr[i]>arr[i+1]
            || (arr[i]<arr[i-1] && arr[i]<arr[i+1]))
            {
                mp[i]++;
                mp[i-1]++;
                mp[i+1]++;
                count++;
            }
            // if(arr[i]>arr[i-1] && arr[i]>arr[i+1])
            // {
            //     mp[i]++;
            //     mp[i+1]++;
            //     count++;
            // }
            // else if (arr[i]<arr[i-1] && arr[i]<arr[i+1])
            // {
            //     mp[i]++;
            //     mp[i-1]++;
            //     count++;
            // }
        }
        ll maxi = 0;
        for(auto i:mp){
            maxi = max(maxi,i);
        }
        cout << count-maxi << endl;
    } 
    return 0;
}
// 10 2 21 10
//  1 2  2  1  