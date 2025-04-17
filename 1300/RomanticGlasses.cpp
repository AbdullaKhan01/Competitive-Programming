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
	vector<int> a(n+1,0);
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	vector<vector<int>>pref(n+1,vector<int>(2,0));
	pref[1][1] = a[1];
	for(int i=2;i<=n;i++)
	{
		if(i % 2 == 0)
		{
			pref[i][0] = pref[i-2][0] + a[i];
			pref[i][1] = pref[i-1][1];
		}
		else
		{
			pref[i][1] = pref[i-2][1] + a[i];
			pref[i][0] = pref[i-1][0];
		}
	}
	int sumOdd = 0;
	int sumEven = 0;
	bool flag = false;
	map<int,int> mp;
	mp[0] = 1;
	for(int i=1;i<=n;i++)
	{
		if(i % 2 == 0)
		{
			sumEven += a[i];
			//her friends finds it
			// sumOdd - pref[l-1][1] == sumEven - pref[l-1][0]
			// sumOdd - sumEven = pref[l-1][1] - pref[l-1][0]
		}
		else
		{
			sumOdd += a[i];
			//lulia finds it
		}
		int finder = sumOdd - sumEven;
		if(mp.find(finder) != mp.end())
		{
			flag = true;
			break;
		}
		mp[pref[i][1] - pref[i][0]]++;
	}
	cout << (flag ? yes:no) << endl;
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