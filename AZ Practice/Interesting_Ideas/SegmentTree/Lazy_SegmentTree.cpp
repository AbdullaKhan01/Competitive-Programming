#include<bits/stdc++.h>
#define int long long
#define fast_io() ios::sync_with_stdio(0);cin.tie(0);

using namespace std; 
/* 
for fast input output use printf and scanf;
*/

struct node
{
	int sum,maxr,lazy;
	// bool isLazy;
	node()
	{
		sum = 0;
		maxr = 0;
		lazy = 0;
	}
};
node merge(node &a,node &b)
{
	node temp;
	temp.sum = a.sum + b.sum;
	temp.maxr = max(a.maxr,b.maxr);
	return temp;
}
const int N = 1e5;
node t[4 * N];
// void build(int id,int l,int r)
// {

// }
void push(int idx,int l,int r)
{
	if(t[idx].lazy)
	{
		t[idx].sum = t[idx].lazy * (r - l + 1);
		t[idx].maxr = t[idx].lazy;
		if(l != r)
		{
			t[2*idx].lazy = t[idx].lazy;
			t[2*idx+1].lazy = t[idx].lazy;
		}
		t[idx].lazy = 0;
	}
}
void update(int idx,int l,int r,int lq,int rq,int v)
{
	push(idx,l,r);
	if(lq > r || l > rq) return;
	if(lq <= l && r <= rq)
	{
		t[idx].lazy = v;
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
	// update(1,0,9,0,5,3);
	// update(1,0,9,6,9,4);
	// // cout << "update done " << endl;
	// node ans = query(1,0,9,3,6);
	// cout << ans.sum << endl;
	// cout << ans.maxr << endl;
	int n,q;
	cin >> n >> q;
	while(q--)
	{
		int l,r,ch;
		cin >> l >> r >> ch;
		l--,r--;
		update(1,0,n-1,l,r,ch);
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