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
	
    string a,b;
    cin >> a >> b;
    if(a.size()!=b.size()){
    	cout << "NO" << endl;
    	return 0;
    }
    char x,y;
    char n,m;
    int cnt = 0;
    for(int i=0;i<a.size();i++){
    	if(a[i]!=b[i]){
    		cnt++;
    		if(cnt == 1){
    			x = a[i];
    			n = b[i];
    		}
    		else{
    			y = a[i];
    			m = b[i];
    		}
    	}
    }
    if(cnt == 0){
    	cout << "YES" << endl;
    	return 0;
    }
    if(cnt == 2 && x==m && y==n){
    	cout << "YES" << endl;
    	return 0;
    }
    cout << "NO" << endl;
    return 0;
}