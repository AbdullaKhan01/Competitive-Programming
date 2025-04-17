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
int n,k;
vector<int> a;
map<int,int> mp;
int sum;
int tot;
bool check(int mid)
{
	// decrease a by 1 or 2 or 3 or 4 or ....... mid
	// set all the numbers equal to the smallest number

	// k mid - k <= n-1
	// k >= mid - n + 1
	// mid - (mid - n - 1)
	int start = max(0LL,mid - n + 1);
	for(int st=start;st<=mid;st++)
	{
		//
		int num = a[0] - st;
		int rem = mid - st;
		int s = tot - mp[rem] + ((1+rem) * num);
		if(s <= k) return true; 
	}
	return false;
}
void solve()
{
	cin >> n >> k;
	a.resize(n);
	input(a);
	sort(all(a));
	sum = 0;
	mp.clear();
	for(int i=0;i<n;i++)
	{
		sum += a[i];
	}
	sum = 0;
	for(int i=n-1;i>0;i--)
	{
		sum += a[i];
		mp[n-i] = sum;
	}
	tot = sum;
	int s = 0 , e = 1e13;
	int ans = -1;
	while(s <= e)
	{
		int mid = (s + e)/2;
		if(check(mid))
		{
			ans = mid;
			e = mid - 1;
		}
		else{
			s = mid + 1;
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

//    1 1
//   1 2 1
//  1 3 3 1
// 1 4 6 4 1 

// nck = n-1Ck-1 + n-1Ck