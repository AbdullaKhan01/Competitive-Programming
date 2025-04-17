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
void solve(vector<int> a,vector<int> cost)
{
	int n = a.size();
	map<int,vector<int>> mp;
	for(int i=0;i<n;i++)
	{
		int it = a[i];
		mp[it].push_back(cost[i]);
	}
	vector<pair<int,int>> g;
	for(auto it:mp)
	{
		vector<int> temp = it.second;
		if(temp.size() > 1) 
		{
			sort(temp.begin(),temp.end());
			for(int i=0;i<temp.size()-1;i++)
			{
				g.push_back({temp[i],it.first});
			}
		}
	}
	sort(g.begin(),g.end());
	for(int i=0;i<1e6;i++)
	{
		if(mp.find(i) == )
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