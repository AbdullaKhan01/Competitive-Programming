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

//VERDICT -> ACCEPTED

/*

Approach is to just find the order in which the characters
will be taken out so that the resulting string is in 
lexicographically smallest manner and then just easily
search for the character in the kth position
*/
void solve()
{
	string s;
	cin >> s;
	int pos;
	cin >> pos;

	int n = s.size();

	vector<int> rem;

	// stack<int> st;
	vector<int> st;
	for(int i=0;i<n;i++)
	{
		while(!st.empty() && s[st.back()] > s[i])
		{
			rem.push_back(st.back());
			st.pop_back();
		}
		st.push_back(i);
	}
	while(!st.empty())
	{
		rem.push_back(st.back());
		st.pop_back();
	}

	vector<int> pref = {1};
	for(int k=n;k>=1;k--) pref.push_back(pref.back() + k); 
	
	auto it = upper_bound(all(pref),pos);
	it--;
	int x = it - pref.begin();
	int val = *(it);

	// we have string no x which has x removed elements

	int cnt = 0;
	int to_find = pos - val;

	for(int i=0;i<x;i++)
	{
		s[rem[i]] = '!';
	}
	for(int i=0;i<n;i++)
	{
		if(s[i] == '!') continue;
		if(to_find == cnt)
		{
			cout << s[i];
			return;	
		}
		else cnt++;
	}
}
signed main(){
	fast_io();
    ll tt;
    cin >> tt;
    while(tt--)
    {
        solve();
        // solve2();
    }
    return 0;
}