#include<bits/stdc++.h>
#define mod 1000000007
#define mod2 998244353
#define ceil(a,b) ((a+b-1)/b)
#define ll long long
#define int long long
#define vi vector<int>
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define input(x) for(auto &a:x) cin >> a;
#define output(x) for(auto a:x) cout << a <<" ";
#define rep(i,a,n) for(int i=(a);i<n;i++)
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define ff first
#define ss second
#define si set<int>
#define pii pair<int,int>
#define mii map<int,int>
#define msi map<string,int>
#define yes "YES"
#define no "NO"
#define endl '\n'
using namespace std; 
const int MAX = 1e5 + 5;
vector<int> primes={1};
vector<int> isPrime(MAX,1);
vector<int> primeFactorization(int n){
	vector<int> ans;
	ans.pb(1);
	for(int i=2;i*i<=n;i++){
		bool flag = false;
		while(n%i == 0){
			flag = true;
			n /= i;
		}
		if(flag) ans.pb(i);
	}
	if(n!=1) ans.pb(n);
	return ans;
}
void init(){
	for(int i=2;i<MAX;i++){
		if(!isPrime[i]) continue;
		primes.pb(i);
		for(int j=i;j<MAX;j+=i){
			isPrime[j] = 0;
		}
	}
}
signed main(){
    ll tt;
    cin >> tt;
    while(tt--)
    {
        int n;
        cin >> n;
        vector<int> ans = primeFactorization(n);
        int ans1 = INT_MAX;
        int k = -1;
       	for(auto it:ans){
       		if(it == 1) continue;
       		k = max({k,it,n/it});
       		// if(it == 1) continue;
       		// int a = it;
       		// int b = n / it;
       		// int lcm1 = n - a;
       		// int lcm2 = n - b;
       		// if(lcm1 <= lcm2 && lcm1 <= ans1){
       		// 	ans1 = lcm1;
       		// 	k = a;
       		// } 
       		// else if(lcm2 <= lcm1 && lcm2 <= ans1){
       		// 	ans1 = lcm2;
       		// 	k = b;
       		// }
       	}
       	// cout << k << endl;
       	if(k == n){
       		cout << 1 << " " << n - 1 << endl;
       	}
       	else cout << k << " " << n - k << endl;
    }
    return 0;
}