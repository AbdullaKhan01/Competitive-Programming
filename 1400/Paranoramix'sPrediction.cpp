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
bool isPrime(ll n){
	bool flag = true;
	for(int i=2;i<=(n/2);i++){
		if(n%i==0){
			flag = false;
			break;
		}
	}
	return flag;
}
int main(){
    ll a,b;
    cin >> a >> b;
    bool flag = false;
    for(int i=a+1;i<=b;i++){
    	if(isPrime(i)){
    		if(i==b){
    			flag = true;
    		}
    		break;
    	}
    }
    cout << (flag?"YES":"NO")<<endl;
    return 0;
}