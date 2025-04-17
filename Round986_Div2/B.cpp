#include<bits/stdc++.h>
#define int long long
#define ceil(a,b) ((a+b-1)/b)
#define fast_io() ios::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
using namespace std; 
/* 
	Last Contest -> Before Break
*/
void solve()
{
	int n,b,c;
	cin >> n >> b >> c;

	if(b == 0)
	{
		if(n > 2+c)
		{
			cout << -1 << endl;
		}
		else if(n == 2+c)
		{
			cout << n - 1 << endl;
		}
		else cout << min(n,c) << endl;

		return ;
	}
	// if b = 0 then handle cases 
	// otherwise just find out 0 se n-1 me kitne elements
	// initially nhi hai utne hi moves lagenge
	else
	{
		int tot = n;
		if(c <= n-1)
		{
			int g = ceil(n - c,b);
			tot -= g; 
		}
		cout << tot << endl;
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