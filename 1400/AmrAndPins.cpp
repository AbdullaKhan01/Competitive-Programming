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
int distance(int x1,int y1,int x2,int y2){
	int l = (x2-x1);
	int m = (y2-y1);
	int dis = ((l*l) + (m*m));
	int dd = sqrt(dis);
	if(dd * dd == dis){
		return dd;
	}
	else return dd+1;

	// int dis = sqrt( pow(x2-x1,2) + (pow(y2-y1,2)) );
	// return dis;
}
signed main(){
	
    int r,x,y,x1,y1;
    cin >> r >> x >> y >> x1 >> y1;
    int ans = distance(x,y,x1,y1);
    // cout << ans << endl;	
    cout << ceil(ans,(2*r)) << endl;
    return 0;
}