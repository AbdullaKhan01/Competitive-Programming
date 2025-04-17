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
Approach -> Took hint from the Editorial

Can you generalize the pattern? We put n−2
cells on the main diagonal. Then put two cells at (n−1,n)
and (n,n)
.

But why does it work? Interesting fact, that in such way
we generate all possible Manhattan distances. 
Odd distances are generated between cells from the main
diagonal and (n−1,n)
Even distances are generated between cells from the main
diagonal and (n,n)

*/
void solve()
{
	int n;
	cin >> n;
	for(int i=1;i<=n-2;i++)
	{
		cout << i << " " << i << endl;
	}
	cout << n-1 << " " << n << endl;
	cout << n << " " << n << endl;
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