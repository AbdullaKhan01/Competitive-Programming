#include<bits/stdc++.h>
#define int long long
#define fast_io() ios::sync_with_stdio(0);cin.tie(0);

using namespace std; 
/* 
for fast input output use printf and scanf;
*/

struct node
{
	int sum,setLazy,addLazy;
	// bool isLazy;
	node()
	{
		sum = 0;
		setLazy = 0;
		addLazy = 0;
	}
};
node merge(node &a,node &b)
{
	node temp;
	temp.sum = a.sum + b.sum;
	return temp;
}
const int N = 2e5;
node t[4 * N];
// void build(int id,int l,int r)
// {

// }
void push(int idx,int l,int r)
{
	if(t[idx].setLazy)
	{
		t[idx].sum = t[idx].setLazy * (r - l + 1);
		if(l != r)
		{
			t[2*idx].setLazy = t[idx].setLazy;
			t[2*idx].addLazy = 0;


			t[2*idx+1].setLazy = t[idx].setLazy;
			t[2*idx+1].addLazy = 0;
		}
		t[idx].setLazy = 0;
	}
	if(t[idx].addLazy)
	{
		t[idx].sum += t[idx].addLazy * (r - l + 1);
		if(l != r)	
		{
			t[2*idx].addLazy += t[idx].addLazy;
			t[2*idx+1].addLazy += t[idx].addLazy;
		} 
		t[idx].addLazy = 0;
	}
}
void update(int idx,int l,int r,int lq,int rq,int v,int type)
{
	push(idx,l,r);
	if(lq > r || l > rq) return;
	if(lq <= l && r <= rq)
	{
		if(type == 2)
		{
			t[idx].setLazy = v;
		}
		else
		{
			t[idx].addLazy += v;
		}
		push(idx,l,r);
		return;
	}
	int mid = (l + r)/2;
	update(2*idx,l,mid,lq,rq,v,type);
	update(2*idx+1,mid+1,r,lq,rq,v,type);
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
void print()
{
	for(int i=1;i<=13;i++)
	{
		cout << i << " -> " << t[i].sum << endl;
	}
}
void solve()
{
	int n,q;
	cin >> n >> q;
	vector<int> ap(n+1);
	for(int i=0;i<n;i++)
	{
		int x;cin >> x;
		update(1,0,n-1,i,i,x,2);
	}
	while(q--)
	{
		int ch;
		cin >> ch;
		if(ch == 3)
		{
			int a,b;
			cin >> a >> b;
			a--,b--;
			node ans = query(1,0,n-1,a,b);
			cout << ans.sum << endl;
		}
		else
		{
			int a,b,x;
			cin >> a >> b >> x;
			a--,b--;
			update(1,0,n-1,a,b,x,ch);
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