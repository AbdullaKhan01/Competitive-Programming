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
// #define endl '\n'
using namespace std; 
/* 
for fast input output use printf and scanf;
*/
void solve()
{
	auto ask = [&](string s)
	{
		cout << "? " << s << endl;
		bool p;cin >> p;
		return p;
	};
	int n;cin >> n;
	string t = "";
	while(t.size() < n)
	{
		string t1 = t + "0";
		string t2 = t + "1";
		if(ask(t1)) t = t1;
		else if(ask(t2)) t = t2;
		else break;
	}
	while(t.size() < n)
	{
		string t1 = "0" + t;
		if(ask(t1)) t = t1;
		else t = "1" + t;
	}
	cout << "! " << t << endl;
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