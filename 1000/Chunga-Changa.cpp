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
	
    int x,y,z;
    cin >> x >> y >> z;
    int t = 0;
    int c1 = max(x%z,t);
    int c2 = max(y%z,t);
    // cout << c1 << " " << c2 << endl;
    int x1 = x/z + y/z;
    if(c1+c2>=z){
    	cout << x1+1 << " " << min(z-c1,z-c2) << endl;
    }
    else{
    	cout << x1 << " " << 0 << endl;
    }

    return 0;
}