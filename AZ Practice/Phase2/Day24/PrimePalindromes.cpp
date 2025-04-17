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
bool isPrime(int x)
{
	for(int i=2;i*i<=x;i++)
	{
		if(x % i == 0) return false;
	}
	return true;
}
vector<int> pal = {1,2};
void init()
{
	// sieve();
	int a,b;
	cin >> a >> b;
	for(int i=3;i<=9999;i++)
	{
		
		string s = to_string(i);
		if(i % 2 == 0 || (s[0]-'0')%2 == 0) continue;
		string temp = s;
		reverse(temp.begin(),temp.end());
		if(s == temp && isPrime(stoll(s)))
		{
			// if(s == "303") cout << "Haa";
			pal.push_back(stoll(s));
		}
		if(s.size() * 2 < 10)
		{
			int x = stoll(s + temp);
			if(isPrime(x)) pal.push_back(x);
		}
		if(s.size() * 2 + 1 >= 5 && s.size() * 2 + 1 < 10)
		{
			for(char ch = '0';ch<='9';ch++)
			{
				s.push_back(ch);
				int p = stoll(s + temp);
				if(isPrime(p)); pal.push_back(p);
				s.pop_back();
			}
		}

	}
	// pal.push_back(1e9 + 9);
	sort(all(pal));
	vector<int> temp;
	for(auto it:pal)
	{
		if(isPrime(it)) temp.push_back(it);
	}
	output(temp);
	cout << endl;
	int cnt = 0;
	for(int i=0;i<(int)temp.size();i++)
	{
		int e = temp[i];
		if(e >= a && e <= b) cnt++;
	}
	cout << cnt << endl;

	// auto it = upper_bound(all(pal),b);
	// auto bt = lower_bound(all(pal),a);
	// cout << it - bt << endl;
}
void solve()
{
	init();
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