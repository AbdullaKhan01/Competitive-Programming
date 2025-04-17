#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
     //write here 
      int tt;
      cin >> tt;
      while(tt--){
        ll a;
        cin >> a;
        if(a%2==0){
            cout << a/2 << " " << a/2 << endl;
            continue;
        }
        else{
            ll x = a;
            ll y = 2;
            while(true){
                if(x%y==0){
                    cout << x << " " << y << endl;
                    break;
                }
                else{
                    x--;y++;
                }
            }
        }
      }
     return 0;
}