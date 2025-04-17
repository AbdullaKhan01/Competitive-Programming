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
pair<int, int> fib (int n) {
    if (n == 0)
        return {0, 1};

    auto p = fib(n >> 1);
    int c = p.first * (2 * p.second - p.first);
    int d = p.first * p.first + p.second * p.second;
    if (n & 1)
        return {d, c + d};
    else
        return {c, d};
}
int main(){
    ll tt;
    cin >> tt;
    if(tt==0){
    	cout << "0 0 0" << endl;
    	return 0;
    }
    if(tt==1){
    	cout << "1 0 0" << endl;
    	return 0;
    }
    if(tt==2){
    	cout << "1 1 0" << endl;
    	return 0;
    }
    if(tt == 3){
    	cout << "1 1 1" << endl;
    	return 0;
    }
    ll a=1,b=2,c=3;
    // for(int i=5)
    for(int i=5;i<=1000;i++){
    	ll z = fib(i).first;
    	if(fib(i).first == tt){
    		cout << b << " " << b << " " << a;
    	}
    	a = b;
    	b = c;
    	c = z;
    }
    return 0;
}