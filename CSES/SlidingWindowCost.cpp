#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
using namespace __gnu_pbds;

#define indexed_set tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>
template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

/* 
for fast input output use printf and scanf;
*/

struct cost
{
	indexed_set st;
	int c = 1;
	// ordered_multiset<int> ms;
	// multiset<int> left,right;
	int sum = 0;
	void print()
	{
		for(auto it:st)
		{
			cout << it.first << " ";
		}
		cout << endl;
	}
	void insert(int x)
	{
		sum += x;
		st.insert({x,c++});
		
	}
	void remove(int x)
	{
		sum -= x;
		auto it = st.lower_bound({x,0});
		if(it != st.end() && it->first == x)
		{
			st.erase(it);
		}
		// print();
		
	}
	int findMedian()
	{

		int l = st.size();
		int idx = l/2;
		auto mid = st.find_by_order(idx);
		if(l % 2 == 0)
		{
			int a = mid -> first;
			int b = (--mid) -> first;
			return (a+b)/2;
		}
		else return mid -> first;
		return 0;
	}
	int answer()
	{
		int med = findMedian();
		int l = st.order_of_key({med,0});
		print();
		cout << med << " " << l << endl; 
		int low = l;
		int high = st.size() - low;
		cout << low << " " << high << endl;
		cout << sum << endl;
		int ans = sum - (high*med - low*med);
		cout << ans << endl;
		return ans;
	}
};
signed main(){
	fast_io();
    int n,k;
    cin >> n >> k;
    vi arr(n);
    input(arr);
    cost c;
    for(int i=0;i<k;i++)
    {
    	c.insert(arr[i]);
    }
    for(int i=k;i<n;i++)
    {
    	c.answer();
    	// cout << c.answer() << " ";
    	int rem = arr[i-k];
    	c.insert(arr[i]);
    	c.remove(rem);
    }

    return 0;
}