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
	string s;
	cin >> s;
	s = "0"+s;
	int n = s.size();
	set<int> st;
	for(int i=1;i<=n;i++)
	{
		if(i >= 3)
		{
			// cout << yes << endl;
			string temp = s.substr(i-3,4);
			if(temp == "1100") st.insert(i);
		}
	}
	int q;
	cin >> q;
	while(q--)
	{
		int i;char j;
		cin >> i >> j;
		s[i] = j;
		if(i >= 4)
		{
			string temp = s.substr(i-3,4);
			if(temp == "1100") st.insert(i);
			else st.erase(i);
		}
		if(i+1 <= n && i+1 >= 4)
		{
			string temp = s.substr(i+1-3,4);
			if(temp == "1100") st.insert(i+1);
			else st.erase(i+1);
		}
		if(i+2 <= n && i+2 >= 4)
		{
			string temp = s.substr(i+2-3,4);
			if(temp == "1100") st.insert(i+2);
			else st.erase(i+2);
		}
		if(i+3 <= n && i+3 >= 4)
		{
			string temp = s.substr(i+3-3,4);
			if(temp == "1100") st.insert(i+3);
			else st.erase(i+3);
		}
		if(st.size() > 0) 
		{
			cout << yes << endl;
		}
		else cout << no << endl;
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