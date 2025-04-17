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
	string s;cin >> s;
	int n = (int)s.size();
	vector<pair<int,int>> cand;

	int idx = -1;
	for(int i=0;i<n;i++){
		if(s[i] == '1') continue;
		if(s[i] == '0') idx = i;
		break;
	}
	if(idx == -1){
		cout << 1 << " " << n << " " << n << " " << n << endl; 
	}
	else{
		// int cnt = 0;
		int pdx = idx;
		int r = n - idx;
		while(pdx < n && s[pdx] == '0'){
			pdx++;
			if(idx - 1 >= 0) idx--;
			else break;
		}
		int l = idx+1;
		cout << 1 << " " << n << " " << l << " " << l + r - 1 << endl;
	}

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