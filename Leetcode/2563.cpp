#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
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
/* 
for fast input output use printf and scanf;
*/
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_multiset;
class PBDS_multiset{
    // *If you want to change your multi ordered set data type,you should change almost everything in the above functions.
    public:
    ordered_multiset s;
    void insert(int x){ //this function inserts one more occurrence of (x) into the set.
         s.insert(x);
    }
    bool exist(int x){ //this function checks weather the value (x) exists in the set or not.
         if((s.upper_bound(x))==s.end()){
            return 0;
         }
         return ((*s.upper_bound(x))==x);
    }
    void erase(int x){ //this function erases one occurrence of the value (x).
         if(exist(x)){
            s.erase(s.upper_bound(x));
         }

    }
    int firstIdx(int x){ //this function returns the first index of the value (x)..(0 indexing).

        if(!exist(x)){
            return -1;
        }
        return (s.order_of_key(x));

    }
    int value(int idx){ //this function returns the value at the index (idx)..(0 indexing).

       return (*s.find_by_order(idx));

    }
    int lastIdx(int x){ //this function returns the last index of the value (x)..(0 indexing).

        if(!exist(x)){
            return -1;
        }
        if(value((int)s.size()-1)==x){
            return (int)(s.size())-1;
        }
        return firstIdx(*s.lower_bound(x))-1;

    }
    int count(int x){ //this function returns the number of occurrences of the value (x).

         if(!exist(x)){
            return 0;
         }
         return lastIdx(x)-firstIdx(x)+1;

    }
    int less_than_equal(int x){
        // returns number of elements less than equal to x
        if(s.empty()) return 0;
        return s.order_of_key(x+1);
    }
    int less_than(int x){
        // return number of elements less than x
        return less_than_equal(x-1);
    }
    int greater_than(int x){
        // return number of elements greater than x
        return (int)(s.size()) - less_than_equal(x);
    }
    int greater_than_equal(int x){
        // return number of elements greater than equal to x
        return (int)(s.size()) - less_than(x);
    }
    int between(int l,int r){
        return less_than_equal(r) - less_than_equal(l-1);
    }
    void print(){
        for(auto it : s){
            cout << it << " ";
        }
        cout << endl;
    }
    void clear(){ //this function clears all the elements from the set.
         s.clear();

    }
    int size(){ //this function returns the size of the set.
         return (int)(s.size());
    }
};

void solve()
{
	vector<int> a = {1,7,9,2,5};
	int lower = 11,upper = 11;
	PBDS_multiset ms;
	int n = a.size();
	int ans = 0;
	for(int i=0;i<n;i++){
		// 
		int lb = lower - a[i];
		int ub = upper - a[i];
		int val = ms.between(lb,ub);
		// ms.print();
		// cout << a[i] << " " << lb << " " << ub << " " << val << endl;    
		ans += max(0LL,val);
		ms.insert(a[i]);
	}
	
	cout << ans << endl;
	// ms.print();
	// cout << ms.less_than_equal(2) << endl;

}
signed main(){
	fast_io();
    int tt = 1;
    // cin >> tt;
    while(tt--)
    {
    	solve();
    }
    return 0;
}

