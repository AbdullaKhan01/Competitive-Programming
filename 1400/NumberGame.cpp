#include<bits/stdc++.h>
#define mod 1000000007
#define mod2 998244353
#define ceil(a,b) ((a+b-1)/b)
#define floor(a,b)((a-b+1)/b)
#define fast_io() ios::sync_with_stdio(0);cin.tie(0);
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
/* 
for fast input output use printf and scanf;
*/
//TC of this precompute is O(NlogN)
bool isPrime(long long x) {
    for (int d = 2; d * d <= x; d++) {
        if (x % d == 0)
            return false;
    }
    return x >= 2;
}
signed main(){
	fast_io();
    ll tt;
    cin >> tt;
    while(tt--)
    {
        int n;
        cin >> n;
        string a = "Ashishgup";
        string b = "FastestFinger";
        if(n == 1){
        	cout << b << endl;
        	continue;
        }
        if(n == 2){

        	cout << a << endl;
        	continue;
        }
        else if(n % 2 != 0){
        	cout << a << endl;
        }
        else{
        	int k = n;
        	while(k % 2 == 0){
        		k/=2;
        	}
        	int m = n / 2;
        	// if(k <= 1){
        	// 	cout << b << endl;
        	// }
        	if(isPrime(m) || k <= 1){
        		cout << b << endl;
        	}
        	else{
        		cout << a << endl;
        	}
        }
    }


    return 0;
}