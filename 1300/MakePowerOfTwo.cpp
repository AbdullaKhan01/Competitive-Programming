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
vector<int> powers;
void init(){
	int a = 1;
	for(int i=0;i<64;i++){
		powers.pb(a);
		a*=2;
	}
}
signed main(){
	
	init();

	int tt;
	cin >> tt;
	while(tt--)
	{
	    int n;
	    cin >> n;
	    int ans = INT_MAX;
	    for(auto it:powers){

	    	string a = to_string(n);
	    	string b = to_string(it);
	    	int i = 0,j=0;
	    	int del = 0;
	    	while(i<a.size() && j<b.size()){
	    		if(a[i] == b[j]){
	    			del++;
	    			i++;
	    			j++;
	    		}
	    		else{
	    			i++;
	    		}
	    	}
	    	int cost = del;
	    	int ap = a.size() - cost + b.size() - cost;
	    	
	    	ans = min(ans,ap);
	    	
	    }
	    cout << ans << endl;
	}
    return 0;
}