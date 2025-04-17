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

const int N = 1e5 + 5;
vector<int> gl;
void solve()
{
	int r;
	cin >> r;

	int l = r*r;
	int h = (r+1)*(r+1);
	int cnt = 0;
	for(int x=1;x<=r;x++)
	{
		int sq = x*x;
		if(sq >= l && sq < h) cnt+=2;

		int idx1 = lower_bound(all(gl),l - x*x) - gl.begin();
		int idx2 = lower_bound(all(gl),h - x*x) - gl.begin();
		cnt += 4*(idx2 - idx1);
	}
	for(int y=0;y<=r;y++)
	{
		int sq = y*y;
		if(sq >= l && sq < h) cnt+=2;
	}
	cout << cnt << endl;
}
void init()
{
	for(int i=1;i<N;i++)
	{
		gl.push_back(i*i);
	}
}
signed main(){
	fast_io();
	init();
    ll tt;
    cin >> tt;
    while(tt--)
    {
        solve();
    }
    return 0;
}