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
    ll tt;
    cin >> tt;
    while(tt--)
    {
        ll n,a;
        cin >> n >> a;
        vll arr(n);
        input(arr);
        ll mx = -1;
        ll count = 1;
        for(int i=1;i<arr.size();i++){
            if(arr[i]<arr[i-1]){
                count++;
            }
            else{
                count = 1;
                mx=max(mx,count);
            }
        }
        mx=max(mx,count);
    cout << ((mx<=a)?"YES":"NO")<<endl;
    }
    return 0;
}