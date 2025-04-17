#include<bits/stdc++.h>
#define int long long
#define fast_io() ios::sync_with_stdio(0);cin.tie(0);
using namespace std; 

/* 
Given a Array 
We can do some preprocessing in O(NlogN) time 
and then we can give the answer of queries of 
type 

Find the min,max,gcd,and,or or a range [L,R] in O(1)

Sparse Table Works for Properties satisfying 
(some property find out ?? maybe Idempotent)

Yes Idempotent Property
i.e -> x . x = x

means lets say we want to calculate BITWISE AND OF
all elements from L to R and let x and y be 2 indices
between L and R such that x < y

eg L . . . x . . . . . y . . . . . . R

then AND of L to R = [AND of L to y] AND [AND of x to R]

so some numbers between L and R 
(precisely b/w idxs x and y (y - x + 1)) will be ANDDED two
times still they do not change the final Result then that
property is said to be an Idempotent Property


(something also known as Dense Table Exists)

How -> By using a precomputed Sparse Table

Advantage -> Fast Querying
Drawback -> only valid for static arrays 
			(values can not be modified)

Approach Precompute the answer for every power of 2 initially

*/
const int MAX_N = 200'005;
const int LOG = 25;
int a[MAX_N];
int m[MAX_N][LOG]; // m[i][j] is minimum among all a[i...i + 2^j-1]
int bin_log[MAX_N];
int query(int L,int R)
{
	int length = R - L + 1;
	// int k = 31 - __builtin_clz(length);
	int k = bin_log[length];
	return min(m[L][k],m[R - (1 << k) + 1][k]);
}
void precompute(int n)
{
	bin_log[1] = 0;
	for(int i=2;i<MAX_N;i++)
	{
		bin_log[i] = bin_log[i/2] + 1;
	}
	// precompute 
	for(int k=1;k<LOG;k++)
	{
		for(int i=0;i + (1 << k) - 1 < n;i++)
		{
			// change or and or gcd etc
			m[i][k] = min(m[i][k-1],m[i + (1<<(k-1))][k-1]);
		}
	}
}
void solve()
{
	int n,q;cin >> n >> q;
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
		// initial value
		m[i][0] = a[i];
	}			
	//precompute the values O(N*logN)
	precompute(n);
	// int q;cin >> q;
	while(q--)
	{
		int l,r;
		cin >> l >> r;
		l--,r--;
		cout << query(l,r) << endl;
	}
}
signed main(){
	fast_io();
    int tt = 1;
    // cin >> tt;
    while(tt--)
    {
    	solve();
    }
    return 0;
}