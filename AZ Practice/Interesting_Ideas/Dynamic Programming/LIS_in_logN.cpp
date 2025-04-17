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
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
	}
	vector<int> lis;
	vector<int> insertedAt(n);
	for(int i=0;i<n;i++)
	{
		if(lis.empty() || lis.back() < arr[i])
		{
			lis.push_back(arr[i]);
			insertedAt[i] = lis.size();
		}
		else
		{
			auto it = lower_bound(lis.begin(),lis.end(),arr[i]);
			*it = arr[i];
			insertedAt[i] = it - lis.begin() + 1;
		}
	}
	int curlen = lis.size();
	vector<int> final_lis;
	for(int i=n-1;i>=0;i--)
	{
		if(insertedAt[i] == curlen)
		{
			final_lis.push_back(arr[i]);
			curlen--;
		}
	}
	reverse(all(final_lis));
	cout << lis.size() << endl;
	output(final_lis);
	cout << endl;
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