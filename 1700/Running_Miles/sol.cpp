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
The Expression is bi1 + bi2 + bi3 - (r-l) should be maximized

lets say we get such l and r then what can we say
about the subarray l to r ??

b[l] and b[r] will be the two maximum elements out of the 
three otherwise we can further reduce the size of array
and get better answer

now for any array l to r 
we know bi1 = b[l] , bi3 = b[r]
only need to find bi2 = b[middle element]

so for any l r we can say the expression will become

b[l] + b[m] + b[r] - (r - l)
(b[l] + l) + b[m] + (b[r] - r)

// so either for every l r we can find b[m]
// or for every b[m] we can find l r 

second method is more time optimized using prefix sum array

*/
void solve()
{
	int n;cin >>n;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
	}	
	vector<int> suff(n),pref(n);
	suff[0] = a[0];
	pref[n-1] = a[n-1] - n + 1;
	for(int i=1;i<n;i++){
		suff[i] = max(suff[i-1],a[i-1] + i - 1);
	}
	for(int i=n-2;i>=0;i--){
		pref[i] = max(pref[i+1],a[i+1] - i - 1);
	}
	int ans = 0;
	for(int i = 1;i<n-1;i++){
		ans = max(ans,suff[i] + a[i] + pref[i]);
	}
	cout << ans << endl;
}
signed main(){
	fast_io();
    int tt = 1;
    cin >> tt;
    while(tt--)
    {
    	solve();
    }
    return 0;
}