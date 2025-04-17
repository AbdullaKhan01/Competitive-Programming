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

Number of Ways to choose k items from a set of n (different)
items is called nCr

nCr =  (n!)/((n-r)!(r)!)

There are 3 ways of calculating nCr

1st when n<=10^6 and r<=10^6 and mod = Prime

factorials method -> precompute all the factorials
from 1 to 10^6 mod Prime also calculate the inverse
factorials of them 

If P is some prime then

inverse of some number a is a^(P-2) by Fermat's little
theorem

and then in O(1) just answer 
ncr = fact(n) * invFact(n-r) * invFact(r) 

2nd -> when N <= 4000 and mod = Not Prime

we can use the Pascals Triangle method

             1
            1 1
           1 2 1
          1 3 3 1
         1 4 6 4 1
        1 5 10 10 5 1
       1 6 15 20 15 6 1

Any term is the sum of above two terms in the Pascals
Triangle hence we can say

ncr[n][r] = ncr[n-1][r-1] + ncr[n-1][r]
or ****** nCr = n-1Cr-1 + n-1Cr

we can just precompute the Pascal's Triangle modulo any
number prime or Not Prime in O(N^2) time and then 
answer ncr


3rd -> Multiplication Method when N<=10^18 but
r <= 10^6 or (n-r) <= 10^6 mod = Prime

then since ncr = (n!)/(n-r!)*(r!)
we can just cancel bigger term from the denominator
let's say r <= 10^6

then ncr = prod i from 0 to r ((n-i)/(i+1)) mod Prime

Some Important Relations

1. summation i from 0 to n nCi = 2^n
comes from (1+x)^n = nC0 + nC1x + nC2x^2 .....
just put x = 1 both sides

2. summation i from 0 to n i*nCi = n * 2^(n-1)

3. Hockey Stick Formula
-> summation m from k to n mCk = (n+1)C(k+1)

4. Vandermonde's Identity
-> summation i from 0 to k nCi * mC(k-i) = (n+m)C(k) 
-> think about choosing k people from a group
of n men and m women

-> if top back is same and one of them is increasing
and the other one is decreasing then it might be a
vandermondes' identity.

special case

-> summation i from 0 to n (nCi)^2 = (2^n)C(n)

Interesting thing(used widely in CP): Bar and Stick Formula

given x1 + x2 + x3 + ...... xn = R

0<=xi<=R 

then # of sol = (n+R-1)C(n-1)
	

summation k from 0 to floor(n/2) (n-k)C(k) = Fib(n+1)

Lucas Theorem -> 

nCm mod P -> for N large P small Prime

then it is = (floor(n/p)C(floor(m/p))) * (n%p)C(m%p) mod P

do this recursively till small enough


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