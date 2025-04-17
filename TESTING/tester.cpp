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
#define endl '\n'
using namespace std;  
/* 
for fast input output use printf and scanf;
*/
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int SIZE = 20;
// max array size
const int NUM = 20;
// max element in the array

int number(int a,int b){
	// generates random number in the range a to b
	return a + rng() % (b - a + 1);
}
vector<int> Array(int n){

	vector<int> a(n);
	for(int i=0;i<n;i++){
		// IF NUMBERS POSITIVE CHANGE 0 to 1
		a[i] = number(1,NUM);
	}
	return a;
}
vector<int> uniqueArray(){
	int n = number(1,SIZE);
	set<int> st;
	while(st.size() != n){
		// IF NUMBERS POSITIVE CHANGE 0 to 1
		st.insert(number(0,NUM));
	}
	vector<int> a;
	for(auto it : st){
		a.push_back(it);
	}
	return a;
}
signed main(){
	cout << 1 << endl;	
	int n = number(3,10);
	int k = number(1,n);
	cout << n << " " << k << endl;
	vector<int> a = Array(n);
	for(int i=0;i<n;i++){
		cout << a[i] << " ";
	}
  return 0;
}