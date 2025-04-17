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
// equation x^2 - bx + c = 0

// solutions = b (+-sqrt(b^2-4ac))/2a

// == 
map<int,int> mp;
int get(int D)
{
	int g = sqrt(D);
	return g;
}
int solve()
{
	int b,c;
	cin >> b >> c;
	int D = (b*b - 4*c);
	if(D < 0) return 0;
	int x1 = (b - get(D))/2;
	int x2 = (b + get(D))/2;
	if(x1 + x2 != b || x1*x2 != c) return 0;
	if(D == 0)
	{
		int freq = mp[x1];
		return freq * (freq - 1)/2;
	}
	else return mp[x1] * mp[x2];

}
signed main(){
	fast_io();
    ll tt;
    cin >> tt;
    while(tt--)
    {
    	mp.clear();
    	int n;
    	cin >> n;
    	for(int i=0;i<n;i++)
    	{
    		int x;
    		cin >> x;
    		mp[x]++;
    	}
    	int q;
    	cin >> q;
    	while(q--)
    	{
    		cout << solve() << " ";	
    	}
    	cout << endl;
    }
    return 0;
}