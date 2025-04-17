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
	int n,k;
	cin >> n >> k;
	vi arr(n);
	input(arr);
	int ans = 0;
	bool turn = false;
	sort(rall(arr));
	for(int i=0;i<n;i++)
	{
		if(turn)
		{
			// bob
			int diff = arr[i-1] - arr[i];
			if(diff <= k)
			{
				k-=diff;
				ans -= arr[i-1];
			}
			else
			{
				ans -= (arr[i] + k);
				k = 0;
			}
		}
		else
		{
			// alice
			ans += arr[i];
		}
		turn = !turn;
	}
	cout << ans << endl;
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