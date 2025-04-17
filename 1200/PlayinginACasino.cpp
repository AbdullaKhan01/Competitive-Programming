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
signed main(){
	
    ll tt;
    cin >> tt;
    while(tt--)
    {
 		int n,m;
 		cin >> n >> m;
 		vector<vector<int>>arr(m);
 		for(int i=0;i<n;i++){
 			for(int j=0;j<m;j++){
 				int x;
 				cin >> x;
 				arr[j].pb(x);
 			}
 		}
 		for(int i=0;i<m;i++){
 			sort(all(arr[i]));
 		}
		int ans = 0;
		for(int i=0;i<m;i++){
			int n = arr[i].size();
			for(int k = 0 ; k < n;k++){

				int p = k * arr[i][k];
				int q = max(1LL*0,n-k-1) * -arr[i][k];
				// cout << k << " " << p << " " << q << endl;
				ans+= p + q;
			}
			// cout << endl;
		}
		cout << ans << endl; 		       
    }
    return 0;
}