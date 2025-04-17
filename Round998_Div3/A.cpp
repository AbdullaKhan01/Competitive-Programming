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
	int a1,a2,a4,a5;
	cin >> a1 >> a2 >> a4 >> a5;
	vector<int> a = {a1,a2,a1+a2,a4,a5};
	vector<int> b = {a1,a2,a4-a2,a4,a5};
	vector<int> c = {a1,a2,a5-a4,a4,a5};
	vector<int> d = {a1,a2,0,a4,a5};

	int maxi = 0;
	int cnt = 0;
	for(int i=2;i<5;i++){
		if(a[i] == a[i-1] + a[i-2]) cnt++;
	}
	maxi = max(maxi,cnt);
	cnt = 0;
	for(int i=2;i<5;i++){
		if(b[i] == b[i-1] + b[i-2]) cnt++;
	}
	maxi = max(maxi,cnt);
	cnt = 0;
	for(int i=2;i<5;i++){
		if(c[i] == b[i-1] + b[i-2]) cnt++;
	}
	maxi = max(maxi,cnt);
	cout << maxi  << endl;
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