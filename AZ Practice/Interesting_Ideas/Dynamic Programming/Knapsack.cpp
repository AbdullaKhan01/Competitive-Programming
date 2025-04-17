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

const int INF = 1e9;
int n;
int W;
int w[3000];
int v[3000];
int dp[101][1001][101];
int K,M;

/*
TIME COMPLEXITY FORMULA = #S * (1 + #T)

#S -> no of states (no of diff parameters in rec func)

#T -> average cost of transition or (number of transitions)
*/


//01 Knapsack -> item can be taken only 1 time

/*
int rec(int idx,int weight)
{
	//pruning 
	//base case
	if(idx == n) return 0;

	//cache check
	if(dp[idx][weight] != -1) return dp[idx][weight];

	// transition
	int ans = rec(idx+1,weight);
	if(w[idx] <= weight)
	{
		ans = max(ans,rec(idx+1,weight-w[idx]) + v[idx]);
	}
	//save and return
	return dp[idx][weight] = ans;
}
*/

// 0 - INF Knapsack -> item can be taken more than 1 time

/*
int recInf(int idx,int weight)
{
	//pruning 
	//base case
	if(idx == n) return 0;

	//cache check
	if(dp[idx][weight] != -1) return dp[idx][weight];

	// transition
	int ans = recInf(idx+1,weight);
	if(w[idx] <= weight)
	{
		ans = max(ans,recInf(idx,weight-w[idx]) + v[idx]);
	}
	//save and return
	return dp[idx][weight] = ans;
}
*/

// now we can take max K items only and sum of items 
// taken should be divisible by M


// if we take some i we cannot take i+1

// so in transition just go to i+2 after taking
int recBound(int idx,int weight,int item_left)
{
	//pruning 
	//base case
	if(idx == n) 
	{
		int sum_of_taken = W - weight;
		if(sum_of_taken % M == 0)
		{
			return 0;
		}
		else
		{
			return -INF;
		}
	}

	//cache check
	if(dp[idx][weight][item_left] != -1) return dp[idx][weight][item_left];

	// transition
	int ans = recBound(idx+1,weight,item_left);
	if(w[idx] <= weight && item_left > 0)
	{
		ans = max(ans,recBound(idx,weight-w[idx],item_left-1) + v[idx]);
	}
	//save and return
	return dp[idx][weight][item_left] = ans;
}



/*
vector<int> solution;
void generate(int i,int x)
{
	if(i == n) return ;
	int donttake = rec(i+1,x);
	if(w[i] <= x)
	{
		// can possibly take this item
		int take = rec(i+1,x-w[i]) + v[i];
		if(donttake > take)
		{
			generate(i+1,x);
		}
		else
		{
			solution.push_back(i);
			generate(i+1,x-w[i]);
		}
	}
	else
	{
		// can't take
		generate(i+1,x);
	}
}

*/
void solve()
{
	cin >> n;
	cin >> K >> M;
	for(int i=0;i<n;i++)
	{
		cin >> w[i];
	}
	for(int i=0;i<n;i++)
	{
		cin >> v[i];
	}
	cin >> W;
	memset(dp,-1,sizeof(dp));
	cout << recBound(0,W,K) << endl;
	// generate(0,W);
	// for(auto it:solution)
	// {
	// 	cout << it << " ";
	// }
	// cout << endl;
}
signed main(){
	fast_io();
    int tt = 1;
    // cin >> tt;
    while(tt--)
    {
    	solve();
    }
    return 0;
}