#include<bits/stdc++.h>
#define ll long long
using namespace std; 

int main(){ 
    int tt;
    cin >> tt;
    while(tt--){
        int n;
        cin >> n;
        cout << (n%3==0?"Second":"First")<<endl;
    } 
    return 0;
}