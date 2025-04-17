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
const int inf = 1e9;
string s;
int n,m;
vector<string> q;
int dp[101];
pair<int,int> front[101];
int rec(int level)
{
	//pruning
	//base case
	if(level == n) return 0;
	//cache check
	if(dp[level] != -1) return dp[level];
	//compute
	int ans = inf;
	for(int i=0;i<m;i++)
	{
		int t = q[i].size();
		string temp = s.substr(level,t);
		if(temp == q[i])
		{
			// then we can do the transition
			for(int x=1;x<=t;x++)
			{
				int t_ans = 1 + rec(level + x);
				// ans = min(ans,1 + rec(level + x));	
				if(t_ans < ans)
				{
					ans = t_ans;
					front[level] = {i+1,level + x};
				}
			}
		}
	}
	//save and return
	return dp[level] = ans;
}
void generate(int level)
{
	if(level == n) return ;
	cout << front[level].first << " " << level + 1 << endl;
	generate(front[level].second);
}
void solve()
{
	cin >> s;
	n = s.size();
	cin >> m;
	q.assign(m,"");
	for(int i=0;i<m;++i)
	{
		cin >> q[i];
	}
	memset(dp,-1,sizeof(dp));
	int ans = rec(0);
	if(ans >= inf)
	{
		cout << -1 << endl;
	}
	else 
	{
		cout << ans << endl;
		generate(0);
	}
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