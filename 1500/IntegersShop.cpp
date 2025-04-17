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

// so the problem is given some l and r
// we have to find out the sum of cost of all l and r's

// now what do we have to do

// suppose we have to insert a range[l,r] to the set of ranges
// if [l,r] already belong to a bigger range[l1,r1]
// then do nothing

// otherwise delete all ranges [lo,ro] lying inside [l,r]
// along with their costs and then insert [l,r] in the 
// set with its cost added to the total cost


// finally to give an ans just return the cost maintained

struct game
{
	// what data structures do we use ?? 
	// set for all the ranges and map for cost of ranges
	int totalCost = 0;
	set<pair<int,int>> s;
	set<pair<int,int>> rs;
	map<pair<int,int>,int>mp;
	void add(int l,int r,int new_cost)
	{
		if(s.empty())
		{
			s.insert({l,r});
			rs.insert({r,l});
			totalCost += new_cost;
			mp[{l,r}] = new_cost;
		}
		if(s.find({l,r}) != s.end())
		{
			int prev_cost = mp[{l,r}];
			totalCost -= prev_cost;
			mp[{l,r}] = min(new_cost,prev_cost);
			totalCost += mp[{l,r}];
			return ;
		}
		// first check if [l,r] belong to any big range
		// then do nothing
		// how do we do that ? 
		// if some big range containing [l,r] is present
		// then it would be the lower_bound of the r
		auto it = rs.lower_bound({r,0});
		if(it != rs.end() && it->second <= l)
		{
			return ;
		}
		// otherwise delete all ranges inside [l,r]
		while(true)
		{
			if(s.empty()) break;
			auto it = s.lower_bound({l,0});
			if(it != s.end() && it->second <= r)
			{
				totalCost -= mp[{it->first,it->second}];
				s.erase({it->first,it->second});
				rs.erase({it->second,it->first});
				mp.erase({it->first,it->second});
			}
			else break;
		}
		// now insert the new pair in the set 
		s.insert({l,r});
		rs.insert({r,l});
		mp[{l,r}] = new_cost;
		totalCost += new_cost;
	}
	int ans()
	{
		return totalCost;
	}
};
bool cmp(pair<int,int>a,pair<int,int>b)
{
	if(a.first < b.first) return true;
	if(a.first == b.first) return (a.second > b.second);
	return false; 
}

struct tryhard
{
	pair<pair<int,int>,int>p1={{1e9,1e9},0};
	pair<pair<int,int>,int>p2={{0,0},0};

	void display()
	{
		cout << p1.first.first << " " << p1.first.second << endl;
		cout << p2.first.first << " " << p2.first.second << endl;
	}
	void add(int l,int r,int c)
	{
		pair<pair<int,int>,int>a={{l,r},c};
		// {l,r} can do 4 things only
		// 1. replace both first and second
		if(r == p2.first.second && l == p1.first.first)
		{
			if(p1.second + p2.second > c)
			{
				p1 = a;
				p2 = a;
			}
		}
		// 2. replace only first		
		if(r > p2.first.second) p2 = a;
		if(l < p1.first.first ) p1 = a;
		
		if(l == p1.first.first)
		{
			if(c < p1.second) p1 = a;
		}
		// 3. replace only second
		if(r == p2.first.second)
		{
			if(c < p2.second) p2 = a;
		}
		// 4. do nothing


	}
	int ans()
	{
		if(p1.first.second == p2.first.second)
		{
			return p1.second;
		}
		if(p2.first.first == p1.first.first)
		{
			return p2.second;
		}
		return p1.second + p2.second;
	}
};

struct work
{
	set<pair<int,int>> s;
	map<pair<int,int>,int>mp;
	int cost = 0;
	void add(int l,int r,int c)
	{
		if(s.empty())
		{
			s.insert({l,r});
			mp[{l,r}] = c;
			cost += c;
			return ;
		}
		// check for duplicates
		if(l == s.begin()->first && r==s.begin()->second)
		{
			int cc = mp[{l,r}];
			cost -= cc;
			mp[{l,r}] = min(cc,c);
			cost += mp[{l,r}];
			return ;
		}
		auto it = ++(s.begin());
		if(it!=s.end() && l == it->first && r==it->second)
		{
			int cc = mp[{l,r}];
			cost -= cc;
			mp[{l,r}] = min(cc,c);
			cost += mp[{l,r}];
			return ;
		}
		// check for first replacement
		if(l < s.begin()->first)
		{
			int left = s.begin() -> first;
			int right = s.begin() -> second;
			s.erase({left,right});
			s.insert({l,r});
			mp[{l,r}] = c;
			cost -= mp[{left,right}];
			cost += c;
		}

		// check for last replacement
		if(it != s.end() && r > it->second)
		{
			int left = it -> first;
			int right = it -> second;
			s.erase({left,right});
			s.insert({l,r});
			mp[{l,r}] = c;
			cost -= mp[{left,right}];
			cost += c;
		}

		// check if first == last
		if(s.size() == 2)
		{
			// auto it = prev(s.end());
			// if(s.begin()->second >= it->second)
			// {
			// 	int g = mp[{}]
			// }
		}
	}
};



struct another
{
	// we have to only maintain // first and last set
	// all the rest numbers we will get as a reward

	pair<int,int> f = {INT_MAX,INT_MAX};
	pair<int,int> l = {INT_MAX,INT_MAX};
	int c1=0,c2=0;
	// set<pair<pair<int,int>,int>>st;
	// int maxi = -1;
	// int func(pair<int,int> a,int cost)
	// {
	// 	st.insert({a,cost});
	// 	if(st.size() == 1) return (st.begin())->first.first;

	// }
	void add(pair<int,int> a,int cost)
	{
		bool flag = false;
		if(a.first == f.first && a.second == f.second)
		{
			c1 = min(c1,cost);
			flag = true;
		}
		if(a.first == l.first && a.second == l.second)
		{
			c2 = min(c2,cost);
			flag = true;
		}
		if(flag) return ;

		if(cmp(a,f) && cmp(a,l))
		{
			f = a;
			l = {INT_MAX,INT_MAX};
			c1 = cost;
			c2 = 0;
		}
		else if(cmp(a,f))
		{
			f = a;
			c1 = cost;
		}
		else if(a.second > f.second && cmp(a,l))
		{
			l = a;
			c2 = cost;
		}

		// now see the last range
		if(l.second < a.second)
		{
			l = a;
			c2 = cost;
		}
		if(l.second == a.second)
		{
			if(c2 > cost)
			{
				l = a;
				c2 = cost;
			}
		}
	}
	int ans()
	{
		return c1+c2;
	}
};
signed main(){
	fast_io();
   	ll tt;
   	cin >> tt;
   	while(tt--)
   	{
   	    int q;
   	    cin >> q;
   	    tryhard g;
   	    while(q--)
   	    {
   	    	int l,r,cost;
   	    	cin >> l >> r >> cost;
   	    	g.add(l,r,cost);
   	    	cout << g.ans() << '\n';
   	    }
   	}
    return 0;
}