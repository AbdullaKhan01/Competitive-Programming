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

// // Q) Find no of N length strings that does
// // not contain the string "0100" as a 

// // 1. subsequence

// // int n;
// // string t = "0100";
// // int dp[100100][5];
// // int rec(int level,int match)
// // {
// // 	//pruning
// // 	if(match == 4) return 0;
// // 	//base case
// // 	if(level == n)
// // 	{
// // 		return 1;
// // 	}
// // 	//cache check
// // 	if(dp[level][match] != -1)
// // 	{
// // 		return dp[level][match];
// // 	}
// // 	//compute
// // 	int ans = rec(level+1,match+1) + rec(level+1,match);
// // 	//save and return 
// // 	return dp[level][match] = ans;
// // }

// // 2. substring
// // int n;
// // int dp[100100][8];
// // int rec(int level,int lastthree)
// // {
// // 	//pruning

// // 	//base case
// // 	if(level == n)
// // 	{
// // 		return 1;
// // 	}
// // 	//cache check
// // 	if(dp[level][lastthree] != -1)
// // 	{
// // 		return dp[level][lastthree];
// // 	}
// // 	//compute
// // 	int ans = 0;
// // 	if(level >= 3 && lastthree == 2) // 010
// // 	{
// // 		// don't allow transition to 0
// // 		ans = rec(level+1,5);
// // 	}else{
// // 		// add a zero
// // 		ans = rec(level+1,(lastthree<<1|0)&7);
// // 		ans += rec(level+1,(lastthree<<1|1)&7);
// // 	}
// // 	//save and return
// // 	return dp[level][lastthree] = ans;
// // }

// // 2. substring
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
// int n;
// string t = "0100";
// int dp[100100][5];
// int rec(int level,int match)
// {
// 	//pruning
// 	if(match == 4)
// 	{
// 		return 0;
// 	}
// 	//base case
// 	if(level == n)
// 	{
// 		return 1;
// 	}
// 	//cache check
// 	if(dp[level][match] != -1)
// 	{
// 		return dp[level][match];
// 	}

// 	//compute
// 	int ans = 0;
// 	if(match == 0){
// 		ans = modAdd(rec(level+1,0),rec(level+1,1));
// 	}else if(match == 1){
// 		ans = modAdd(rec(level+1,1),rec(level+1,2));
// 	}else if(match == 2){
// 		ans = modAdd(rec(level+1,3),rec(level+1,0));
// 	}else if(match == 3){
// 		ans = modAdd(rec(level+1,4),rec(level+1,2));
// 	}

// 	//save and return
// 	return dp[level][match] = ans;

// }
// void solve()
// {
// 	// cin >> n;
// 	memset(dp,-1,sizeof(dp));
// 	cout << rec(0,0) << endl;
// }
// long long binpow(long long a, long long b, long long m=1e9+7) {
//     a %= m;
//     long long res = 1;
//     while (b > 0) {
//         if (b & 1)
//             res = res * a % m;
//         a = a * a % m;
//         b >>= 1;
//     }
//     return res;
// }
// void solve2()
// {
// 	cout << binpow(2,n) - binpow(2,n-3)  << endl;
// 	cout << endl; 	
// }
// signed main(){
// 	fast_io();
//     int tt = 1;
//     cin >> tt;
//     while(tt--)
//     {
//     	// int n;
//     	cin >> n;
//     	solve();
//     	solve2();
//     }
//     return 0;
// }	

// // 2^n strings 
// //  
// // 

