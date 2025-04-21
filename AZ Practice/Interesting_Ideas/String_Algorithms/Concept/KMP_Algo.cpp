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
/*
Given A String we have to find the KMP array

KMP[i] = longest **(proper) prefix of the string which
		is also a **(proper) suffix of the string

**proper -> do not take the entire string as prefix or 
suffix

*/
void solve()
{
	string s;cin >> s;
	int n = s.size();
	vector<int> kmp(n+1);
	int i=0,j=-1;kmp[0] = -1;	
	while(i < n){
		while(j != -1 && s[i] != s[j]) j = kmp[j];
		j++;i++;
		kmp[i] = j;
	}
	// done that's all 
	for(int i=0;i<=n;i++){
		cout << kmp[i] << " ";
	}
	cout << endl;
}

signed main(){
	fast_io();
	int tt = 1;
	// cin >> tt;
	while(tt--)
	{
	    solve();
	}
    return 0;
}