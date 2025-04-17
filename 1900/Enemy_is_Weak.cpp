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
int n;
vector<int> a;
class segtree
{
	public:
	vector<int> tree;		
	segtree(int n){
		tree.assign(4*n,0);
	}
	void update(int idx,int l,int r,int pos,int val)
	{
		if(pos < l || pos > r) return;
		if(l == r)
		{
			tree[idx] = val;
			return ;
		}
		int mid = (l + r)/2;
		update(2*idx,l,mid,pos,val);
		update(2*idx+1,mid+1,r,pos,val);
		tree[idx] = tree[2*idx] + tree[2*idx+1];
	}
	int query(int idx,int l,int r,int lq,int rq)
	{
		if(l > rq || lq > r) return 0;
		if(lq <= l && r <= rq)
		{
			return tree[idx];
		}
		int mid = (l + r)/2;
		int a = query(2*idx,l,mid,lq,rq);
		int b = query(2*idx+1,mid+1,r,lq,rq);
		return a + b;
	}
};
void solve()
{
	cin >> n;
	a.resize(n);
	vector<int> b(n);
	map<int,int> mp;
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
		b[i] = a[i];
	}
	sort(rall(b));
	for(int i=0;i<n;i++)
	{
		mp[b[i]] = i;
	}
	segtree st1(n),st2(n);
	int cnt = 0;
	for(int i=0;i<n;i++)
	{
		int idx = mp[a[i]];
		int ans = st1.query(1,0,n-1,0,idx);
		st1.update(1,0,n-1,idx,1);
		st2.update(1,0,n-1,idx,ans);
		int ab = st2.query(1,0,n-1,0,idx);
		int bc = st2.query(1,0,n-1,idx,idx);
		// cout << i << " " << idx << " " << a[i] << " " << ab << " " << bc << endl;
		cnt += (ab - bc);
	}
	cout << cnt << endl;
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