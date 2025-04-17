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
long long lcm (long long a, long long b) {
    return a / __gcd(a, b) * b;
}
/*

APPROACH -> Bigger number has to get nuetralized
by smaller number hence we have to look into something
of that sort 

for every x +'s we need y -'s 

lets say we subtract x*k +'s from p and y*k -'s from
m then they should be same so that 


*/
signed main(){
	fast_io();
    int n;
    cin >> n;
    string s;
    cin >> s;
    int p = 0 , m = 0;
    for(auto it:s) p+=(it=='+'),m+=(it=='-');
    int q;
	cin >> q;
	while(q--)
	{
		int x,y;
		cin >> x >> y;
		if(p == m)
		{
			cout << yes << endl;
			continue;
		}
		int k = lcm(x,y);
		int a = k/x , b = k/y;
		if(b < a) swap(a,b);
		if(b == a)
		{
			cout << no << endl;
			continue;
		}
		if(p >= a && m >= b && (m-p)>=0 &&(m-p)%(b-a) == 0)
		{
			int k = (m-p) / (b-a);
            if(m-k*b >= 0)
            {
                cout << yes << endl;
            }
            else cout << no << endl;
		}
		else if(p >= b && m >= a && (p-m)>=0 && (p-m)%(b-a) == 0)
		{
			int k = (p-m) / (b-a);
            if(p-k*b >= 0)
            {
                cout << yes << endl;
            }
            else cout << no << endl;
		}
		else cout << no << endl;
	}
    return 0;
}
