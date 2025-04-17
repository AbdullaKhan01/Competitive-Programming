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
vi pref;
struct big_fan
{
	int one = 0;
	int zero = 0;

	void precompute(string s,vector<int>&a)
	{
		for(int i=0;i<s.size();i++)
		{
			if(s[i] == '0') zero ^= a[i];
			else one ^= a[i];
		}
	}
	void first(int l,int r)
	{
		int factor = pref[r] ^ pref[l-1];
		one ^= factor;
		zero ^= factor;
	}
	int second(int a)
	{
		if(a == 1) return one;
		return zero;
	}
};
signed main(){
	fast_io();
    ll tt;
    cin >> tt;
    while(tt--)
    {
        int n;
        cin >> n;
        vi arr(n);
        input(arr);
        pref.resize(n+1);
        pref[0] = 0;
        for(int i=1;i<=n;i++)
        {
        	pref[i] = pref[i-1] ^ arr[i-1];
        }
        string s;
        cin >> s;
        big_fan bf;
        bf.precompute(s,arr);
        int q;
        cin >> q;
        while(q--)
        {
        	int a;
        	cin >> a;
        	if(a == 1)
        	{
        		int l,r;
        		cin >> l >> r;
        		bf.first(l,r);
        	}
        	else
        	{
        		int d;
        		cin >> d;
        		cout << bf.second(d) << " ";
        	}
        }
        cout << endl;
    }
    return 0;
}