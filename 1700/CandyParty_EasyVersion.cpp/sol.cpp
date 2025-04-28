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
// Read Question Properly 
// Don't be afraid to derive mathematical formulas
// Had to take hint from Editorial

// Solution to 2^x - 2^y is unique if x,y >= 0 and y < x
map<int,pair<int,int>> mp;
void precompute(){
	for(int x=0;x<32;x++){
		for(int y=0;y<32;y++){
			mp[(1<<x) - (1<<y)] = make_pair(x,y);
		}
	}
}
void solve(){
	int n;cin >> n;
	vector<int> a(n);
	int sum = 0;
	for(int i=0;i<n;i++){
		cin >> a[i];
		sum += a[i];
	}
	if(sum % n != 0){
		cout << "No" << endl;
		return ;
	}
	int val = sum / n;
	// a[i] + 2^x - 2^y = val
	// 2^x - 2^y = val - a[i]
	map<int,int> ans;
	for(int i=0;i<n;i++){
		int d = val - a[i];
		if(d == 0) continue;
		if(mp.find(d) == mp.end()){
			cout << "No" << endl;
			return;
		}
		pair<int,int> x = mp[d];
		ans[x.first]--;
		ans[x.second]++;
	}
	for(auto it : ans){
		if(it.second != 0){
			cout << "No" << endl;
			return ;
		}
	}
	cout << "Yes" << endl;
}

signed main(){
	precompute();
	fast_io();
    int tt = 1;
    cin >> tt;
    while(tt--)
    {
    	solve();
    }
    return 0;
}