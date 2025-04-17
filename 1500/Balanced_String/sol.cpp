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
void solve()
{
	int n;cin >> n;
	string s;cin >> s;

	// let's subtitute 0 with -1 and 1 with 1
	vector<int> a;
	for(auto it : s){
		if(it == '0') a.push_back(-1);
		else a.push_back(1);
	}
	for(int i=1;i<n;i++){
		a[i] += a[i-1];
	}
	map<int,int> mp;
	// if some substring has equal number of 0s and 1s then
	// prefix sum at the starting and ending of the string
	// is same
	int ans = 0;
	mp[0] = -1;
	for(int i=0;i<n;i++){
		int psum = a[i];
		if(mp.find(psum) != mp.end()){
			int length = i - mp[psum];
			ans = max(ans,length);
		}
		else{
			mp[psum] = i;
		}
	}
	cout << ans << endl;
}
signed main(){
	fast_io();
    int tt = 1;
    // cin >> tt;
    while(tt--)
    {
    	solve();
    }
    return 0;
}