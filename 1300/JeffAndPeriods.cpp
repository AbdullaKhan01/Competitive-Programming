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
	
    int n;
    cin >> n;
    vi arr(n);
    map<int,vector<int>>mp;
    rep(i,0,n){
    	cin >> arr[i];
    	mp[arr[i]].pb(i);
    }
    vector<pii> store;
    // if((store.size() == 0) == false){
    //     return 0;
    // }
    for(auto it:mp){
    	int m = it.first;
    	vector<int> ans = it.second;
    	if(ans.size() == 1){
    		store.pb({m,0});
    	}
    	else{
    		int diff = ans[1]-ans[0];
    		bool flag = true;
    		rep(i,1,ans.size()){
    			if(ans[i] - ans[i-1] != diff) flag = false;
    		}
    		if(flag) store.pb({m,diff});
    	}
    }
    cout << store.size() << endl;
    for(auto it:store){
    	cout << it.first << " " << it.second << endl;
    }
    return 0;
}