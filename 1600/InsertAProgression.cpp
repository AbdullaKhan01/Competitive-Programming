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
/*
some array -> a1 a2 a3 a4

so sum of absolute diff = (a2 - a1) + (a3 - a2) + (a4 - a3)

now lets say we insert x at the beginning 
then the sum increases by abs(a1-x);

let's say we insert x at the end of the array
then the sum increases by abs(a4-x)

and if we insert x at the middle of the array lets say
between a2 and a3
a1 a2 x a3 a4

then the sum increases by 
abs(x - a2) + abs(a3 - x) - (a3 - a2)

*/
void solve()
{
	
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