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
    ll n;
    cin >> n;
    if(n==1){
    	cout << 1 << endl << 1 << endl;
    	return 0;
    }
    if(n==2){
    	cout << 1 << endl << "1 1" << endl;
    	return 0;
    }
    vector<int> is_prime(n+2, 1);
	is_prime[0] = is_prime[1] = 0;
	for (int i = 2; i * i <= n+1; i++) {
	    if (is_prime[i] == 1) {
	        for (int j = i * i; j <= n+1; j += i)
	            is_prime[j] = 2;
	    }
	}
	cout << 2 << endl;
	for(int i=2;i<=n+1;i++){
		cout << is_prime[i] << " ";
	}
    return 0;
}