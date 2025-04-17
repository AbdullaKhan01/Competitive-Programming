#include<bits/stdc++.h>
#define ll long long
#define ll long long
#define lli long long int
#define vi vector<int>
#define vll vector<ll>
#define all(x) (x).begin(),(x).end()
#define FOR(i,n) for(i=0;i<n;i++)
using namespace std; 

int main(){
        ll n;
        cin >> n;
        ll a=0,b=0,c=0;
        while(n--){
           ll x,y,z;
            cin >> x >> y >> z;
            a+=x,b+=y,c+=z;
        }
        if(a==0 && b==0 &&c== 0){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    return 0;
}