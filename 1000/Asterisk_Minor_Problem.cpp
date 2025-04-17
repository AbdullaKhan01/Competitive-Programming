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
	string a,b;
	cin >> a >> b;
	if(a[0] == b[0])
	{
		cout << yes << endl;
		cout << a[0]<<"*" << endl;
		return ;
	}
	if(a.back() == b.back())
	{
		cout << yes << endl;
		cout << "*"<<a.back() << endl;
		return ;
	}
	// else if 2 length string matches
	for(int i=0;i<a.size()-1;i++)
	{
		string temp = a.substr(i,2);
		if(b.find(temp) != -1)
		{
			cout << yes << endl;
			cout << "*"<<temp<<"*" << endl;
			return ;
		}
	}
	// else false
	cout << no << endl;


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