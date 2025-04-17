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
      for(int i=0;i<n;i++){
        cin >> ans[i];
      }  
      ll a = *min_element(ans.begin(),ans.end());
      ll b = *max_element(ans.begin(),ans.end());
      cout << abs(a-b) << endl;
    } 
    return 0;
}