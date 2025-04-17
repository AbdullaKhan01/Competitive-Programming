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
void printms(multiset<pair<int,int>>&ms)
{
	cout << "[";
	for(auto it:ms)
	{
		cout << "{"<<it.first << "," << it.second << "},";
	}
	cout << "] " << endl;
}
struct maintain
{
	int count = 0;
	multiset<pair<int,int>>ms;
	multiset<pair<int,int>> cand;
	void add(int l,int r)
	{
		if(ms.empty())
		{
			ms.insert(make_pair(l,r));
			count++;
			cand.insert({l,r});
			// printms(ms);
			return ;
			// sfsdsd
		}
		auto it = ms.lower_bound({l,0});
		printms(ms);
		if(it != ms.end() && it->first <= r)
		{
			ms.insert(make_pair(l,r));
			return ;
		}
		// it--;
		if(it != ms.begin())
		{
			it--;
			ms.insert(make_pair(l,r));
			if(it->second >= l)
			{
				return ;
			}
		}
		count++;
		// cout << "hurrah" << endl;
		cand.insert({l,r});
		
		// -----------------l1----l ----r1-- r----------
	}
	void remove(int l,int r)
	{

		auto it = ms.lower_bound({l,0});
		printms(ms);
		if(it!= ms.end() && it->first <= r)
		{
			ms.erase(ms.find(make_pair(l,r)));
			return ;
		}
		// sdnbf
		if(it != ms.begin())
		{
			it--;
			if(it->second >= l)
			{
				ms.erase(ms.find(make_pair(l,r)));
				return ;
			}
		}
		count--;
		cand.erase(cand.find({l,r}));
	}
	void candy()
	{
		printms(cand);
	}
	bool ans()
	{
		return cand.size() >= 2;
	}
};
void test()
{

}
void solve()
{
	int q;
	cin >> q;
	multiset<int> left,right;
	while(q--)
	{
		char ch;
		int l,r;
		cin >> ch >> l >> r;
		if(ch == '+')
		{
			left.insert(l);
			right.insert(r);
		}
		else
		{
			left.erase(left.find(l));
			right.erase(right.find(r));
		}
		bool ans = false;
		if(right.empty() || left.empty()) ans = false;
		else ans = *right.begin() < *left.rbegin();
		cout << (ans?yes:no) << endl;
	}
}
signed main(){
	fast_io();
    // test();
    solve();
    return 0;
}