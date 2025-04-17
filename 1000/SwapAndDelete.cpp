#include<bits/stdc++.h>
#define mod 1000000007
#define mod2 998244353
#define ceil(a,b) ((a+b-1)/b)
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
/*ACCEPTED*/
int main(){
    ll tt;
    cin >> tt;
    while(tt--)
    {
        string s;
        cin >> s;
        ll one = count(all(s),'1');
        ll zero = count(all(s),'0');
        ll a=0,b=0;
        ll ans = 0;
        for(int i=s.size()-1;i>=0;i--){
        	ll reqOne = zero-b;
        	ll reqZero = one-a;
        	if(one>=reqOne && zero>=reqZero){
        		break;
        	}
        	ans++;
        	a+=(s[i]=='1');
        	b+=(s[i]=='0');
        }
        cout << ans << endl;
    }
    return 0;
}