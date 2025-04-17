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
const int N = 1e6 + 6;
int dp[N];
void preprocess()
{
	dp[1] = 1;
	int st = 2 , en = 3;
	int add = 2;
	int alpha = 2;
	int num = 2;
	while(num < N)
	{
		int sq = num * num;
		if(num == st)
		{
			dp[num] = sq + dp[num - add + 1];
			st += add;
		}
		else if(num == en)
		{

			dp[num] = sq + dp[num - add];
			add++;
			alpha += 2;
			en += add;
		}
		else
		{
			dp[num] = sq + dp[num - add] + dp[num - add + 1] - dp[num - alpha];
		}
		num++;
	}
	
}
void solve()
{
	int n;
	cin >> n;
	cout << dp[n] << endl;

}
signed main(){
	fast_io();
    preprocess();
    int tt = 1;
    cin >> tt;

    while(tt--)
    {
    	solve();
    }
    return 0;
}