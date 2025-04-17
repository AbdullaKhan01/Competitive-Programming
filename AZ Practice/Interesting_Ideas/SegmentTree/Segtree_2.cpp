#include<bits/stdc++.h>
#define int long long
using namespace std; 
/* 
for fast input output use printf and scanf;
*/
int n;
int a[200200];
int t[800800];

void build(int idx,int l,int r)
{
	if(l == r)
	{
		t[idx] = a[l];
		return ;
	}
	int mid = (l+r)/2;
	build(2*idx,l,mid);
	build(2*idx+1,mid+1,r);
	t[idx] = t[2*idx] + t[2*idx+1];
}
void update(int idx,int l,int r,int pos,int val)
{
	if(pos < l || pos > r) return ;
	if(l == r)
	{
		a[l] = val;
		t[idx] = val;
		return ;
	}
	int mid = (l+r)/2;
	update(2*idx,l,mid,pos,val);
	update(2*idx+1,mid+1,r,pos,val);
	t[idx] = t[2*idx] + t[2*idx+1];	
}
int query(int idx,int l,int r,int lq,int rq)
{
	if(l > rq || lq > r)
	{
		return 0;
	}
	if(lq <=l && r <= rq)
	{
		// lq <= l <= r <= rq
		return t[idx];
	}
	int mid = (l+r)/2;
	return query(2*idx,l,mid,lq,rq) + query(2*idx+1,mid+1,r,lq,rq);
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
			cout << query(1,0,n-1,l,r) << endl;
		}
	}
}
signed main(){
	solve();	
    return 0;
}