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
    ll sum = 0;
    while(tt--)
    {
        ll a,b;
        cin >> a >> b;
        if(a>b) sum++;
        if(a<b) sum--;
    }
    if(sum>0) cout << "Mishka";
    else if(sum<0) cout << "Chris";
    else cout << "Friendship is magic!^^";
    cout << endl;
    return 0;
}