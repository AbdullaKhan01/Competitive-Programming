#include<bits/stdc++.h>
#define int long long
#define fast_io() ios::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
using namespace std; 
/* 
	Last Contest -> Before Break
*/
void solve()
{
	int n,a,b;
	cin >> n >> a >> b;
	int x = 0 , y = 0;
	string s;cin >> s;
	int idx = 0;
	int cnt = 1000;
	while(cnt--)
	{
		if(x == a && y == b) break;
		if(s[idx] == 'N')
		{
			y+=1;
		}
		else if(s[idx] == 'S')
		{
			y-=1;
		}else if(s[idx] == 'E')
		{
			x+=1;
		}else if(s[idx] == 'W')
		{
			x-=1;
		}
		idx = (idx+1) % n;

	}
	if(x == a && y == b)
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
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