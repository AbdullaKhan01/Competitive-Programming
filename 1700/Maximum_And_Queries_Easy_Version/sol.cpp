// #include<bits/stdc++.h>
// #define mod 1000000007
// #define mod2 998244353
// #define ceil(a,b) ((a+b-1)/b)
// #define floor(a,b)((a-b+1)/b)
// #define fast_io() ios::sync_with_stdio(0);cin.tie(0);
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
// /* 
// for fast input output use printf and scanf;
// */
// int getV(int &val,int &bit){
// 	int idx = 0;
// 	int m = val;
// 	while(idx < bit){
// 		m &= ~(1LL << idx);
// 		idx++;
// 	}
// 	m |= (1LL << bit);
// 	return val - m;
// }
// void solve()
// {
// 	int n,q;
// 	cin >> n >> q;
// 	vector<int> a(n);
// 	for(int i=0;i<n;i++){
// 		cin >> a[i];
// 	}
// 	vector<int> f(32,0);
// 	for(int i=0;i<32;i++){
// 		for(int j=0;j<n;j++){
// 			if(1 & (a[j] >> i))continue;
// 			else{
// 				f[i] += getV(a[j],i);
// 			}
// 		}
// 	}
// 	while(q--){
// 		int x;cin >> x;
// 		int s = 0 , e = INT_MAX;
// 		while(s <= e){
// 			int ans = s;
// 			int mid = (s + e)/2;
// 			bool flag = true;
// 			for(int i=0;i<32;i++){
// 				if(1 & (mid >> i)){

// 				}
// 			}
// 			if(flag){
// 				ans = mid;
// 				s = mid+1;
// 			}
// 			else e = mid - 1;
// 			cout << ans << endl;
// 		}
// 	}
// }
// signed main(){
// 	fast_io();
//     int tt = 1;
//     // cin >> tt;
//     while(tt--)
//     {
//     	solve();
//     }
//     return 0;
// }

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
/*

001
011
111
101

*/
int n,q;
vector<int> a;
int getV(int num,int bit){
	int val = (1LL << bit);
	for(int i=bit+1;i<=62;i++){
		if(num & (1LL << i)){
				val |= (1LL << i);
		}	
	}
	return val;
}
int getAns(int k){
	vector<int> l = a;
	int ans = 0;
	for(int bit=62;bit>=0;bit--){
		int cnt = 0;
		for(int i=0;i<n;i++){
			int number = l[i];
			int make = getV(number,bit);
			int want = make - number;
			if(want>0) cnt += want;
			if(cnt > k) break;
		}
		if(k >= cnt){
			k -= cnt;
			ans |= (1LL << bit);
			for(int i=0;i<n;i++){
				l[i] = max(l[i],getV(l[i],bit));
			}
		}
	}
	return ans;
}
void solve()
{
	cin >> n >> q;
	a.assign(n,0);
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	while(q--){
		int k;cin >> k;
		cout << getAns(k) << endl;
	}
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