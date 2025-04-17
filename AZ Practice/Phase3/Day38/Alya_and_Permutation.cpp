#include<bits/stdc++.h>
#include<bitset>
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
bool isPowerOfTwo(int n) {
    return n && !(n & (n - 1));
}
int complement(int n)
{
	int i = 0;
	int ans = 0;
	while(n != 0)
	{
		int bit = n%2;
		n/=2;
		if(bit == 0) ans |= (1LL<<i);
		i++;
	}
	return ans;
}
void solve()
{
	int n;
	cin >> n;
	set<int> st;
	for(int i=1;i<=n;i++) st.insert(i);
	// cout << bit_width(n) << endl;
	vector<int> p(n);
	int k = 0;
	if(n % 2 != 0)
	{
		// odd 
		bool flag = true;
		for(auto it:st)
		{
			if(flag) k |= it;
			else k &=it;
			flag = !flag;
		}
		cout << k << endl;
		for(auto it:st)
		{
			cout << it << " ";
		}
		cout << endl;
 	}
 	else
 	{
 		if(isPowerOfTwo(n))
 		{
 			st.erase(n-1);
 			for(auto it : st)
 			{
 				cout << it << " ";
 			}
 			cout << n-1 << endl;
 		}
 		else
 		{
 			int a = n;
 			int b = complement(n);
 			int c = b;
 			for(int i=0;i<30;i++)
 			{
 				c |= (1<<i);
 				if(c != b) break;
 			}
 			st.erase(a);
 			st.erase(b);
 			st.erase(c);
 			for(auto it:st)
 			{
 				cout << it << " ";
 			}
 			cout << c << " " << b << " " << a << endl;

 		}
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