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
	int n,q;
	cin >> n >> q;
	segtree st(n);
	st.takeInput();
	st.build(0,0,n-1);
	while(q--)
	{
		int l,r;
		cin >> l >> r;
		l--,r--;
		cout << st.query(0,0,n-1,l,r) << endl;
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