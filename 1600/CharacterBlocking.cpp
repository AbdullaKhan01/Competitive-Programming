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
/*

IDEA is simple just keep track of which indexes
are the faulty ones which cause the strings to not match

we can keep a set for that 

and rest is just trivial
*/
int t,q,n;
vector<string> st(2);
struct doable
{
	set<int> p;
	map<int,int> timer;
	void precompute()
	{
		for(int i=0;i<n;i++)
		{
			if(st[0][i] != st[1][i])
			{
				p.insert(i);
			}
		}
	}
	void start()
	{
		for(int i=1;i<=q;i++)
		{
			if(timer.find(i) != timer.end()) p.insert(timer[i]);
			int x;
			cin >> x;
			if(x == 1)
			{
				int idx;
				cin >> idx;
				idx--;
				if(st[0][idx] == st[1][idx]) continue;
				else
				{
					// they would be present in the set p
					p.erase(idx);
					timer.insert({i+t,idx});
				}
			}
			else if(x == 2)
			{
				// swapping
				int s1,k1,s2,k2;
				cin >> s1 >> k1 >> s2 >> k2;
				s1--,k1--,s2--,k2--;
				swap(st[s1][k1],st[s2][k2]);
				if(st[0][k1] == st[1][k1])
				{
					p.erase(k1);
				}
				else
				{
					p.insert(k1);
				}
				if(st[0][k2] == st[1][k2])
				{
					p.erase(k2);
				}
				else
				{
					p.insert(k2);
				}
			}
			else
			{
				// x=3
				cout << (p.size()?"NO":"YES") << endl;
			}
		}
	}

};
void solve()
{
	cin >> st[0] >> st[1];	
	cin >> t >> q;
	n = st[0].size();
	doable dd;
	dd.precompute();
	dd.start();
}
signed main(){
	fast_io();
    int tt = 1;
    cin >> tt;
    while(tt--)
    {
    	solve();
    }
    return 0;
}

// a + b + c == n
// 

// if a = n-x b+c = x

// 10 ^ 6 -> 
// 1000000
// 1 99999