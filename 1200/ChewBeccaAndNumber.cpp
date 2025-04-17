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
	
    string s;
    cin >> s;
    bool first = true;
    for(int i=0;i<s.size();i++){
    	if(s[0] == '9'){
    		if(first){
    			first = false;
    			continue;
    		} 
    	}
    	int p = s[i]-48;
    	if(p>=5){
    		s[i] = (9 - p) + 48;
    	}
    }
    cout << s << endl;
    return 0;
}