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
// int n;
// string s;
// vector<int> c;
// int dp[100100][4];
// string temp = "hard";
// // 0 h
// // 1 a
// // 2 r
// // 3 d
// int rec(int level,int find)
// {
// 	//pruning
// 	if(find == 4) return 1e18;
// 	//base case
// 	if(level == n) return 0;
// 	//cache check
// 	if(dp[level][find] != -1)
// 	{
// 		return dp[level][find];
// 	} 
// 	//compute
// 	int ans = 0;
// 	if(s[level] == temp[find])
// 	{
// 		int one = rec(level+1,find) + c[level];
// 		int two = rec(level+1,find+1);
// 		ans = min(one,two);
// 	}
// 	else ans = rec(level+1,find);
// 	//save and return 
// 	return dp[level][find] = ans;
// }

// void solve()
// {
// 	cin >> n;
// 	cin >> s;
// 	c.resize(n);
// 	for(int i=0;i<n;i++)
// 	{
// 		cin >> c[i];
// 	}
// 	memset(dp,-1,sizeof(dp));
// 	cout << rec(0,0) << endl;
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