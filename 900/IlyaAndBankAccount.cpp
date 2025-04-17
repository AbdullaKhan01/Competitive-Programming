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
    if(n>=0){
    	cout << n << endl;
    }
    else{
    	if(n>=-9){
    		cout << 0 << endl;
    	}
    	else{
    		// int p = abs(n);
    		// int q = p%10;
    		// int v = (p/10)%10;
    		// string s;
    		string s = to_string(n);
    		int p = s.size();
    		if(s[p-2]>=s[p-1]) s.erase(p-2,1);
    		else s.erase(p-1,1);
    		if(s == "-0") s = "0"; 
    		cout << s << endl;
    		// if(v!=0) n/=10;
    		// else n+=q;
    		// cout << n << endl;
    	}
    }
    return 0;
}