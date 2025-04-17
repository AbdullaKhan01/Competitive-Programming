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
Took Help from Editorial

// Basically if we replace 0 by some number x
// then all the suffix sum after that number will 
// increase by x

// this means we can just replace 0 with the number which
// appear max number of times in the suffix sum lets say k
// with -k

// [s(l+1),s(l+2),.........s(r)]


*/
void solve()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
	}
	vector<vector<int>>g;
	vector<int> temp;
	for(int i=0;i<n;i++)
	{
		if(a[i] == 0)
		{
			if(!temp.empty())
			{
				g.push_back(temp);
				temp.clear();
			}
			temp.push_back(0);
		}
		else temp.push_back(a[i]);
	}
	g.push_back(temp);
	int ans = 0;
	for(auto it:g)
	{
		map<int,int> mp;
		int psum = 0;
		int maxi = 0;
		for(auto i:it)
		{
			psum += i;
			mp[psum]++;
			maxi = max(maxi,mp[psum]);
		}
		if(it[0] == 0) ans += maxi;
		else ans += mp[0];
	}
	cout << ans << endl;
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