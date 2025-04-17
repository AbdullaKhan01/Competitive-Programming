#include<bits/stdc++.h>
// #define mod 1000000007
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
int f(int n)
{
    int mod = n % 4;

    // If n is a multiple of 4
    if (mod == 0)
        return 1LL*n;

    // If n % 4 gives remainder 1
    else if (mod == 1)
        return 1LL;

    // If n % 4 gives remainder 2
    else if (mod == 2)
        return 1LL*(n + 1);

    // If n % 4 gives remainder 3
    else if (mod == 3)
        return 0LL;
    return 0LL;
}
int finder(int n,int r,int i)
{
	if(r < n) return 0;
	// total number = (r - n)/2^i
	int nums = 1 + ((r - n)/(1LL<<i));

	// cout << (r - n)/(1<<i) << endl;
	int f = 4;
	// int g = 1;
	bool flag = true;
	int ans = 0LL;
	// cout << nums << endl;
	for(int bits=i;bits<60;bits++)
	{
		// int full = nums/f;
		if(flag)
		{ 	
			if((nums/2) % 2 != 0) ans ^= (1LL<<bits);
			flag = false;
			continue;
		}

		int half = nums%f;

		// cout << bits << " " << full << " " << half << endl;
		// f/2 0's and f/2 ones
		int abc = half-(f/2);
		if(abc > 0 && abc % 2 != 0)
		{
			ans ^= (1LL<<bits);
		}
		f*=2;
	}
	// cout << ans << endl;
	if(nums % 2 != 0)
	{
		ans ^= n;
	}
	// cout << ans << endl;
	return ans;
}
void solve()
{
	int l,r,i,k;
	cin >> l >> r >> i >> k;
	int ans = f(r) ^ f(l-1);
	int a = finder(k,r,i);
	int b = finder(k,l-1,i);
	// cout << a << " " << b << endl;
	int something = a^b;
	// just xor ans with all numbers b/w l to r
	// which on mod with 2^i gives remainder k
	// cout << (ans^2) << endl;
	cout << (ans ^ something) << endl;
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