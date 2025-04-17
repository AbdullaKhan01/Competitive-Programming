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
	
    ll tt;
    cin >> tt;
    while(tt--)
    {
        int h,w,x1,y1,x2,y2;
        cin >> h >> w >> x1 >> y1 >> x2 >> y2;
        int req = abs(x1-x2);
        int q = req/2;
        int p = ceil(req,2);
        int row = x1 + p;
        int win = 0;
        int z = 1;
        int mla = max(z,y1-p);
        int mra = min(w,y1+p); 
        int mlb = max(z,y2-q);
        int mrb = min(w,y2+q); 
        // cout << mla << " " << mra << " " << mlb << " " << mrb << endl;
        if(x2 - x1 < req){
        	cout << "Draw" << endl;
        	continue;
        }
        if(row - x1 <= x2 - row){
        	if(mlb<=mla && mrb>=mra){
        		win = 1;
        	}
        }
        else{
        	if(mla<=mlb && mra>=mrb){
        		win = -1;
        	}
        }
        if(win == -1){
        	cout << "Alice" << endl;
        }
        else if(win == 1){
        	cout << "Bob" << endl;
        }
        else{
        	cout << "Draw" << endl;
        }
    }
    return 0;
}