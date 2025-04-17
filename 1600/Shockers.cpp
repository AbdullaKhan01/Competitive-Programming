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
void solve2()
{
	int n;
	cin >> n;
	vector<pair<char,string>>brr(n);
	for(int i=0;i<n;i++)
	{
		cin >> brr[i].first >> brr[i].second;
	}
	set<char> st;
	for(char ch = 'a';ch<='z';ch++) st.insert(ch);
	bool flag = false;
	int cnt = 0;
	for(int i=0;i<n-1;i++)
	{
		char sm = brr[i].first;
		string s = brr[i].second;
		flag |= (st.size() == 1);
		if(sm == '!')
		{
			if(flag) cnt++;
			else
			{
				set<char> st2;
				for(auto it:s)
				{
					if(st.find(it) != st.end()) st2.insert(it);
				}
				st = st2;	
			}	
		}
		else if(sm == '.')
		{
			for(auto it:s)
			{
				if(st.find(it) != st.end())
				{
					st.erase(it);
				}
			}	
		}
		else
		{
			// shock or ultra shock
			if(flag) cnt++;
			else
			{
				char ffi = s[0];
				st.erase(ffi);
			}
		}
	}
	cout << cnt << endl;
}
signed main(){
	fast_io();
    solve2();
    return 0;
}