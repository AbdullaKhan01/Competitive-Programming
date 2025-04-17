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
void solve()
{
	int n,m;
	cin >> n >> m;
	vector<pair<int,int>> p,t;
	vector<int> a(n+m+1),b(n+m+1);
	vector<int> w(n+m+1);
	input(a);
	input(b);
	for(int i=0;i<a.size();i++)
	{
		int s1 = a[i];
		int s2 = b[i];
		if(a[i] > b[i])
		{
			//programmer
			if(p.size() <= n)
			{
				p.push_back({s1,s2});
				w[i] = 1;	
			} 
			else
			{
				t.push_back({s2,s1});
				w[i] = 0;
			} 
			
		}
		else
		{
			//tester
			if(t.size() <= m)
			{
				w[i] = 0;
				t.push_back({s2,s1});	
			} 
			else
			{
				w[i] = 1;
				p.push_back({s1,s2});	
			} 
		}
	}
	int sum = 0;
	for(auto it:p) sum += it.first;
	for(auto it:t) sum += it.first;

	// cout << sum << endl;
	for(int i=0;i<a.size();i++)
	{
		//ith person is absent

		//was he a programmer or tester ? 
		int k = sum;
		if(w[i] == 1)
		{
			k -= a[i];
			if(t.size() > m)
			{
				k -= t.back().first;
				k += t.back().second;
			}
		}
		else
		{
			k -= b[i];
			if(p.size() > n)
			{
				k -= p.back().first;
				k += p.back().second;
			}
		}
		cout << k << " ";
	}
	cout << endl;
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



// 
// 2 2 3 6 4 2
// 6 3 3 6 6 6 