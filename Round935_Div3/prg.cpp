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

int solve(int salary,int index,vector<int> &cost,vector<int> &happy
	,int add,map<pair<int,int>,int> &mp)
{
	if(index >= cost.size()) return 0;
	int take = 0 , notTake = 0;
	// if(cost[index] == 0) more = happy[index];
	if(mp.find({salary,index}) != mp.end()) return mp[{salary,index}];
	if(salary >= cost[index])
	{
		take = happy[index] + solve(salary-cost[index]+add,index+1,cost,happy,add,mp);
	}
	notTake = solve(salary+add,index+1,cost,happy,add,mp);
	int ans = max(take,notTake);
	mp[{salary,index}] = ans;
	return ans;
}
signed main(){
	fast_io();
    ll tt;
    cin >> tt;
    while(tt--)
    {
        int m,x;
        cin >> m >> x;
        vector<int> cost(m);
        vector<int> happy(m);
        int extra = 0;
        for(int i=0;i<m;i++)
        {
        	cin >> cost[i] >> happy[i];
        	if(i == 0 && cost[i] == 0) extra += happy[i];
        }
        map<pair<int,int>,int> mp;
        cout << solve(x,1,cost,happy,x,mp) + extra << endl;
    }
    return 0;
}