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
	
    int n,m;
    cin >> n >> m;
    vi arr(m);
    input(arr);
    // output(arr);
    int ini = 1;
    int ans = 0;
    for(int i=0;i<m;i++){
    	int s = arr[i];
    	// cout << ini << s << endl;
    	if(s < ini){
    		ans+=(n-ini) + s;
    		ini = s;
    	}
    	else{
    		int dist = max(1LL*0,s-ini);
    		ans+= dist;
    		ini = s;
    	}
    }
    cout << ans << endl;
    return 0;
}