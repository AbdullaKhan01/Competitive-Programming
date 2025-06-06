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
	int n,k,d;
	cin >> n >> k >> d;
	vector<int> a(n);
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
	}
	vector<int> v(k);
	for(int i=0;i<k;i++)
	{
		cin >> v[i];
	}
	int l = 0;
	while(v.size() < 2*n)
	{
		v.push_back(v[l]);
		l = (l+1)%k;
	}
	v.insert(v.begin(),0);
	int ans = 0;
	for(int i=0;i<min(d,(int)v.size());i++)
	{
		int range = v[i];
		int cnt = 0;
		for(int j=1;j<=n;j++)
		{
			if(j <= range) a[j-1]++;
			if(a[j-1] == j) cnt++;
		}
		// used i days // left d - i days
		// for the rest of d - i days increase 1 and take it
		ans = max(ans,cnt + (d-i-1)/2);
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