#include<bits/stdc++.h>
#define ll long long
#define ll long long
#define lli long long int
#define vi vector<int>
#define vll vector<ll>
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define input(x) for(auto &a:x) cin >> a;
#define output(x) for(auto a:x) cout << a <<" ";
#define FOR(i,n) for(i=0;i<n;i++)
using namespace std; 

int main(){
        vector<vll> arr(3,vll(3,1));
        vector<vector<int>> ans(3,vector<int>(3,0));
        for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
        {
        cin >> ans[i][j];
        ans[i][j]%=2;
        }
        
        for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
        {
            if(ans[i][j]){
            if(i+1 < 3) arr[i+1][j]^=1;
            if(j+1 < 3) arr[i][j+1]^=1;
            if(i-1 >= 0) arr[i-1][j]^=1;
            if(j-1 >= 0) arr[i][j-1]^=1;
            arr[i][j]^=1;
            }
        }

        for(auto i:arr){
            for(auto j:i){
                cout << j;
            }
            cout << endl;
        }
    return 0;
}