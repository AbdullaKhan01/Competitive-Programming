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
struct maybe_doable
{
	map<int,int> ans;
	multiset<int> ms;
	void add(int x)
	{
		ms.insert(x);
	}
	int find(int x)
	{
		int start = 1;
		if(ans.find(x) != ans.end()) start = ans[x];
		while(ms.find(start*x) != ms.end())
		{
			start++;
		}
		ans[x] = start;
		return x*start;
	}

};
signed main(){
	fast_io();
    int q;
    cin >> q;
    maybe_doable md;
    while(q--)
    {
    	char ch;int a;
    	cin >> ch >> a;
    	if(ch == '+')
    	{
    		md.add(a);
    	}
    	else
    	{
    		cout << md.find(a) << '\n';
    	}
    }
    return 0;
}