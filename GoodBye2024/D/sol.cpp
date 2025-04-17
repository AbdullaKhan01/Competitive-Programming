#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// #define mod 1000000007
#define mod 998244353
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
/* 
for fast input output use printf and scanf;
*/
template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

ll modAdd(ll a,ll b){
    ll p = (a%mod + b%mod)%mod;
    return p;
}
ll modSub(ll a,ll b){
    ll p = (a%mod - b%mod)%mod;
    if(p<0) p+=mod;
    return p;
}
ll modMul(ll a,ll b){
    ll p = (a%mod * b%mod)%mod;
    return p;
}
int pw(int a,int p=mod-2){
	int result = 1;
	while(p>0){
		if(p&1)
			result = a*result %mod;
		a = a * a %mod;
		p >>= 1;
	}
	return result;
}

ordered_multiset<int> ms1,ms2;
void print(ordered_multiset<int> &st){
	for(auto it : st){
		cout << it << " ";
	}
	cout << endl;
}
void print2(ordered_set &st){
	for(auto it : st){
		cout << it << " ";
	}
	cout << endl;
}
void solve()
{
	ms1.clear();
	ms2.clear();
	int n,q;
	cin >> n >> q;
	vector<int> a(n);
	vector<int> b(n);
	
	for(int i=0;i<n;i++){
		cin >> a[i];
		ms1.insert(a[i]);
	}
	for(int i=0;i<n;i++){
		cin >> b[i];
		ms2.insert(b[i]);
	}
	vector<int> c = a;
	vector<int> d = b;
	sort(all(c));
	sort(all(d));
	int ans = 1;
	for(int i=0;i<n;i++){	
		ans = modMul(ans,min(c[i],d[i]));
	}
	cout << ans << " ";
	// cout << ans << "query" << endl;
	while(q--){
		int type,index;
		cin >> type >> index;
		index--;
		int val;
		if(type == 1){

			val = a[index];
			// cout << "q1 " << val << endl;
			val += 1;
			int pos = ms1.order_of_key(val);
			if(pos > 0) pos--;
			// cout << pos << endl;
			auto v1 = ms1.find_by_order(pos);
			auto v2 = ms2.find_by_order(pos);
			if(*v2 > *v1){
				int inv = pw(*v1);
				// cout << "inverse of " << *v1 << "multiplied" << endl;
				ans = modMul(ans,inv);
				ans = modMul(ans,val);
				// cout << val << "multiplied" << endl;
			}
			else{
				// cout << "nothing done" << endl;
			}
			
			ms1.erase(v1);
			ms1.insert(val);
			a[index] = val;
		}
		else{

			val = b[index];
			val += 1;
			int pos = ms2.order_of_key(val);
			if(pos > 0) pos--;
			auto v1 = ms2.find_by_order(pos);
			auto v2 = ms1.find_by_order(pos);
			if(*v2 > *v1){
				int inv = pw(*v1);
				ans = modMul(ans,inv);
				ans = modMul(ans,val);
			}
			else{
				// cout << "nothing done" << endl;
			}
			// cout << val << endl;
			// cout << "done" << endl;
			ms2.erase(v1);
			ms2.insert(val);
			// print(ms2);
			b[index] = val;
		}
		cout << ans << " ";
	}
	cout << endl;
	// print(ms1);
	// print(ms2);
}
void test(){
	ordered_set ms;
	ms.insert(1);
	ms.insert(1);
	ms.insert(1);
	ms.insert(2);
	ms.insert(2);
	ms.insert(2);
	ms.insert(3);
	print2(ms);
	auto it = ms.find_by_order(2);
	cout << *it << endl;
	// cout << *it << endl;
	// ms.erase(ms.find_by_order(2));
	// print(ms);
	// cout << ms.order_of_key(3) << endl;
	// cout << *ms.find_by_order(5) << endl;
}
signed main(){
	fast_io();
    int tt = 1;
    cin >> tt;
    while(tt--)
    {
    	solve();
    	// test();
    }
    return 0;
}