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
const int inf = 1e9;
struct node
{
	int a,b;
	node(int x=0,int y=0)
	{
		a = x;
		b = y;
	}
};
node merge(node a,node b)
{
	node temp;
	vector<int> g = {a.a,a.b,b.a,b.b};
	sort(g.rbegin(),g.rend());
	temp.a = g[0];
	temp.b = g[1];
	return temp;
}
const int N = 100100;
node t[4 * N];
void build(int idx,int l,int r,int val)
{
	if(l == r)
	{
		t[idx] = node(val,val);
		return ;
	}
	int mid = (l + r)/2;
	build(2*idx,l,mid,val);
	build(2*idx+1,mid+1,r,val);
	t[idx] = merge(t[2*idx],t[2*idx+1]);
}
void update(int idx,int l,int r,int pos,int val)
{
	if(pos < l || pos > r) return ;
	if(l == r)
	{
		t[idx] = node(val);
		return ;
	}

	int mid = (l + r)/2;
	update(2*idx,l,mid,pos,val);
	update(2*idx+1,mid+1,r,pos,val);
	t[idx] = merge(t[2*idx],t[2*idx+1]);
}
node query(int idx,int l,int r,int lq,int rq)
{
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
	int n;cin>>n;
	for(int i=0;i<n;i++)
	{
		int v;cin >> v;
		update(1,0,n-1,i,v);
	}
	int q;cin>>q;
	while(q--)
	{
		char ch;cin >> ch;
		if(ch == 'U')
		{
			int pos,val;
			cin >> pos >> val;
			pos--;
			update(1,0,n-1,pos,val);
		}
		else
		{
			int l,r;
			cin >> l >> r;
			l--,r--;
			node ans = query(1,0,n-1,l,r);
			cout << ans.a + ans.b << endl;
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