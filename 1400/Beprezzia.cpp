// #include<bits/stdc++.h>
// #define mod 1000000007
// #define mod2 998244353
// #define ceil(a,b) ((a+b-1)/b)
// #define ll long long
// #define int long long
// #define vi vector<int>
// #define all(x) (x).begin(),(x).end()
// #define rall(x) (x).rbegin(),(x).rend()
// #define input(x) for(auto &a:x) cin >> a;
// #define output(x) for(auto a:x) cout << a <<" ";
// #define rep(i,a,n) for(int i=(a);i<n;i++)
// #define pb push_back
// #define ppb pop_back
// #define pf push_front
// #define ppf pop_front
// #define ff first
// #define ss second
// #define si set<int>
// #define pii pair<int,int>
// #define mii map<int,int>
// #define msi map<string,int>
// #define yes "YES"
// #define no "NO"
// #define endl '\n'
// using namespace std; 
// static bool cmp(pii &a,pii &b){

// }
// static bool cmp2(pii &a,pii &b){
	
// }
// signed main(){
	
//     int q;
//     cin >> q;
//     set<pair<int,int>>a1,a2;
//     int cust = 1;
//     while(q--){
//     	int a;
//     	cin >> a;
//     	if(a == 1){
//     		int g;
//     		cin >> g;
//     		a1.insert({cust,g},cmp);
//     	}
//     	else if(a == 2){
//     		//
//     	}
//     	else{
//     		// a = 3
//     	}
//     }
//     return 0;
// }
#include<bits/stdc++.h>
#define mod 1000000007
#define mod2 998244353
#define ceil(a,b) ((a+b-1)/b)
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
static bool cmp(pii &a,pii &b){
	return a.first >= b.first;
}
signed main(){
	
    map<int,int> mp;
    mp.insert({1,2});
    mp.insert({2,3});
    sort(mp.begin(),mp.end(),cmp);
    for(auto it:mp){
    	cout << it.first << " " << it.second << endl;
    }
    return 0;
}