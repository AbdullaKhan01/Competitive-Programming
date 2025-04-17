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
long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
bool isPrime(long long x) {
    for (int d = 2; d * d <= x; d++) {
        if (x % d == 0)
            return false;
    }
    return x >= 2;
}
signed main(){

	int n;cin>>n;
	int ans = 0;
	vector<int>visited(n,0);
 	for(int i=2;i<n;i++){
 		if(visited[i]) continue;
		bool flag = false;
		int pow = -1;
		for(int j = 1;j<n;j++){
			if((binpow(i,j)-1)%n == 0){
				pow = j;
				break;
			}
		}
		flag = (pow == n-1);
		for(int a = i;a<n;a+=i){
			if(visited[a]) continue;
			visited[a] = true;
			ans+=(flag == true);
		}
 	}   
 	cout << ans << endl;
    return 0;
}