#include<bits/stdc++.h>
using namespace std; 
/* 
for fast input output use printf and scanf;
*/
class segtree
{
	int n;
	vector<int> a;
	vector<int> seg;
	public:	
	segtree(int k)
	{
		n = k;
		a.resize(n+1);
		seg.resize(4*n+1);
	}
	void takeInput()
	{
		// fill this function according to your needs
		for(int i=0;i<n;i++)
		{
			cin >> a[i];
		}
	}
	void build(int ind,int low,int high)
	{
		if(low == high)
		{
			seg[ind] = a[low];
			return ;
		}
		int mid = (low + high)/2;
		build(2*ind+1,low,mid);
		build(2*ind+2,mid+1,high);
		seg[ind] = min(seg[2*ind+1],seg[2*ind+2]);
		/*change function if required*/

	}
	int query(int ind,int low,int high,int l,int r)
	{
		// no overlap
		// l r low high or low high l r
		if(r < low || l > high)
		{
			return INT_MAX;
			/*change return type if function changed*/	
		}

		// complete overlap
		// l low high r
		if(low >= l && high <= r)
		{
			return seg[ind];
		} 

		// partial overlap just query both sides and return value
		int mid = (low + high) >> 1;
		int left = query(2*ind+1,low,mid,l,r);
		int right = query(2*ind+2,mid+1,high,l,r);
		return min(left,right);/*change if fn changed*/
	}
	void update(int ind,int low,int high,int i,int val)
	{
		if(low == high)
		{
			seg[ind] = val;
			a[low] = val;
			return ;
		}
		int mid = (low + high) >> 1;
		if(i <= mid) update(2*ind+1,low,mid,i,val);
		else update(2*ind+2,mid+1,high,i,val);
		seg[ind] = min(seg[2*ind+1],seg[2*ind+2]);
	}
};
void solve()
{
	int n;
	cin >> n;
	segtree s1(n);
	s1.takeInput();
	s1.build(0,0,n-1);
	int l,r;
	cin >> l >> r;
	cout << s1.query(0,0,n-1,l,r) << endl;
}
signed main(){
	solve();
    return 0;
}

