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
int smallestPrimeFactor(int n){
	// int p;
	for(int i=2;i*i<=n;i++){
		if(n%i == 0){
			return i;
		}
	}
	return n;
}
signed main(){
	
    ll tt;
    cin >> tt;
    while(tt--)
    {
    	int n,m;
        cin >> n >> m;
        if(m == 1 || n == 1){
        	cout << yes << endl;
        	continue;
        }
        if(n <= m){
        	cout << no << endl;
        }
        else{
        	if(n % 2 == 0){
        		cout << no << endl;
        	}
       	 	else{
        		int l = smallestPrimeFactor(n);
        		if(m >= l){
        			cout << no << endl;
        		}
        		else{
        			cout << yes << endl;
        		}
        	}
        }
    }
    return 0;
}