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
		
	    int x1,y1,x2,y2;
	    cin >> x1 >> y1 >> x2 >> y2;
	    int rook,bis=0,king;
	    rook = 2 - (x2 == x1 || y2 == y1);
	    king = max(abs(x2-x1),abs(y2-y1));
	    int summ = x1 + y1;
	    int diff = x1 - y1;
	    //diagonal one
	    for(int i=1;i<=8;i++){
	    	int x = i;
	    	int y = summ - x;
	    	// cout << x << " " << y << endl;
	    	if(x == x2 && y==y2) {bis = 1;break;}
	    	int diff = x - y;
	    	for(int ii=1;ii<=8;ii++){
	    		int xx = ii;
	    		int yy = xx - diff;
	    		if(xx == x2 && yy == y2) bis = 2;
	    	}
	    }
	    //diagonal two
	    if(bis==1){
	    	cout << rook << " " << bis << " " << king << endl;
	    	return 0;
	    }
	    for(int i=1;i<=8;i++){
	    	int x = i;
	    	int y = x - diff;
	    	// cout << x << " " << y << endl;
	    	if(x == x2 && y == y2) {bis = 1;break;}
	    	int sum = x+y;
	    	for(int ii=1;ii<=8;ii++){
	    		int xx = ii;
	    		int yy = sum - xx;
	    		if(xx == x2 && yy == y2) bis = 2;
	    	}
	    }
	    cout << rook << " " << bis << " " << king << endl;
	    return 0;
	}