// #include<bits/stdc++.h>
// #define mod 1000000007
// #define mod2 998244353
// #define ceil(a,b) ((a+b-1)/b)
// #define floor(a,b)((a-b+1)/b)
// #define fast_io() ios::sync_with_stdio(0);cin.tie(0);
// #define ll long long
// #define int long long
// #define vi vector<int>
// #define all(x) (x).begin(),(x).end()
// #define rall(x) (x).rbegin(),(x).rend()
// #define input(x) for(auto &a:x) cin >> a;
// #define output(x) for(auto a:x) cout << a <<" ";
// #define rep(i,a,n) for(int i=(a);i<n;i++)
// #define pb push_back
// #define ppb pop_back
// #define pf push_front
// #define ppf pop_front
// #define ff first
// #define ss second
// #define si set<int>
// #define pii pair<int,int>
// #define mii map<int,int>
// #define msi map<string,int>
// #define yes "YES"
// #define no "NO"
// #define endl '\n'
// using namespace std; 
// /* 
// for fast input output use printf and scanf;
// */
// int n,k;
// ll modAdd(ll a,ll b){
//     ll p = (a%mod + b%mod)%mod;
//     return p;
// }
// ll modSub(ll a,ll b){
//     ll p = (a%mod - b%mod)%mod;
//     if(p<0) p+=mod;
//     return p;
// }
// ll modMul(ll a,ll b){
//     ll p = (a%mod * b%mod)%mod;
//     return p;
// }
// void solve()
// {
// 	cin >> n >> k;
// 	vector<vector<int>>dp(n+1,vector<int>(k+1,0));
// 	dp[0] = vector<int>(k+1,1);
// 	// dp[1][1] = 1;
// 	for(int i=1;i<=n;i++){
// 		for(int j=1;j<=k;j++){			
// 				if(i>=j){
// 					dp[i][j] += dp[i-j][j];
// 					dp[i][j] += dp[i][j-1];
// 				}
// 		}
// 	}
// 	// for(int i=1;i<=n;i++){
// 	// 	for(int j=1;j<=k;j++){
// 	// 		cout << i << " " << j << " " << dp[i][j] << endl;
// 	// 	}
// 	// }
// 	cout << dp[n][k] << endl;
// }
// signed main(){
// 	fast_io();
//     int tt = 1;
//     cin >> tt;
//     while(tt--)
//     {
//     	solve();
//     }
//     return 0;
// }


// C++ code of finding the bellNumber
// using Memoization 

#include <iostream>
#include <vector>

using namespace std;

// Function to compute Stirling numbers of
// the second kind S(n, k) with memoization

int stirling(int n, int k, vector<vector<int>>& memo) {
  
    // Base cases
    if (n == 0 && k == 0) return 1;
    if (k == 0 || n == 0) return 0;
    if (n == k) return 1;
    if (k == 1) return 1;

    // Check if result is already computed
    if (memo[n][k] != -1) return memo[n][k];

    // Recursive formula
    memo[n][k] = k * stirling(n - 1, k, memo) + 
    stirling(n - 1, k - 1, memo);
    return memo[n][k];
}

// Function to calculate the total number of 
// ways to partition a set of `n` elements
int countP(int n, int k) {
  
    // Initialize memoization table with -1
    vector<vector<int>> memo(n + 1, vector<int>(n + 1, -1));
    return stirling(n, k, memo);
}

int main() {
  
    int n = 5, k = 2;
    int result = countP(n, k);
    cout << result << endl;

    return 0;
}