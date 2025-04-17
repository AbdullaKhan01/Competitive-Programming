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
void print(int n){
	for(int i=0;i<n;i++) cout << 0;
}
void solve(){
	int n;cin >> n;
	if(n == 1){
		cout << 1 << endl;
		return;
	}
	// 169 196 961
	// 16900 19600 96100 10609 90601
	// 1690000 1960000 9610000 1060900 9060100 1006009 9006001
	vector<int> a = {169,196,961};
	for(int i=0;i<3;i++){
		cout << a[i];
		print(n-3);
		cout << endl;
	}
	int x = n;
	n-=3;
	for(int i=0;i<(n/2);i++){
		cout << 1;
		print(i+1);
		cout<<6;
		print(i+1);
		cout<<9;
		print(x - 2*i - 2 - 3);
		cout << endl;

		cout << 9;
		print(i+1);
		cout<<6;
		print(i+1);
		cout<<1;
		print(x - 2*i - 2 - 3);
		cout << endl;
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