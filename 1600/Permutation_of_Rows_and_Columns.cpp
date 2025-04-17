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
int find(vector<int>&a,vector<vector<int>>&b)
{
	int n = b.size();
	int m = b[0].size();
	for(int i=0;i<n;i++)
	{
		bool flag = true;
		set<int> st;
		for(int j=0;j<m;j++)
		{
			st.insert(b[i][j]);
		}
		for(int j=0;j<m;j++)
		{
			if(st.find(a[j]) != st.end()) st.erase(a[j]);
			else flag = false;
		}
		if(flag) return i;
	}
	return -1;
}
void solve()
{
	int n,m;
	cin >> n >> m;
	vector<vector<int>>a(n,vector<int>(m,0));
	map<int,int> mp;
	rep(i,0,n)
	{
		rep(j,0,m)
		{
			cin >> a[i][j];
		}
	}
	
	vector<vector<int>>b(n,vector<int>(m,0));
	rep(i,0,n)
	{
		rep(j,0,m)
		{
			cin >> b[i][j];
		}
	}
	int r = find(a[0],b);
	if(r == -1)
	{
		cout << no << endl;
		return ;
	}
	for(int i=0;i<m;i++)
	{
		mp[b[r][i]] = i;
	}
	bool flag = true;
	for(int i=0;i<m;i++)
	{
		// col in a = mp[b[r][i]]
		int col = mp[a[0][i]];
		// cout << b[r][i] << " " << col << endl;
		set<int> st;


		for(int j=0;j<n;j++)
		{
			st.insert(a[j][i]);
		}
		for(int j=0;j<n;j++)
		{
			int ele = b[j][col];
			if(st.find(ele) != st.end()) st.erase(ele);
			else
			{
				cout << "flag false for " << ele << endl;
			 	flag = false;
			}
		}
	}
	cout << ((flag)?yes:no) << endl;
}
signed main(){
	fast_io();
    ll tt;
    cin >> tt;
    while(tt--)
    {
        solve();
    }
    return 0;
}