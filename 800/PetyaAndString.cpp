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
    string tt,jj;
    cin>> tt>>jj;   
    int flag = 0;
    for(int j=0;j<tt.size();j++){
        if(tolower(tt[j])!=tolower(jj[j])){
            if(tt[j] > jj[j]){
                flag = -1;
            }
            else{
                flag = 1;
            }
            break;
        }
    }
    cout << flag << endl;
    return 0;  
}  