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
    while(tt--)
    {
        ll n;
        cin >> n;
        ll U=0,D=0,R=0,L=0;
        ll x = 0,y=0;
        while(n--){
        	ll a,b;
        	cin >> a >> b;
        	if(a>x){
        		U++;
        	}
        	if(a<x){
        		D++;
        	}
        	if(b>y){
        		R++;
        	}
        	if(b<y){
        		L++;
        	}
        }
        if(U==0 || D==0 || R==0 || L==0){
        	cout << "YES" << endl;
        }
        else{
        	cout << "NO" << endl;
        }
    }
    return 0;
}