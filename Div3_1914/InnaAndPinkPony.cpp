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
	
    int n,m,i,j,a,b;
    cin >> n >> m >> i >> j >> a >> b;
    int up = i-1;
    int down = n - i;
    int left = j - 1;
    int right = m - j; 
    int ans = INT_MAX;
    // cout << up << " " << down << " " << left << " " << right;
    // if(up%a == 0 && left%b == 0){
    // 	// ans = min(ans,(up/a + left/b));
    // 	if(left % (2*b) == 0){
    // 		ans = min(ans,up/a + left/b);
    // 	}
    // }
    // if(up%a == 0 && right%b == 0){
    // 	// ans = min(ans,(up/a + right/b));
    // 	if(right % (2*b) == 0){
    // 		ans = min(ans,up/a + right/b);
    // 	}
    // }
    // if(down%a == 0 && left%b == 0){
    // 	// ans = min(ans,(down/a + left/b));
    // 	if(left % (2*b) == 0){
    // 		ans = min(ans,down/a + left/b);
    // 	}
    // }
    // if(down%a == 0 && left%b == 0){
    // 	// ans = min(ans,(down/a + right/b));
    // 	if(right % (2*b) == 0){
    // 		ans = min(ans,down/a + right/b);
    // 	}
    // }
    // if(ans != INT_MAX){
    // 	cout << ans << endl;
    // }
    // else{
    // 	cout << "Poor Inna and pony!" << endl;
    // }
    if(up % a == 0){

    	int l1 = left,r1=right;
    	if(up%(2*a) != 0) l1 -= b,r1-=b; 
    	if(l1 % (2*b) == 0){
    		cout << "UL" << endl;
    		ans = min(ans,up/a + l1/b);
    	}
    	if(r1 % (2*b) == 0){
    		cout << "UR" << endl;
    		ans = min(ans,up/a + r1/b);
    	}
    }
    if(down % a == 0){
    	int l1 = left,r1=right;
    	if(down%(2*a) != 0) l1 -=b,r1-=b; 
    	if(l1 % (2*b) == 0){
    		cout << "DL" << endl;
    		ans = min(ans,down/a + l1/b);
    	}
    	if(r1 % (2*b) == 0){
    		cout << "DR" << endl;
    		ans = min(ans,down/a + r1/b);
    	}
    }
    if(left % b == 0){
    	int u1 = up,d1=down;
    	if(left%(2*b) != 0) u1 -=a,d1-=a; 
    	if(u1 % (2*a) == 0){
    		cout << "LU" << endl;
    		ans = min(ans,u1/a + left/b);
    	}
    	if(d1 % (2*a) == 0){
    		cout << "LD" << endl;
    		ans = min(ans,d1/a + left/b);
    	}
    }
    if(right % b == 0){
    	int u1 = up,d1=down;
    	if(right%(2*b) != 0) u1-=a,d1-=a; 
    	if(u1 % (2*a) == 0){
    		cout << "RU" << endl;
    		ans = min(ans,u1/a + right/b);
    	}
    	if(d1 % (2*a) == 0){
    		cout << "RD" << endl;
    		ans = min(ans,d1/a + right/b);
    	}
    }
    if(ans!=INT_MAX){
    	cout << ans << endl;
    }
    else{
    	cout << "Poor Inna and pony!" << endl;
    }
    return 0;
}