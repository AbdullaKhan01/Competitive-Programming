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
    int l=-2*1e9,h=2*1e9;
    while(tt--)
    {
        string a;int n;char ans;
        cin >> a >> n >> ans;
        // cout << a << n << ans << endl;
        if(ans == 'Y'){
	        if(a==">="){
	        	l = max(l,n);
	        }
	        else if(a==">"){
	        	l = max(l,n+1);
	        }
	        else if(a=="<="){
	        	h =  min(h,n);
	        }
	        else{
	        	h = min(h,n-1);
	        }
    	}
    	if(ans == 'N'){
    		if(a==">="){
	        	h = min(h,n-1);
	        	// l = max(l,n);
	        }
	        else if(a==">"){
	        	h =  min(h,n);
	        	// l = max(l,n+1);
	        }
	        else if(a=="<="){
	        	l = max(l,n+1);
	        	// h =  min(h,n);
	        }
	        else{
	        	l = max(l,n);
	        	// h = min(h,n-1);
	        }
    	}
    }
    // cout << l << h << endl;
    if(h<l){
    	cout << "Impossible" << endl;
    }
    else{
    	cout << l << endl;
    }
    return 0;
}
// 1000000000
// -1998638045