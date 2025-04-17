#include<bits/stdc++.h>
#define mod 1000000007
#define mod2 998244353
#define ll long long
#define ll long long
#define lli long long int
#define vi vector<int>
#define vll vector<ll>
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define input(x) for(auto &a:x) cin >> a;
#define llmax(a,b) max(1LL*(a),1LL*(b))
#define output(x) for(auto a:x) cout << a <<" ";
#define FOR(i,n) for(i=0;i<n;i++)
using namespace std; 

int main(){
    vector<vector<int>>arr(8,vector<int>(8,0));
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            char x;cin >> x;
            arr[i][j] = (x=='B');
        }
    }
    int count;
    bool flag = true;
    for(int i=0;i<8;i++){
        count = 0;
        for(int j=0;j<8;j++){
            if(arr[i][j]^arr[i][(j+1)%8] == 0){
                count++;
            }
        }
        if(count >=2 ) {flag = false;break;} 
    }
    cout << (flag?"YES":"NO")<<endl;
    return 0;
}