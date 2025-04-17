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
// const int size = 1e5 + 5;
int dp[100005][2] = {0};
signed main(){
	
    int n;
    cin >> n;
    vector<vector<int>>h(2,vector<int>(n));
    for(int i = 0; i < n ; i++){
    	cin >> h[0][i];
    }
    for(int i = 0 ; i < n ; i++){
    	cin >> h[1][i];
    }

    dp[0][0] = h[0][0];
    dp[0][1] = h[1][0];

    for(int x = 1 ; x < n ; x++){
    	for(int y = 0 ; y < 2 ; y++){
    		dp[x][y] = max(dp[x-1][y],h[y][x] + dp[x-1][!y]);
    	}
    }

    cout << max(dp[n-1][0],dp[n-1][1]);
    return 0;
}