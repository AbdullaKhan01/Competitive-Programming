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
//VERDICT -> ACCEPTED
int n,q;
struct node
{
	int left,right,full;
	node(int l=0,int r=0,int f=0)
	{
		left = l;
		right = r;
		full = f;
	}
};
node merge(node &a,node &b)
{
	node temp;
	temp.full = a.full + b.full + min(a.left,b.right);
	temp.left = a.left + b.left - min(a.left,b.right);
	temp.right = a.right + b.right - min(a.left,b.right); 
	return temp;
}
string s;
const int N = 1e6 + 6;
node t[4*N];
void build(int idx,int l,int r)
{
	if(l == r)
	{
		t[idx] = node(s[l] == '(',s[l] == ')');
		return;
	}
	int mid = (l + r)/2;
	build(2*idx,l,mid);
	build(2*idx+1,mid+1,r);
	t[idx] = merge(t[2*idx],t[2*idx+1]);
}
node query(int idx,int l,int r,int lq,int rq)
{
	if(lq > r || l > rq)
	{
		return node();
	}
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
	// how many proper bracket sequences from l to r
	cin >> s;
	n = s.size();
	build(1,0,n-1);
	cin >> q;
	while(q--)
	{
		int l,r;
		cin >> l >> r;
		l--,r--;
		cout << 2*query(1,0,n-1,l,r).full << endl;
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