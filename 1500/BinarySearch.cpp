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
/*

	INTUITION -> 

	l = 0 , h = n-1

	// mid = (l+h)/2;
	// for l = 0 , h = 4;
	mid = 2
	where do we have to go -> to the left side this means that
	// the number should be > 1 at the position mid

	// no of ways = 2 spots are free for now

	// then where will we go 
	// mid = (l+h) / 2

	for l = 0 , h = 2
	mid = 1

	l = 1 , h = 2
	mid = 1
	l = 2 , h = 2; break out 

	_ 1 _ _

*/

// _ 2 _ _ mid -> 

// VERDICT -> ACCEPTED
ll modAdd(ll a,ll b){
    ll p = (a%mod + b%mod)%mod;
    return p;
}
ll modSub(ll a,ll b){
    ll p = (a%mod - b%mod)%mod;
    if(p<0) p+=mod;
    return p;
}
ll modMul(ll a,ll b){
    ll p = (a%mod * b%mod)%mod;
    return p;
}
signed main(){
	fast_io();
    int n,x,pos;
    cin >> n >> x >> pos;
    int l = x-1;
    int r = n-x;
    int left = 0 , right = n;
    int ans = 1;
    while(left < right)
    {
    	int mid = (left+right)/2;
    	if(mid == pos)
    	{
    		left = mid + 1;
    		continue;
    	}
    	if(mid < pos)
    	{
    		ans = modMul(ans,l--);
    		left = mid + 1;
    	}
    	else
    	{
    		ans = modMul(ans,r--);
    		right = mid;
    	}
    }
    for(int i=l+r;i>0;i--)
    {
    	ans = modMul(ans,i);
    }
    cout << ans << endl;
    return 0;
}