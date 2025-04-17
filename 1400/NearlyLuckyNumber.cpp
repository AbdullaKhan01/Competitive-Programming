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
    string s;
    cin >> s;
    ll ans = 0;
    for(int i=0;i<s.size();i++){
    	int z = s[i]-48;
    	ans+=(z==4 || z==7);
    }
    cout << ((ans==4 || ans==7)?"YES":"NO")<<endl;
    return 0;
}