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
const int N = 2e5 + 5;
// struct node
// {
// 	int cnt;
// };
// node merge(node &a,node &b)
// {
// 	node temp;
// 	temp.cnt = a.cnt + b.cnt;
// 	return temp;
// }
int n,q;
int a[N];
int t[4 * N];

void build(int idx,int l,int r)
{
	if(l == r)
	{
		t[idx] = (a[l] % 2 == 0);
		return ;
	}
	int mid = (l+r)/2;
	build(2*idx,l,mid);
	build(2*idx+1,mid+1,r);
	t[idx] = t[2*idx]+t[2*idx+1];
}
void update(int idx,int l,int r,int pos,int val)
{
	if(pos < l || pos > r)
	{
		return ;
	}
	if(l == r)
	{
		t[idx] = (val % 2 == 0);
		return ;
	}
	int mid = (l+r)/2;
	update(2*idx,l,mid,pos,val);
	update(2*idx+1,mid+1,r,pos,val);
	t[idx] = t[2*idx]+t[2*idx+1];
}
int query(int idx,int l,int r,int lq,int rq)
{
	if(l > rq || lq > r)
	{
		return 0;
	}
	if(lq <= l && r <= rq)
	{
		return t[idx];
	}
	int mid = (l+r)/2;
	return query(2*idx,l,mid,lq,rq) + query(2*idx+1,mid+1,r,lq,rq);
}
void solve()
{
	cin >> n;
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
	}
	//just build the segtree
	build(1,0,n-1);
	cin >> q;
	while(q--)
	{
		int x;cin >> x;
		if(x == 0)
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
			int ans = query(1,0,n-1,l,r);
			if(x == 1)
			{
				cout << ans << endl;
			}
			else
			{
				cout << (r - l + 1) - ans << endl;
			}
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