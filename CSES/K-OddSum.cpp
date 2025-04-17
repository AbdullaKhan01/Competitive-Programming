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
        int n,k;
        cin >> n >> k;
        if( k == n-1){
        	for(int i=1;i<=n;i++){
        		cout << i << " ";
        	}
        	cout << endl;
        }
        else{
        	vector<int> ans;
        	int l = k/2;
        	int max = l * 2;
        	int start = 1;
        	bool flag = false;
        	int m = -1;
        	while(l--){
        		ans.pb(start);
        		ans.pb(start+1);
        		start+=2;
        		if(start >= max) break;
        	}
        	
        	if(k%2 == 0 && !ans.empty()){
        		flag = true;
        		m = ans.back();
        		ans.ppb();
        	}
        	for(int i = start;i<=n ; i+=2) ans.pb(i);
        	for(int i = start + 1 ; i<=n ; i+=2) ans.pb(i);
        	if(flag) cout << m << " ";
        	output(ans);
        	cout << endl;
        }
    }
    return 0;
}