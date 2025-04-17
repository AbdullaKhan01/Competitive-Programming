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
Observation : any number cannot be increased it can only
be decreased 
if some number is 1
then all numbers have to be 1

otherwise lets say there are 2 numbers x , y > 1
and x < y for eg 10 11
// then ceil(10/11) == 2

*/
bool check(vector<pair<int,int>>&a)
{
	bool flag = true;
	for(int i=1;i<a.size();i++)
	{
		if(a[i].first != a[i-1].first) flag = false;
	}
	return flag;
}
void solve()
{
	int n;
	cin >> n;
	vector<pair<int,int>> a(n);
	for(int i=0;i<n;i++)
	{
		cin >> a[i].first;
		a[i].second = i;
	}	
	sort(all(a));

	if(a.size() >= 2 && a[0].first==1 && a.back().first > 1)
	{
		cout << -1 << endl;
	}
	else if(a.size() == 1 || check(a))
	{
		// cout << "here" << endl;
		cout << 0 << endl;
	}
	else
	{
		vector<pair<int,int>> ans;
		int cnt = 0;
		while(true)
		{
			cnt++;
			a.back().first = ceil(a.back().first,a[0].first);
			ans.push_back({a.back().second+1,a[0].second+1});
			if(a.back().first == 2) break;
		}
		int idx = a.back().second+1;
		// int cnt = 1;
		for(int i=0;i<n;i++)
		{
			int to_push = a[i].second+1;
			while(a[i].first > 2)
			{
				a[i].first = ceil(a[i].first,2);
				ans.push_back({to_push,idx});
				cnt++;
			}
		}
		if(cnt <= 30*n)
		{
			cout << ans.size() << "\n";
			for(auto it:ans)
			{
				cout << it.first << " " << it.second << endl;
			}
		}
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