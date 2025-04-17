#include<bits/stdc++.h>
#define ll long long
using namespace std; 

int main(){ 
    int n;
    cin >> n;
    vector<int> ans(n);
    for(auto &a:ans){
        cin >> a;
    }
    int a=1,count=1;
    for(int i=1;i<n;i++){
        if(ans[i]>ans[i-1]){
            count++;
        }
        else{
            count = 1;
        }
        a = max(a,count);
    }
    cout << a << endl;
    return 0;
}