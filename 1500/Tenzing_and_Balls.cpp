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
signed main(){
	fast_io();
    // intuition -> this is a dp problem 
    // how many dimensional -> 1D because only dp[i] depends on 
    // only index
    // then what will dp[i] represent ? 
    // ans -> the max no of balls that can be deleted from i .... n

    // we can store this answer in an map so that we can map 
    // this can to an integer

	// VERDICT -> ACCEPTED

    ll tt;
    cin >> tt;
    while(tt--)
    {
		int n;
		cin >> n;
		vi arr(n);
		input(arr);
		map<int,pair<int,int>> mp;
		int maxi = 0;
		for(int i=n-1;i>=0;i--)
		{

			if(mp.find(arr[i]) != mp.end())
			{
				pair<int,int> val = mp[arr[i]];

				
				int coins = (val.first - i + 1) + val.second;
				if(maxi >= coins)
				{
					mp[arr[i]] = {i,maxi};
				}
				else
				{
					mp[arr[i]] = {val.first,val.second};
				}	

				maxi = max(maxi,coins);
			}
			else
			{
				pair<int,int> pp = make_pair(i,maxi);
				mp[arr[i]]=pp;
			}
		}
		cout << maxi << endl;        
    }
    return 0;
}
