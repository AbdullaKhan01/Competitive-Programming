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

// typedef tree<int, null_type, less<int>, rb_tree_tag,
//     tree_order_statistics_node_update>
//     ordered_set;
template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
/* 
for fast input output use printf and scanf;
*/


void update(ordered_multiset<int> &left,ordered_multiset<int> &right,int l,int r)
{
	left.insert(l);
	right.insert(r);
}
void print_l(ordered_multiset<int> &left)
{
	for(auto it:left)
	{
		cout << it << " ";
	}
}
void print_r(ordered_multiset<int> &right)
{
	for(auto it:right)
	{
		cout << it << " ";
	}
}
int query(ordered_multiset<int> &left,ordered_multiset<int> &right,int x)
{
	int a = 0;
	auto it = right.lower_bound(x);
	if(it!=right.begin())
	{
		it--;
		a = right.order_of_key(*it);
	}
	auto jt = left.upper_bound(x);
	int b = 0;
	if(it != left.end())
	{
		b = left.size() - left.order_of_key(*jt);
	}
	return a + b; 
}

// void solve()
signed main(){
	// fast_io();

	// solve();
    ll tt;
    cin >> tt;
    while(tt--)
    {
    	ordered_multiset<int> left,right;
    	update(left,right,1,6);
    	print_l(left);
    }
    return 0;
}