#include<bits/stdc++.h>
#define int long long
using namespace std; 
/* 
for fast input output use printf and scanf;
*/
int n;
int a[200200];
pair<int,int> t[800800];


/*

Given an array support 2 types of Queries

1. update value at pos to val
2. return the index of the element which is
   min(l,r)
   if multiple mins return smallest index


*/



void build(int idx,int l,int r)
{
	if(l == r)
	{
		t[idx] = {a[l],l};
		return ;
	}
	int mid = (l+r)/2;
	build(2*idx,l,mid);
	build(2*idx+1,mid+1,r);
	t[idx] = min(t[2*idx],t[2*idx+1]);
}
void update(int idx,int l,int r,int pos,int val)
{
	if(pos < l || pos > r) return ;
	if(l == r)
	{
		a[l] = val;
		t[idx] = {val,l};
		return ;
	}
	int mid = (l+r)/2;
	update(2*idx,l,mid,pos,val);
	update(2*idx+1,mid+1,r,pos,val);
	t[idx] = min(t[2*idx],t[2*idx+1]);	
}
pair<int,int> query(int idx,int l,int r,int lq,int rq)
{
	if(l > rq || lq > r)
	{
		return {1e9,-1};
	}
	if(lq <=l && r <= rq)
	{
		// lq <= l <= r <= rq
		return t[idx];
	}
	int mid = (l+r)/2;
	return min(query(2*idx,l,mid,lq,rq),query(2*idx+1,mid+1,r,lq,rq));
}

void solve()	
{
	int q;
	cin >> n >> q;
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
	}	
	build(1,0,n-1);
	for(int i=0;i<q;i++)
	{
		int ch;cin >> ch;
		if(ch == 1)
		{
			//update
			int x,v;
			cin >> x >> v;
			x--;
			update(1,0,n-1,x,v);
		}else{
			int l,r;
			cin >> l >> r;
			l--,r--;
			cout << query(1,0,n-1,l,r).second + 1 << endl;
		}
	}
}
signed main(){
	solve();	
    return 0;
}