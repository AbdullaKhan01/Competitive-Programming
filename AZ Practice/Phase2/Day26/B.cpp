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
bool onBorder(int r,int c,int n,int m)
{
	if(r == 0 || c == 0 || r == n-1 || c == m-1) return true;
	// cout << r << " " << c << "No" << endl;
	return false;
}
void solve()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	int l = sqrt(n);
	if(l * l != n)
	{
		cout << "No" << endl;
		return ;
	}
	int r = l;
	int cr = 0;
	bool flag = true;
	for(int i=0;i<n;i++)
	{
		if(i != 0 && i % r == 0) cr++;
		int cc = i % r;

		// cout << cr << " " << cc << endl;
		if(s[i] == '1')
		{
			if(!onBorder(cr,cc,r,r)){
				flag = false;
				break;	
			}  
		}
		else
		{
			if(onBorder(cr,cc,r,r))
			{
				 flag = false;
				 break;
			}
		}
	}
	if(flag)
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}
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