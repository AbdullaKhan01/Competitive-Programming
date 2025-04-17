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
const int MAX = (3 * 1e5) + 5;

// int dp[MAX][2]={0};
int solve(vi &arr,int index,bool flag){
	if(index>=arr.size()) return 0;

	int fact = 1;
	if(flag == false) fact*=-1;
	int take = (arr[index] * fact) + solve(arr,index+1,!flag);
	int notTake = solve(arr,index+1,flag);
	return max(take,notTake);
}
// int solveMem(vi &arr,int index,bool flag){
// 	if(index>=arr.size()) return 0;
// 	if(dp[index][flag]!=-1){
// 		return dp[index][flag];
// 	}
// 	int fact = 1;
// 	if(flag == false) fact*=-1;
// 	int take = (arr[index] * fact) + solveMem(arr,index+1,!flag);
// 	int notTake = solveMem(arr,index+1,flag);
// 	return dp[index][flag]=max(take,notTake);
// }
int solveTab(vi &arr,int n,vector<vector<int>>&dp){

	for(int index=n;index>=0;index--){
		for(int flag=0;flag<=1;flag++){
			int fact = 1;
			if(flag == 0) fact*=-1;
			int take = (arr[index] * fact) + dp[index+1][!flag];
			int notTake = dp[index+1][flag];
			dp[index][flag]=max(take,notTake);
		}
	}
	return max(dp[0][0],dp[0][1]);
}
signed main(){
	
   	ll tt;
   	cin >> tt;
   	while(tt--)
   	 {
   	    int n,q;
   	    cin >> n >> q;
   	  	vi arr(n);
   	  	input(arr);
   	  	// int ans = solve(arr,0,1);
   	  	// for(int i=0;i<n;i++){
   	  	// 	dp[i][0] = dp[i][1] = 0;
   	  	// }
   	  	// int ans = solveMem(arr,0,1);
   	  	// int ans2 = solveMem(arr,0,0);
   	  	vector<vector<int>>dp(n+1,vector<int>(2,0));
   	  	int ans = solveTab(arr,arr.size()-1,dp);
   	  	cout << ans << endl;
   	  	// cout << max(ans,ans2) << endl;   
   	 } 
    return 0;
}