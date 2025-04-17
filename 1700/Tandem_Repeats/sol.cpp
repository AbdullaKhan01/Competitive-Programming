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
	 // _ _ _ _ _ _ _ _  
	string s;cin >> s;
	int n = s.size();
	int ans = 0;
	for(int d=1;d<=s.size()/2;d++){
		int cnt = 0;
		for(int i=0;i<n;i++){
			if(i + d < n){
			cnt +=(s[i] == s[i+d] || s[i] == '?' || s[i+d] == '?');
			}
			if(i - d >= 0){
				cnt -= (s[i - d] == s[i] || s[i] == '?' || s[i - d] == '?');
			}
			if(i - d + 1 >= 0 && cnt == d){
				ans = 2 * d;
			}
			
		}
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