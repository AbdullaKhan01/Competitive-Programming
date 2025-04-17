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
    ll n,k;
    cin >> n >> k;
    vector<bool> is_prime(n+1, true);
    vi primes;
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i <= n; i++) {
	    if (is_prime[i]) {
	    	primes.push_back(i);
	        for (int j = i * i; j <= n; j += i)
	            is_prime[j] = false;
	    }
	}

	int cnt = 0;
	// for(auto it:primes){
	// 	cout << it << " ";
	// }
	// cout << endl;
	for(int i=2;i<=n;i++){
		int f = 0;
		for(int j=1;j<primes.size();j++){
			if(is_prime[i] && i == (primes[j] + primes[j-1] + 1)){
				f = 1;
			}
		}
		cnt+=f;
		// cout << i << " " << cnt << endl;
	}
	// cout << cnt << endl;
	cout << (cnt>=k?"YES":"NO") << endl;

    return 0;
}