#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std; 
/* 
for fast input output use printf and scanf;
*/
const int inf = 1e18;
const int N = 2e5 + 5;


struct node
{
	int maxi,sum,lsum,rsum;
	node(int a=0,int b=0,int c=0,int d=0)
	{
		sum = a;
		maxi = b;
		lsum = c;
		rsum = d;
	}
};

int n,q;
int a[N];
node t[4*N];

node operator+(const node A,const node B)
{
	node temp;
	temp.lsum = max(A.lsum,A.sum + B.lsum);
	temp.rsum = max(B.rsum,A.rsum + B.sum);
	temp.sum = A.sum + B.sum;
	temp.maxi = max({A.maxi,B.maxi,A.rsum+B.lsum});
	return temp;
}
void update(int idx,int l,int r,int pos,int val)
{
	if(pos < l || pos > r)
	{
		return ;
	}
	if(l == r)
	{
		// a[pos] = val;		
		int x = max(0LL,val);
		t[idx] = node(val,x,x,x);
		return ;
	}
	int mid = (l+r)/2;
	update(2*idx,l,mid,pos,val);
	update(2*idx+1,mid+1,r,pos,val);
	t[idx] = t[2*idx] + t[2*idx+1];

}
void solve()
{
	cin >> n >> q;
	for(int i=0;i<n;i++)
	{
		int v;
		cin >> v;
		update(1,0,n-1,i,v);
	}
	while(q--)
	{
		int ch,val;
		cin >> ch >> val;
		ch--;
		update(1,0,n-1,ch,val);
		cout << t[1].maxi << endl;
	}
}
signed main(){
    int tt = 1;
    // cin >> tt;
    while(tt--)
    {
    	solve();
    }
    return 0;
}