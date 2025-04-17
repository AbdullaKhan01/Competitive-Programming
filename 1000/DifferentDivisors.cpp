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
const int N = 1000000;
int primes[N+1];
signed main(){
	
	for(int i=2;i<=N; i++){
		primes[i] = 1;
	}
	vector<int> pr;
	for(int i=2;i<=N;i++){
		if(!primes[i]){
			continue;
		}
		pr.push_back(i);
		for(int j=2*i;j<=N;j+=i){
			primes[j] = 0;
		}
	}

	// for(auto x:pr){
	// 	cout << x << " ";
	// }
	ll tt;
	cin >> tt;
	while(tt--)
	{
		int d;
		cin >> d;

		int p = *upper_bound(pr.begin(),pr.end(),d);
		int q = *upper_bound(pr.begin(),pr.end(),p+d-1);

		cout << p * 1LL * q << endl;    
	}
	

    return 0;
}
//properties of prime numbers
//no of distinct prime fa 