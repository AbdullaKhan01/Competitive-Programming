// #include<bits/stdc++.h>
// #define mod 1000000007
// #define mod2 998244353
// #define ceil(a,b) ((a+b-1)/b)
// #define ll long long
// // #define int long long
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
// //**********IMP****************
// //invfact[x-1] = 1/(x-1)!  = x * (1/x!) = x * invfact[x] % mod
// const int N = 1e6; 
// #define PRIME mod
// int fact[N],invfact[N];
// int pw(int a,int p=mod-2){
// 	int result = 1;
// 	while(p>0){
// 		if(p&1)
// 			result = a*result %mod;
// 		a = a * a %mod;
// 		p >>= 1;
// 	}
// 	return result;
// }

// void init(){
// 	int p = PRIME;
// 	fact[0] = 1;
// 	int i;
// 	for(i=1;i<N;i++){
// 		fact[i] = i * fact[i-1]%p;
// 	}
// 	i--;
// 	invfact[i] = pw(fact[i],p-2);
// 	for(i--;i>=0;i--){
// 		invfact[i] = invfact[i+1]*(i+1)%p;
// 	}

// }
// int ncr(int n,int r){
// 	if(r > n || n < 0 || r < 0) return 0;
// 	return fact[n] * invfact[r] % PRIME * invfact[n-r] % PRIME;
// }
#include<stdio.h>
signed main(){
	
    short int a = -48;
    printf("%d\n",a);
    printf("%u\n",a);
    return 0;
}
