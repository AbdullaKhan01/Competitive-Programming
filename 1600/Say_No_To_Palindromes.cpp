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

Approach -> took hint from Editorial
*/
int n,m;
string s;
vector<string> perm(6);
void precompute()
{
	string k = "abc";
	int i = 0;
	do
	{
		while(perm[i].size() < 2e5)
		{
			perm[i] += k;
		}
		i++;
	}
	while(next_permutation(all(k)));

}
void solve()
{
	cin >> n >> m;
	cin >> s;
	vector<vector<int>> pref(6,vector<int>(n+1,0));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<6;j++)
		{
			pref[j][i+1] = pref[j][i] + (s[i] != perm[j][i]);
		}
	}
	while(m--)
	{
		int l,r;
		cin >> l >> r;
		int ans = 1e9;
		for(int i=0;i<6;i++)
		{
			ans = min(ans,pref[i][r] - pref[i][l-1]);
		}
		cout << ans << endl;
	}
}
signed main(){
	precompute();
	fast_io();
    int tt = 1;
    // cin >> tt;
    while(tt--)
    {
    	solve();
    }
    return 0;
}