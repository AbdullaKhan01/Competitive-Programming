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
void solve()
{
	string s;
	cin >> s;
	int n = s.size();
	vector<int> a;
	bool flag = true;
	for(int i=0;i<n;i++)
	{
		// -1 means neutral
		//  1 means increasing
		//  0 means non increasing
		if(s[i] == '+')
		{
			if(!a.empty() && a.back() == 0)
				a.push_back(0);
			else a.push_back(-1);
		}
		else if(s[i] == '-')
		{
			a.pop_back();
		}
		else if(s[i] == '1')
		{
			// check increasing 
			if(a.size() <= 1) continue;
			if(a.back() == 0) flag = false;
			else
			{
				// it is true
				// what to do
				// make all increasing from last to curr
				int j = a.size() - 1;
				while(j > 0 && a[j] == -1)
				{
					a[j--] = 1;
				}
			}
		}
		else
		{
			// check non increasing
			if(a.size() <= 1 || a.back() == 1) flag = false;
			else
			{
				// it is true
				// what to do
				// make the last element as causing trbl
				a.back() = 0;
			}
		}
	}
	cout << (flag ? yes:no) << endl;
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