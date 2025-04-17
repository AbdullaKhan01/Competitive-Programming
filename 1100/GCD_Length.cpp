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
	
    vector<int> arr={0,2,11,101,1009,10007,100003,1000003,10000019,
					1000000007};
	ll tt;
	cin >> tt;
	while(tt--)
	{
	    int a,b,c;
	    cin >> a >> b >> c;
	    int l = arr[c];
	    if(c == 9){
	    	cout << l << " " << l << endl;
	    	continue;
	    }
	    if(c == 1 && a==1 && b==1){
	    	cout << 2 << " " << 2 << endl;
	    	continue;
	    }
	    else{
	    	int aa,bb;
	    	if(a == c)
	    		aa = pow(10,a);
	    	else
	 			aa = pow(10,a-1);
	 		if(b == c)
	 		  bb = pow(10,b);
	 		else 
	 			bb = pow(10,b-1);
	 		cout << (aa + (l - aa%l)) << " " << (bb+ (l - bb%l)) << endl;
	    }
	}
    return 0;
}