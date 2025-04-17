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
vector<int> factorization(int n){
	vector<int> ans;
	for(int i=2;i*i<=n;i++){
		if(n%i == 0){
			ans.pb(i);
			ans.pb(n/i);
		}
	}
	sort(all(ans));
	return ans;
}
vector<int> primeFactorization(int n){
	vector<int> ans;
	for(int i=2;i*i<=n;i++){
		while(n%i == 0){
			ans.pb(i);
			n/=i;
		}
	}
	if(n!=1) ans.pb(n);
	return ans;
}
signed main(){
	
    ll tt;
    cin >> tt;
    while(tt--)
    {
        int n;
        cin >> n;
        vi arr = primeFactorization(n);
        int a = arr[0];
        int b=1,c=1;
        int ind = 1;
        for(;ind<arr.size();ind++){
        	b*=arr[ind];
        	if(b!=a){
        		ind++;
        		break;
        	}
        }
        for(;ind<arr.size();ind++){
        	c*=arr[ind];
        }
        if(a == 1 || b==1 || c==1){
        	cout << no << endl;
        }
        else if(a == b || b==c || a==c){
        	cout << no << endl;
        }
        else{
        	cout << yes << endl;
        	cout << a << " " << b << " " << c << endl;
        }
    }
    return 0;
}