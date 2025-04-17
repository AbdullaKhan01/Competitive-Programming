#include<bits/stdc++.h>
#define ceil(a,b) ((a + b - 1)/b)
#define int long long
#define fast_io() ios::sync_with_stdio(0);cin.tie(0);

using namespace std; 
/* 
for fast input output use printf and scanf;
*/

struct node
{
	int sum,lLazy,rLazy,diff;
	// bool isLazy;
	node(int a=0,int b=0,int c=0,int d=0)
	{
		sum = a;
		lLazy = b;
		rLazy = c;
		diff = 0;
	}
};
node merge(node &a,node &b)
{
	node temp;
	temp.sum = a.sum + b.sum;
	return temp;
}
const int N = 2e5 + 5;
int a[N];
node t[4 * N];

/*

VERDICT -> ACCEPTED

DID this by my own Proud of Myself

only 1 little bug was there in the nterm
*/

int sum_of_ap(int a,int d,int n)
{
	int sum = (n*(2*a + (n-1) * d))/2;
	return sum;
}
int fsum(int n)
{
	return (n * (n+1))/2;
}
void build(int idx,int l,int r)
{
	if(l == r)
	{
		t[idx] = node(a[l]);
		return ;
	}	
	int mid = (l + r)/2;
	build(2*idx,l,mid);
	build(2*idx+1,mid+1,r);
	t[idx] = merge(t[2*idx],t[2*idx+1]);
}
void push(int idx,int l,int r)
{
	if(t[idx].lLazy)
	{
		int start = t[idx].lLazy;
		int diff = t[idx].diff;
		int sz = r - l + 1;
		int mid = ceil(sz,2);
		int to_add = sum_of_ap(start,diff,sz);
		int nterm = start + mid * diff;
		t[idx].sum += to_add;
		if(l != r)
		{
			t[2*idx].lLazy += start;
			t[2*idx].diff += diff;
			t[2*idx+1].lLazy += nterm;
			t[2*idx+1].diff += diff;
		}
		t[idx].lLazy = 0;
		t[idx].diff = 0;
	}
}
void update(int idx,int l,int r,int lq,int rq,int &v)
{
	push(idx,l,r);
	if(lq > r || l > rq) return;
	if(lq <= l && r <= rq)
	{
		int sz = r - l;
		t[idx].lLazy += v;
		t[idx].diff += 1;
		v = v + sz + 1;
		push(idx,l,r);
		return;
	}
	int mid = (l + r)/2;
	update(2*idx,l,mid,lq,rq,v);
	update(2*idx+1,mid+1,r,lq,rq,v);
	t[idx] = merge(t[2*idx],t[2*idx+1]);
}
node query(int idx,int l,int r,int lq,int rq)
{
	push(idx,l,r);
	if(lq > r || l > rq) return node();
	if(lq <= l && r <= rq)
	{
		return t[idx];
	}
	int mid = (l + r)/2;
	node a = query(2*idx,l,mid,lq,rq);
	node b = query(2*idx+1,mid+1,r,lq,rq);
	return merge(a,b);
}
void solve()
{
	int n,q;
	cin >> n >> q;
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
	}
	build(1,0,n-1);
	while(q--)
	{
		int ch;cin >> ch;
		if(ch == 1)
		{
			// update
			int l,r;
			cin >> l >> r;
			l--,r--;
			int val = 1;
			update(1,0,n-1,l,r,val);
		}
		else
		{
			// query
			int l,r;
			cin >> l >> r;
			l--,r--;
			node ans = query(1,0,n-1,l,r);
			cout << ans.sum << endl;
		}
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