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
VERDICT -> ACCEPTED
*/
static bool cmp(pii a,pii b)
{
	return a.first <b.first;
}
signed main(){
	fast_io();
    ll tt;
    cin >> tt;
    while(tt--)
    {
        // assert(0>2);
        int n,m,k;
        cin >> n >> m >> k;
        vi brr(n+1,0);
        vector<pii>arr;
        rep(i,0,n)
        {
        	cin >> brr[i];
        	arr.pb({brr[i],i});
        }
        sort(all(arr),cmp);
        int want = k;
        vector<int> needed(n+1,0);
        for(int j=0;j<n;j++)
        {
        	int g = min(m,k);
        	// assert(arr[j].second<n);
        	needed[(int)arr[j].second] = g;
        	k-=g;
        }
        int ans = 0;
        int prev = 0;
        // output(needed);
        // cout << endl;
        for(int j=0;j<n;j++)
        {
        	ans += (brr[j]+prev) * needed[j];
        	prev += needed[j];
        }
        cout << ans << endl;
    }
    return 0;
}