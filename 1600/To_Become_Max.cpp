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
Approach -> We can Use Binary Search

Lets say to check for a Particular Number L

we will iterate through all indices of the array 
and check if this index could take the max value which is L

so the next index would be L-1 then next would be L-2

so cost = max(0LL,L-a[i]) + max(0LL,L-1-a[i+1]) + max(0LL,L-2-a[i+2])
......

if this cost is <= k then we can do it  

*/
int n,k;
vector<int> a;
bool check(int mid)
{
	for(int i=0;i<n;i++)
	{
		int cnt = 0;
		bool flag = true;
		int prev = mid+1;
		for(int j=i;j<n;j++)
		{
			int curr = prev - 1;
			if(a[j] >= curr) break;
			if(j == n-1) flag = false;
			else cnt += (curr - a[j]);
			prev = curr;
		}
		if(cnt <= k && flag) return true;
	}
	return false;
}
void solve()
{
	cin >> n >> k;
	a.resize(n);
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
	}
	int maxi = *max_element(all(a));
	int s = maxi+1 , e = 1e9;
	int ans = maxi;
	while(s <= e)
	{
		int mid = (s + e)/2;
		if(check(mid))
		{
			ans = mid;
			s = mid + 1;
		}
		else
		{
		 	e = mid - 1;
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