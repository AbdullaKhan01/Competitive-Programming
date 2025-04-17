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

int inverse(int a,int p=mod-2){
	int result = 1;
	while(p>0){
		if(p&1)
			result = a*result %mod;
		a = a * a %mod;
		p >>= 1;
	}
	return result;
}
ll modAdd(ll a,ll b){
    ll p = (a%mod + b%mod)%mod;
    return p;
}
ll modSub(ll a,ll b){
    ll p = (a%mod - b%mod)%mod;
    if(p<0) p+=mod;
    return p;
}
ll modMul(ll a,ll b){
    ll p = (a%mod * b%mod)%mod;
    return p;
}
int modDiv(int a,int b)
{
	return modMul(a,inverse(b));
}
int runs[] = {1,2,3,4,6,0};
int dp[151][61][10][101][3];
int bp[151][61][10][101][3];

int rec(int needed,int bleft,int wickets,int curr_score,int onStrike)
{
	// pruning
	// base case

	if(bleft % 6 == 0)
	{
		if(onStrike == 0) onStrike = 1;
		if(onStrike == 1) onStrike = 0;
		if(onStrike == 2) onStrike = 2;
	}
	// cout << needed << " " << bleft << " " << wickets << " " << curr_score << " " << onStrike << endl;

	if(onStrike == 2 && curr_score < 100) return 0;
	if(needed <= 0)
	{
		if(curr_score >= 100) return 1;
		else return 0;
	}
	// needed more than 0 runs
	if(bleft <= 0) return 0;
	if(wickets == 10) return 0;

	// cache check
	if(dp[needed][bleft][wickets][curr_score][onStrike] != -1)
	{
		return dp[needed][bleft][wickets][curr_score][onStrike];
	}
	int ans = 0;
	// compute
		// either score 1,...,6 runs or get out
		for(int i=0;i<5;i++)
		{
			int val = 0;
			if(i == 5)
			{
				int nstrike = (onStrike == 1 || onStrike == 2) ? 2 : 0;
				val = rec(needed,bleft-1,wickets+1,curr_score,nstrike);
			}
			else if(i == 0 || i == 2)
			{
				if(onStrike == 1)
				{
					val = rec(needed - runs[i],bleft-1,wickets,curr_score+runs[i],0);
				}
				else
				{
					int nstrike = (onStrike == 0 ? 1 : 2);
					val = rec(needed - runs[i],bleft-1,wickets,curr_score,nstrike);
				}		
			}
			else
			{
				if(onStrike == 1)
				{
					val = rec(needed - runs[i],bleft-1,wickets,curr_score+runs[i],1);
				}
				else
				{
					val = rec(needed - runs[i],bleft-1,wickets,curr_score,onStrike);
				}			
			}
			
			ans += val;
			// ans is the number of outcomes which is winning
		}
		// if Virat on strike or he scored more than 100 runs then he can get out
			
	// save and return
	return dp[needed][bleft][wickets][curr_score][onStrike] = ans;
}

// int rec4(int ballRem,int runRem,int vkRuns,int wickRem,int strike)
// {
// 	if(runRem <= 0)
// 	{
// 		return (vkRuns >= 100);
// 	}
// 	if(ballRem == 0) return 0;
// 	if(wickRem == 0) return 0;

// 	if(sp[ballRem][runRem][vkRuns][wickRem][strike] != -1)
// 	{
// 		return sp[ballRem][runRem][vkRuns][wickRem][strike];
// 	}
// }

int rec2(int needed,int bleft,int wickets,int curr_score,int onStrike)
{
	// pruning
	// base case
	if(bleft % 6 == 0)
	{
		if(onStrike == 0) onStrike = 1;
		if(onStrike == 1) onStrike = 0;
		if(onStrike == 2) onStrike = 2;
	}

	if(needed <= 0)
	{
		if(curr_score >= 100) return 0;
		else return 1;
	}
	// needed more than 0 runs
	if(bleft <= 0) return 1;
	if(wickets == 10) return 1;

	// cache check
	if(bp[needed][bleft][wickets][curr_score][onStrike] != -1)
	{
		return bp[needed][bleft][wickets][curr_score][onStrike];
	}
	int ans = 0;
	// compute
		// either score 1,...,6 runs or get out
		for(int i=0;i<6;i++)
		{
			int val = 0;
			if(i == 5)
			{
				int nstrike = (onStrike == 1 || onStrike == 2) ? 2 : 0;
				val = rec2(needed,bleft-1,wickets+1,curr_score,nstrike);
			}
			else if(i == 0 || i == 2)
			{
				if(onStrike == 1)
				{
					val = rec2(needed - runs[i],bleft-1,wickets,curr_score+runs[i],0);
				}
				else
				{
					int nstrike = (onStrike == 0 ? 1 : 2);
					val = rec2(needed - runs[i],bleft-1,wickets,curr_score,nstrike);
				}		
			}
			else
			{
				if(onStrike == 1)
				{
					val = rec2(needed - runs[i],bleft-1,wickets,curr_score+runs[i],1);
				}
				else
				{
					val = rec2(needed - runs[i],bleft-1,wickets,curr_score,onStrike);
				}			
			}
			
			ans = modAdd(ans,val);
			// ans is the number of outcomes which is winning
		}
		// if Virat on strike or he scored more than 100 runs then he can get out
			
	// save and return
	return bp[needed][bleft][wickets][curr_score][onStrike] = ans;
}
int gp[61][160][11];
int rec3(int ballRem,int runRem,int wickRem)
{
	if(ballRem == 0 || runRem <= 0 || wickRem == 0) return 1;
	if(gp[ballRem][runRem][wickRem] != -1)
	{
		return gp[ballRem][runRem][wickRem];
	}
	int ans = 0;
	for(int i=0;i<5;i++)
	{
		ans = modAdd(ans,rec3(ballRem-1,runRem-runs[i],wickRem));
	}
	ans = modAdd(ans,rec3(ballRem-1,runRem,wickRem-1));
	return gp[ballRem][runRem][wickRem] = ans;
}
void solve()
{
	int n,b,w,x;
	cin >> n >> b >> w >> x;
	// cout << n << b << w << x << endl;
	int total = rec3(b,n,10-w);
	// cout << total << endl;
	int fav = rec(n,b,w,x,1);
	fav = 2;
	int n_fav = rec2(n,b,w,x,1);
	int tot = fav + n_fav;

	// cout << fav << endl;
	cout << tot << " " << total << endl;
	// cout << modDiv(fav,tot) << endl;
}

void test()
{
	int cnt = 0;
	for(int i=1;i<=6;i++)
	{
		for(int j=1;j<=12203000;j++)
		{
			if(modDiv(i,j) == 411737895)
			{
				cout << i << " " << j << endl;
			}
			else cnt++;
		}
	}
	cout << cnt << endl;
}
signed main(){
	fast_io();
    int tt = 1;
    cin >> tt;
    memset(dp,-1,sizeof(dp));
    memset(bp,-1,sizeof(bp));
    memset(gp,-1,sizeof(gp));
    while(tt--)
    {
    	test();
    	// solve();
    }
    return 0;
}
