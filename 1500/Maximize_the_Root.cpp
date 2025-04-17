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

// VERDICT -> ACCEPTED
long long n;
long long a[200100];
vector<vector<long long>> children;
bool check(long long node,long long subs,long long mid)
{
	// if leaf node just return it's value
	assert(subs <= LLONG_MAX);
	if(children[node].size() == 0) return a[node]>=mid+subs;
	for(auto child:children[node])
	{
		long long more = 0LL;
		if(a[child]-subs < mid) more = mid - a[child] + subs;
		
		if(subs <= LLONG_MAX - more)
		{
			if(check(child,subs+more,mid) == false) return false;	
		}
		else return false;
	}
	return true;
	// return ans;
}
void solve()
{
	cin >> n;
	children.resize(n+1);
	int maxi = INT_MIN;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=2;i<=n;i++)
	{
		int x;
		cin >> x;
		children[x].push_back(i);
	}
	for(int i=1;i<=n;i++)
	{
		if(children[i].size() == 0) maxi = max(maxi,a[i]);
	}
	int s = 0 , e = 1e9;
	int ans = 0;
	while(s <= e)
	{
		int mid = (s+e)/2;
		if(check(1LL,0LL,mid))
		{
			ans = mid;
			s = mid + 1;
		}
		else
		{
			e = mid - 1;
		}
	}
	cout << a[1] + ans << "\n";
	children.clear();
}
signed main(){
	fast_io();
    ll tt;
    cin >> tt;
    while(tt--)
    {
        solve();
    }
    return 0;
}