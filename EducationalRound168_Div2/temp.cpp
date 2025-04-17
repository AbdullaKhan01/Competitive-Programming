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
#define F first
#define S second
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


struct range_maintainance
{
    set<pair<int,int>> st;
    void fill_range(int l, int r)
    {
        auto it = st.upper_bound({l, 1e9});
        if (it != st.begin())
        {
            it--;
            if (it->second >= l)
            {
                l = it->first;
                r = max(r, it->second);
                st.erase(it);
            }
        }

        it = st.upper_bound({r, 1e9});
        if (it != st.begin())
        {
            it--;
            if (it->second >= r)
            {
                r = it->second;
                l = min(r, it->second);
                st.erase(it);
            }
        }

        while (1)
        {
            it = st.lower_bound({l, 0});
            if (it == st.end() || (it->second <= r))
            {
                break;
            }
            else
            {
                st.erase(it);
            }
        }

        st.insert({l, r});
    }

    void clear_range(int l, int r)
    {
        auto it = st.upper_bound({l, 1e9});
        if (it != st.begin())
        {
            it--;
            if (it->second >= r)
            {
                int lo1 = it->first;
                int hi1 = l;

                int lo2 = r;
                int hi2 = it->second;

                st.erase(it);
                st.insert({lo1, hi1});
                st.insert({lo2, hi2});
                return;

                if (it->second >= l)
                {
                    int lo = it->first;
                    int hi = l;
                    st.erase(it);
                    st.insert({lo, hi});
                }
            }
        }

        it = st.upper_bound({r, 1e9});
        if (it != st.begin())
        {
            it--;
            if (it->second >= r)
            {
                int lo = r;
                int hi = it->second;
                st.erase(it);
                st.insert({lo, hi});
            }
        }

        while (1)
        {
            it = st.lower_bound({l, 0});
            if (it == st.end() || (it->first > r))
            {
                break;
            }
            else
            {
                st.erase(it);
            }
        }
    }

    bool check_point(int x)
    {
        auto it = st.upper_bound({x, 1e9});
        if (it == st.begin())
        {
            return 0;
        }
        else
        {
            it--;
            if (it->second >= x)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
    }

    bool check_range_any(int x, int y)
    {
        auto it = st.upper_bound({x, 1e9});
        if (it != st.end())
        {
            if (it->first <= y)
            {
                return 1;
            }
        }
        return check_point(x);
    }

    bool check_range_all(int x, int y)
    {
        auto it = st.upper_bound({x, 1e9});
        if (it == st.begin())
        {
            return 0;
        }
        else
        {
            it--;
            if (it->second >= y)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
    }
};

// struct query
// {
// 	int sum = 0;
// 	set<pair<int,int>> s;
// 	map<pair<int,int>,int>mp;
// 	void insert(int l,int r,int cost)
// 	{
// 		if(s.find({l,r}) != s.end())
// 		{
// 			int curr = mp[{l,r}];
// 			int z = min(curr,cost);
// 			sum -= curr;
// 			sum += z;
// 			mp[{l,r}] = z;
// 			return ;
// 		}
// 		// if this range[l,r] is fully contained
// 		// in another [l1,r1] then do nothing

// 		// otherwise if delete all ranges[l0,r0] that
// 		// are contained fully in this [l,r]


// 		// then insert the range [l,r]

// 		// add it's sum
// 	}
// 	int ans()
// 	{
// 		return sum;
// 	}
// };
signed main(){
	fast_io();
    
    return 0;
}