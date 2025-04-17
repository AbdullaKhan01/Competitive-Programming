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
    vector<pii> arr;
    int x=0,y=0;
    rep(i,0,n){
    	int a,b;
    	cin >> a >> b;
    	arr.pb({a,b});
    	x+=a,y+=b;
    }
    if(x%2 == 0 && y%2==0){
    	cout << 0 << endl;
    }
    else{
    	int ans = -1;
    	rep(i,0,n){
    		int p = arr[i].ff;
    		int q = arr[i].ss;
    		int z = x + (q-p);
    		int l = y + (p-q);
    		if(z%2 == 0 && l%2==0){
    			ans = 1;break;
    		}
    	}
    cout << ans << endl;
    }
    return 0;
}