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
			
	    int r1,r2,c1,c2,d1,d2;
	    cin >> r1 >> r2 >> c1 >> c2 >> d1 >> d2;
	    int a,b,c,d;
	    // b+c = d2;
	    // b+d = c2;
	    // c+d = r1;
	    // d2 - b + d = r1;
	    // d - b = r1-d2;
	    // d + b = c2;
	    // 2 * d = r1-d2 + c2;
	    d = (r2-d2 + c2)/2;
	    b = c2 - d;
	    a = r1 - b;
	    c = c1 - a;

	    if(a==b || a==c || a==d || b==c||b==d || c==d){
	    	cout << -1 << endl;
	    	return 0;
	    }
	    if(a<=0 || b<=0 || c<=0 ||d<=0 || a>=10 || b>=10 || c>=10 ||d>=10){
	    	cout << -1 <<endl;
	    	return 0;
	    }
	    if(a+b!=r1 || a+c!=c1 || a+d!=d1 || b+c!=d2 || b+d!=c2 || c+d!=r2){
	    	cout << -1 << endl;
	    	return 0;
	    }
	    cout << a << " " << b <<endl;
	    cout << c << " " << d <<endl;

	    return 0;
	}