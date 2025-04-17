#include<bits/stdc++.h>
#define mod 1000000007
#define mod2 998244353
#define ceil(a,b) ((a+b-1)/b)
#define floor(a,b)((a-b+1)/b)
#define fast_io() ios::sync_with_stdio(0);cin.tie(0);
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
/* 
for fast input output use printf and scanf;
*/
struct Bitset
{
	void set(int &n,int i){n |= (1LL<<i);}
	void clear(int &n,int i){n &= ~(1LL<<i);}
	bool check(int n,int i){return (n>>i) & 1;}
	void flip(int &n,int i){n ^= (1LL<<i);}
	void flipMSB(int &n){n &= (n-1);}
	int findMSB(int n){return 64 - __builtin_clz(n);}
	void reverse(int &n,int i){}
	bool isPowerof2(int n){return !((n)&(n-1));}
	int count(int n)
	{
		//does not work for negative numbers
		//uncomment for negative numbers
		return __builtin_popcountll(n);

		// int ans = 0;
		// int x = n;
		// while(x)
		// {
		// 	ans++;
		// 	x = x & (x-1);
		// }
		// return ans;
	}
};
signed main(){
	fast_io();
    
    return 0;
}