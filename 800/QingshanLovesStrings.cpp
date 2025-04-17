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
    ll tt;
    cin >> tt;
    while(tt--)
    {
        ll n,p;
        cin >> n >> p;
        string a,b;
        cin >> a >> b;
        int i=0;
        int m,c=0;
        bool x=true,y=true;
        FOR(i,n-1){
            if((a[i]-48) ^ (a[i+1]-48)) x=false,m=i,c++;
        }
        i=0;
        FOR(i,p-1){
            if((b[i]-48) ^ (b[i+1]-48)) y=false;     
        }
        if(x){
            cout << "YES" << endl;
        }
        else
        {
            if(!y){
                cout << "NO" << endl;
            }
            else{
                if(b[0]!=a[m]){
                    cout << "YES" << endl;
                }
                else{
                    cout << "NO" << endl;
                }
            }
        }

    }
    return 0;
}