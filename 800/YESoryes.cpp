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
    ll tt;
    cin >> tt;
    while(tt--){
    string s;
    cin >> s;
    cout <<(((s[0]=='Y'||s[0]=='y')&&(s[1]=='E'||s[1]=='e')&&(s[2]=='S'||s[2]=='s'))?"YES":"NO")<<endl;
    }
    return 0;
}