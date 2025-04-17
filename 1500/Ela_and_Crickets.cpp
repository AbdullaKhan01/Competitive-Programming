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
#define endl '\n'
using namespace std; 
/* 
for fast input output use printf and scanf;
*/
bool haveSameSign(int x,int y)
{
	return (x&1) == (y&1);
}
signed main(){
	fast_io();
    ll tt;
    cin >> tt;
    while(tt--)
    {
        int n;
        cin >> n;
        int r1,c1,r2,c2,r3,c3;
        cin >> r1 >> c1 >> r2 >> c2 >> r3 >> c3;
        int row = 0 , col = 0;
        if(r1 == r2)
        {
        	col = (c3+1) % 2;
        	row = (r3) % 2;
        }
        else if(r1 == r3)
        {
        	col = (c2+1) % 2;
        	row = (r2) % 2;
        }
        else
        {
        	col = (c1+1) % 2;
        	row = (r1) % 2;
        }
        // cout << row << " " << col << endl;
        int x,y;
        cin >> x >> y;
        if(haveSameSign(row,x) && haveSameSign(col,y))
        {
        	cout << no << endl;
        }
        else
        {
        	cout << yes << endl;
        }
    }
    return 0;
}