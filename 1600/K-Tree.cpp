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
const int M = 1e9 + 7;
int n,k,d;
int dp[105][2]; // pos,flag

int calc(int n,int flag){
	if(n == 0) return flag;
	if(n < 0 ) return 0; // invalid route

	if(dp[n][flag] != -1) return dp[n][flag];

	int ans = 0;

	for(int i = 1 ; i <= k ; i++)
	{
		ans = (ans + calc(n-i,flag || (i>=d))) % M;
	}	
	return dp[n][flag] = ans;
}

// int solve(int n,int k,int d,int flag){
// 	if(n == 0) return flag;
// 	if(n < 0 ) return 0;
// 	int ans = 0;
// 	for(int i = 1; i < k ;i++){


// 		ans = modAdd(ans,solve(n-i,k,d,flag||(i>=d)));
// 		if(i < k){
// 			ans = modAdd(ans,solve(n-i,k,d,flag));
// 		}
// 		else{
// 			flag = true;
// 			ans = modAdd(ans,1 + solve(n-i,k,d,flag));
// 		}
// 	}
// 	return ans;
// }
signed main(){

    cin >> n >> k >> d;
    for(int i=0; i < 105 ; i++){
    	dp[i][0] = -1;
    	dp[i][1] = -1;
    }
    cout << calc(n,0);
    return 0;
}