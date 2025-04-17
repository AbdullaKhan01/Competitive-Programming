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
/*
VERDICT -> ACCEPTED
*/
int main(){
    ll tt;
    cin >> tt;
    while(tt--)
    {
        ll a,b;
        cin >> a >> b;
        vi arr(a);
        input(arr);
        ll m = -1;
        ll s = 0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>b) break;
            m  = max(m,arr[i]-s);
            s  = arr[i]; 
        }
        m = max(m,2*(b-s));
        cout << m << endl;
    }
    return 0;
}