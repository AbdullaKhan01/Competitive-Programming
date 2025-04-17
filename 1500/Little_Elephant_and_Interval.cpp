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
int f[18];

int solve(int n)
{
	int x = 1;
	string s = to_string(n);
	int idx = 0;
	int ans = 0;
	while(x < s.size())
	{
		ans += f[idx++];
		x++;
	}
	cout << ans << endl;
	int g = s[0] - 48;
	ans += (g-1) * f[idx];

	int extra = 1;
	bool flag = false;

	int cnt = 1;
	for(int i=1;i<s.size()-1;i++)
	{
		int num = s[i] - 48;
		// cnt*= num;
		if(flag)
		{
			cnt *= num;
			extra *= 10;
		}
		else
		{
			if(num != 0) extra *= num;
			if(num != 0) flag = true;	
		}

	}
	// cout << ans << endl;
	// cout << extra << " " << cnt << endl;
	int c = 0;
	if(s[s.size()-1] >= s[0]) c++;
	if(flag == false)
	{
		return ans+c;
	}
	if(s[s.size()-1] >= s[0])
		return ans+extra+cnt;
	else return ans+extra+(cnt-1);
	// 7 8 8 3 3 3 8 9 
	// 7 0 0 0 0 0 8 9

}

// 1 9 -> 9
// 11 99 -> 10

// 111 - 999 -> 100

// 1001 -> 1011 - 1021 


signed main(){
	fast_io();
   	f[0] = f[1] = 9;
   	int a = 10;
   	for(int i=2;i<18;i++)
   	{
   		f[i] = a;
   		a*=10;
   	}
   	cout << solve(101) << endl;
    return 0;
}