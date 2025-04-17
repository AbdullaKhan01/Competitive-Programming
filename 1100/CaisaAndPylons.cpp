#include<bits/stdc++.h>
#define ll long long
using namespace std; 

int main(){ 
    int n;
    cin >>n;
    vector<int> ans(n);
    for(auto &a:ans){
        cin >> a;
    }
    ll z = ans[0];
    ll energy = 0;
    for(int i=1;i<n;i++){
        if(ans[i]-ans[i-1] >= energy){
            z+=ans[i]-ans[i-1]-energy;
            cout << z << " " << energy << endl;
            energy = 0;
        }
        else{
            cout << z << " " << energy << endl;
            energy+=abs(ans[i]-ans[i-1]);
        }
    }
    cout << z << endl;
    return 0;
}