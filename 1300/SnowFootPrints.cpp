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
    string s;cin >> s;
    int r=0,a=0,b=0,l=0;
    for(int i=0;i<n;i++){
    	if(s[i]=='R'){
    		r = i+1;
    		break;
    	}
    }
    for(int i=0;i<n;i++){
    	if(s[i]=='L'){
    		l = i+1;
    		break;
    	}
    }
    for(int i=n-1;i>=0;i--){
    	if(s[i]=='R'){
    		a = i+1;
    		break;
    	}
    }
    for(int i=n-1;i>=0;i--){
    	if(s[i]=='L'){
    		b = i+1;
    		break;
    	}
    }
    if(r == 0){
    	cout << b << " " << l-1 << endl;
    }
    else if(l == 0){
    	cout << r << " " << a+1 << endl;
    }
    else{
    	cout << r << " " << l << endl;
    }
    return 0;
}