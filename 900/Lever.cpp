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
	
    string s;cin>>s;
    int p = s.find('^');
    int ans = 0;
    for(int i=0;i<s.size();i++){
    	if(s[i] == '=' || s[i] == '^') continue;
    	else{
    		if(i<p){
    			ans+= (s[i]-48)*(p-i);
    		}
    		else ans-= (s[i]-48) * (i-p);
    	}
    }
    cout << (ans==0?"balance":ans>0?"left":"right") << endl;
    return 0;
}