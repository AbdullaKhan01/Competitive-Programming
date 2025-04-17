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
FIBONACCI NUMBERS

F0 = 0 , F1 = 1
Fn = Fn-1 + Fn-2 n>=2

0,1,1,2,3,5,8,13,21,34..........


Identities 

1. summation i from 0 to n Fi = Fn+2 - 1

2. summation i from 0 to n (Fi)^2 = Fn * Fn+1 

3. Convolution Property 
Fn = Fm*Fn-m+1 + Fm-1*Fn-m

4. Fn divides F(k*n) Fn|F(k*n)
conversly 
if Fn divides Fm then n divides m or n is a factor of m

if Fn | Fm then n|m for n > 2

5. GCDs(Fn,Fm) = Fgcd(n,m)


*/
pair<int, int> fib (int n) {
    if (n == 0)
        return {0, 1};

    auto p = fib(n >> 1);
    int c = p.first * (2 * p.second - p.first);
    int d = p.first * p.first + p.second * p.second;
    if (n & 1)
        return {d, c + d};
    else
        return {c, d};
}
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