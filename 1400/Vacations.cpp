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
const int INF = 1e9;
int a[105];
int dp[105][3]; // position,last day activity
/*
0->rest
1->contest
2->sport
*/
signed main(){
	
    int n;
    cin >> n;
    for(int i=1;i <=n;i++){
    	cin >> a[i];
    }

    dp[0][0] = 0; // no rest till 0th day

    for(int i = 1 ; i <= n ; i++){
    	dp[i][0] = 1 + min({dp[i-1][0],dp[i-1][1],dp[i-1][2]});

    	if( a[i] % 2 == 1 ){
    		dp[i][1] = min(dp[i-1][0],dp[i-1][2]);
	    }
	    else{
	    	dp[i][1] = INF;	
	    } 

    	if( (a[i] / 2) == 1 ){
    		dp[i][2] = min(dp[i-1][0],dp[i-1][1]);
	    }
	    else{
	    	dp[i][2] = INF;	
	    } 
	    
    }
    cout << min({dp[n][0],dp[n][1],dp[n][2]}); 
    // minimum rest till nth day
    return 0;
}