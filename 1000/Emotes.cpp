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
void run_cases(){
   	ll n,m,k;
   	cin >> n >> m >> k;
   	vi arr(n);
   	input(arr);
   	sort(all(arr));
   	ll ans = 0;
   	if(m<=k){
   		ans+=(arr[n-1]*m);
   	}
   	else{
   		ll z = (arr[n-1]*k)+arr[n-2];
   		ll w = m/(k+1),x=m%(k+1);
   		// cout << z << endl;
   		ans+=(w*z + (x*arr[n-1]));
   	}
   	cout << ans << endl;
}
signed main(){
    run_cases();
    return 0;
}