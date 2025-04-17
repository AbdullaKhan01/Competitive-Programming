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
signed main(){
	
 	ll tt;
 	   cin >> tt;
 	   while(tt--)
 	   {
 	       int n;
 	       cin >> n;
 	       vi arr(n);
 	       input(arr);
 	       vi dp(n,1);
 	       dp[0] = 0;
 	       vi dp2(n,1);
 	       dp2[n-1] = 0;
 	       for(int i=1;i<n-1;i++){
 	    		if(abs(arr[i]-arr[i-1])<abs(arr[i]-arr[i+1])){
 	    			dp[i+1] = dp[i]+abs(arr[i]-arr[i+1]);
 	    		}
 	    		else dp[i+1] = 1 + dp[i];   	
 	       }
 	       for(int i=n-2;i>0;i--){
 	       		
 	       		if(abs(arr[i]-arr[i-1]) < abs(arr[i]-arr[i+1])){
 	       			dp2[i-1] = dp2[i] + 1;
 	       		}
 	       		else{
 	       			dp2[i-1] = dp2[i] + abs(arr[i]-arr[i-1]);
 	       		}
 	       }
 	       int m;
 	       cin >> m;
 	       while(m--){
 	       		int a,b;
 	       		cin >> a >> b;
 	       		a--,b--;
 	       		if(a<b){
 	       			cout << dp[b] - dp[a] << endl;
 	       		}
 	       		else{
 	       			cout << dp2[b] - dp2[a] << endl;
 	       		}
 	       }
 	   }   
    return 0;
}