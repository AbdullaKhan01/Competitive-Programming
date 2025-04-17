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

// It's a DP problem Greedy does not work here
void solve()
{
	int n;
	cin >> n;
	vector<int> a(n);

	map<int,int> mp;
	int mex = 0;
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
		mp[a[i]]++;
	}
	for(auto it:mp)
	{
		if(it.first == mex) mex++;
	}
	// cout << mex << endl;
	sort(a.begin(),a.end());

	int ans = INT_MAX;

	for(int st=0;st<n;st++)
	{
		int cnt = 0;
		for(int i=st;i>=0;i--)
		{
			int element = a[i];
			mp[element]--;
			if(mp[element] == 0)
			{
				mex = min(mex,element);
			}
			cnt += mex;
		}
		for(int j=n-1;j>st;j--)
		{
			int element = a[j];
			mp[element]--;
			if(mp[element] == 0)
			{
				mex = min(mex,element);
			}
			cnt += mex;
		}
		ans = min(ans,cnt);
		mex = 0;
		for(int i=0;i<n;i++)
		{
			mp[a[i]]++;
			if(a[i] == mex) mex++;
		}
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