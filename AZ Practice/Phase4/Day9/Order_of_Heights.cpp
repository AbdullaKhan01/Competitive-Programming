#include<bits/stdc++.h>
#define int long long
#define fast_io() ios::sync_with_stdio(0);cin.tie(0);

using namespace std; 
/* 
for fast input output use printf and scanf;
*/
/*
Q). Design A Data Structure that Supports 3 types
of Operations

+ x -> add element x to the data structure
- x -> remove element x from the data structure
? k -> find kth smallest element in the data Structure

N <= 10^5
Queries <= 10^5
x <= 10^5

The Idea is to build a Segment Tree which will 
store 

t[idx](l,r) = no of elements in the data Structure
which are b/w l & r

By this we can easily add remove and query

*/
struct node
{
	// int val;
	// node()
	// {
	// 	val = 0;
	// }
};
const int N = 1e5;
int t[4 * N];

int findKth(int idx,int l,int r,int k)
{
	if(l == r) return l;
	int mid = (l + r)/2;
	if(k <= t[2*idx]) return findKth(2*idx,l,mid,k);
	else return findKth(2*idx+1,mid+1,r,k - t[2*idx]);
}
void add_or_remove(int idx,int l,int r,int v,int type)
{
	if(v < l || v > r) return;
	if(l == r)
	{
		if(type == 1) t[idx] = 1;
		else t[idx] = 0;
		return;
	}
	int mid = (l + r)/2;
	add_or_remove(2*idx,l,mid,v,type);
	add_or_remove(2*idx+1,mid+1,r,v,type);
	t[idx] = t[2*idx] + t[2*idx+1];
}
void solve()
{
	int n;cin >> n;
	for(int i=0;i<n;i++)
	{
		int x;cin >>x;
		// add_or_remove(1,0,)
	}
	vector<int> t(n);
	for(int i=0;i<n;i++)
	{
		cin >> t[i];
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