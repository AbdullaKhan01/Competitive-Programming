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
	int n;
	cin >> n;
	string s;
	cin >> s;
	int cnt = 0;
	bool flag = true;
	int arr[26] = {0};
	int pairs[26] = {0};
	for(int i=0;i<n/2;i++)
	{
		if(s[i] == s[n-1-i]) cnt++,pairs[s[i] - 'a']++;
	}
	int maxi = 0;
	for(int i=0;i<n;i++)
	{
		arr[s[i] - 'a']++;
		if(arr[s[i] - 'a'] > (n/2)) flag = false;
		maxi = max(maxi,pairs[s[i] - 'a']);
	}
	if(n % 2 == 0 && flag)
	{

		int total = cnt - maxi;

		if(maxi > total)
		{
			cout << maxi << endl;
		}
		else cout << ceil(cnt,2) << endl;
	}
	else cout << -1 << endl;
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