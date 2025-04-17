#include<bits/stdc++.h>
using namespace std; 

int main(){ 
    int tt;
    cin >> tt;
    while(tt--){
        int n;
        cin >> n;
        int a=0,b=0;
        for(int i=0;i<n;i++){
            int x;cin >> x;
            if(i%2==0 && x%2!=0){
                a++;
            }
            if(i%2!=0 && x%2==0){
                b++;
            }      
        }
        if(a==b){
            cout << a << endl;
        }
        else{
            cout << -1 << endl;
        }
    } 
    return 0;
}