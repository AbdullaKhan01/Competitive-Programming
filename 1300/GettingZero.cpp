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
// int solve(int n){
// 	int power = 0 , cnt = 0;
// 	if(n%2 != 0) n++,cnt++;
// 	while(n%2 == 0){
// 		power++;
// 		n/=2;
// 	}
// 	int ans = max(15-power,1LL*0) + cnt;
// 	return ans;
// }
// signed main(){
	
//     int n;
//     cin >> n;
//     vi arr(n);
//     input(arr);
//     vector<int> pref(n,0);
//     vector<int> suff(n,0);
//     set<int> s;
//     int mn = 2;
//     for(int i=1;i<=15;i++){
//     	s.insert(mn);
//     	mn*=2;
//     }
//     for(int i=0;i<n;i++){
//     	pref[i] = solve(arr[i]);
//     }
//     for(int i=0;i<n;i++){
//     	suff[i] = *s.lower_bound(arr[i]);
//     }
//   	for(int i=0;i<n;i++){
  		
//   		if(arr[i] == 0){
//   			cout << 0 << " ";
//   			continue;
//   		}
//   		int a = pref[i];
//   		int b = (suff[i] - arr[i]) + (32678/suff[i]);
//   		cout << min(a,b) << " "; 
  		
//   	}
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
const int mmod = 32678; 
signed main(){
	
    int n;
    cin >> n;
    vi arr(n);
    input(arr);
    for(int i=0;i<n;i++){
    	if(arr[i] == 0){
    		cout << 0 << " ";
    		continue;
    	}
    	int best = INT_MAX;
    	for(int j=0;j<=15;j++){
    		int l = arr[i] + j;
    		int cnt = 0;
    		while(l % 2 == 0) cnt++,l/=2;
    		int ans = j+15-cnt;
    		best = min(best,ans);
    	}
    	cout << best << " ";
    }
    return 0;
}