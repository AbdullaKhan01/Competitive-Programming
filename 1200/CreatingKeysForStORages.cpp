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
// void solve()
// {
// 	int n,x;
// 	cin >> n >> x;
// 	vector<int> maybe;
// 	int k = 0;
// 	while(maybe.size() < n && k <= x){
// 		bool flag = true;
// 		for(int i=0;i<32;i++){
// 			if(x & (1 << i)){
// 				// bit is 1 at this position
// 			}
// 			else{
// 				// bit is 0 at this position
// 				if(k & (1<<i)){
// 					// k has bit 1 at this position
// 					flag = false;
// 				}
// 			}
// 		}
// 		if(flag){
// 			maybe.push_back(k);
// 		}
// 		k++;
// 	}
// 	int orry = 0;
// 	for(int i=0;i<maybe.size();i++){
// 		orry |= maybe[i];
// 	}
// 	if(orry != x){
// 		maybe.pop_back();
// 		maybe.push_back(x);
// 	}
// 	while(maybe.size() < n) maybe.push_back(x);
// 	output(maybe);
// 	cout << endl;
// }
// signed main(){
// 	fast_io();
//     int tt = 1;
//     cin >> tt;
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
void solve()
{
	int n,x;
	cin >> n >> x;
	vector<int> ans;
	int num = 0;
	int orry = 0;
	while(ans.size() < n){
		bool flag = true;
		for(int i=0;i<32;i++){
			if(x & (1 << i)){
				// x has 1 bit at this position
				// num can have either 0 or 1 so ignore
				continue;
			}
			else{
				// x has 0 bit in this position so num
				// cannot have 1 bit at this position
				if(num & (1 << i)){
					flag = false;
					break;
				}
			}
		}
		if(flag == false){
			break;
		}
		else{
			// num can be the number of this array
			// check if the or has been already x then 
			// insert num otherwise if 1 more space is 
			// available
			if((orry|num) == x || ans.size() < (n-1)){
				ans.push_back(num);
				orry |= num;
				num++;
			}
			else{
				break;
			}
		}
	}
	while(ans.size() < n){
		ans.push_back(x);
	}
	for(auto it : ans){
		cout << it << " ";
	}
	cout << endl;
}
signed main(){
	fast_io();
    int tt = 1;
    cin >> tt;
    while(tt--)
    {
    	solve();
    }
    return 0;
}