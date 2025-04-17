#include<bits/stdc++.h>
#define mod 1000000007
#define mod2 998244353
#define ceil(a,b) ((a+b-1)/b)
#define floor(a,b)((a-b+1)/b)
#define fast_io() ios::sync_with_stdio(0);cin.tie(0);
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
// #define endl '\n'
using namespace std; 
/* 
for fast input output use printf and scanf;
*/
int query(int x,int y){
	cout << "? " << x << " " << y << endl;
	int a;
	cin >> a;
	return a;
}
void printAns(int x,int y){
	cout << "! " << x <<  y << endl;
}
void solve()
{
	int n,m;
	cin >> n >> m;
	// interactive problem
	int d1 = query(1,1);
	
	int x1 = 1+d1;
	int y1 = 1 + (x1 > m ? x1-m);
	x1 = min(x1,m);

	int y2 = 1+d1;
	int x2 = 1 + (y2>n ? y2-n);
	y2 = min(y2,n);


	int d2 = query(x1,y1);

	int d3 = query(x2,y2);

	int a = x1 - (d2/2);
	int b = y1 - (d2/2);

	int c = x2 + (d3/2);
	int d = y2 + (d3/2);

	if(d2 % 2 != 0){
		printAns(c,d);
		return;
	}
	if(d3 % 2 != 0){
		printAns(a,b);
		return;
	}
	int d4 = query(a,b);
	if(d4 == 0){
		printAns(a,b);
		return;
	}
	printAns(c,d);

}
signed main(){
	fast_io();
    int tt = 1;
    cin >> tt;
    while(tt--)
    {
    	solve();
    }
    return 0;
}