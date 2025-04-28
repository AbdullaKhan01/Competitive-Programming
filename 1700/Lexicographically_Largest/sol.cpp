#include<bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
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

template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

// order_of_key(x) no of elements less than x

/*
Think before Coding 

a[i] + i

Observation -> element is only affected by what is 
happening in the left no relation from right

lets say we have the a[i] + i values of all the elements
the value of leftmost element a[i] + i will never change
because it does not get affected from something in right
but it can affect some other elements i value

2 1
if(greater than 3 then will get used before last 3)
(always something <3) 3 cannot be >3 otherwise will get used 3

conclusion if 2 values have same number always use the first value

try to avoid duplicate values as much as possible


*/

// 3 5 4 2 1

// 3 3 3
// 3 2 2
// 3 2 1

// if duplicates first occurence of the number has 
// to be inserted first because any other occurence
// otherwise duplicate elements will be there

// if all duplicates just remove the elements from the
// right and u will have the lexicographically largest


// 7 6 7 3 6 3
// 7  
// 3 6 3 7 7 6 
// ans- 7 6 
// 4th 3 6 3 6 5 
// 2nd 3 2 5 4
// 7 6 5 4 3 2
// 7 6  

// 2 3 3 3
// 3 2 2 2
void solve(){
	
	int n;cin >> n;
	vector<int> a(n+1,0);
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	// >11 11 12 >11
	for(int i=1;i<=n;i++){
		int value = a[i] + i;
		// int neg  = greater_than_equal(value);
		// no of elements before it >= value
		// ms.insert(value - neg);
	}
	vector<int> ans;
	// for(auto it : ms){
	// 	ans.push_back(it);
	// }
	reverse(ans.begin(),ans.end());
	for(auto it : ans){
		cout << it << " ";
	}
	// 7 6 11
	cout << endl;
	
}
// 3 6 3 7 7 6
// 7 7 6 6 3 3 
// 2 5 1
void solve2(){
	int n;cin >> n;
	vector<int> a(n+1,2e9);
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n;i++){
		// val = a[i] + i - cposs
		// cposs <= i

		// find smallest cposs such that
		// a[i] + i - cposs is not present in the array
		// largest value of a[i] + i - cposs = 
		// a[i] + i
		// find first value < a[i] + i
		a[i] += i;
	}
	sort(a.begin()+1,a.end());
	reverse(a.begin() + 1,a.end());
	for(int i=1;i<=n;i++){
		a[i] = min(a[i],a[i-1]-1);
		cout << a[i] << " ";
	}
	cout << endl;
}
signed main(){
	fast_io();
    int tt = 1;
    cin >> tt;
    while(tt--)
    {
    	solve2();
    }
    return 0;
}