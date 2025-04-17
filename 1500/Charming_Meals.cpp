#include<bits/stdc++.h>
#define mod 1000000007
#define mod2 998244353
#define ceil(a,b) ((a+b-1)/b)
#define floor(a,b)((a-b+1)/b)
#define fast_io() ios::sync_with_stdio(0);cin.tie(0);
#define ll long long
// #define int long long
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
bool solve(vector<int>&a,vector<int>&b,int mini)
{
	int n = a.size();
	vector<vector<int>> v(n+1,vector<int>(0));
	vector<int> used(n+1,0);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(abs(a[i]-b[j]) >= mini)
			{
				v[i].push_back(j);
			}
		}
	}
	vector<int> s;
	for(int i=0;i<n;i++) s.push_back(i);
	sort(all(s),[&](int &a,int &b){
		return v[a].size() <= v[b].size();
	});
	// output(s);
	// cout << endl;
	bool flag = true;
	for(auto it:s)
	{
		if(v[it].size() == 0)
		{
			return false;
		}
		int cnt = 0;
		for(int i=0;i<(int)v[it].size();i++)
		{
			int jt = v[it][i];
			if(!used[jt])
			{
				used[jt] = 1;
				cnt=1;
				break;
			}
		}
		if(cnt == 0)
		{
			return false;
		}
	}
	return flag;
}

signed main(){
	fast_io();
    ll tt;
    cin >> tt;
    while(tt--)
    {
        int n;
	    cin >> n;
	    vi dish(n);
	    input(dish);
	    vi meal(n);
	    input(meal);
	    int s = 0 , e = 1e9;
	    int ans = 0;

	    while(s <= e)
	   	{
	   		int mid = (s+e)/2;
	   		if(solve(dish,meal,mid))
	   		// if(false)
	   		{
	   			ans = mid;
	   			s = mid+1;
	   		}
	   		else
	   		{
	   			e = mid-1;
	   		}
	   	}
	   	cout << ans << endl;
    }
    return 0;
}