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
    string tt;
    cin >> tt;
    ll count=0,a=10;
    if(tt.size()==1){
        cout << 0 << endl;  
        return 0;
    }
    while(a>=10){
        a=0;
        for(int i=0;i<tt.size();i++)
        {
            a+=(tt[i]-48);
        }
    tt=to_string(a);
    count++;
    }
    cout << count << endl;
}