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
signed main(){
	fast_io();
    ll tt;
    cin >> tt;
    while(tt--)
    {
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        // a < c && b < d
        // Conditions : 
        // 1. a < x <= c && b < y <= d
        // 2. x*y is divisible by a*b
        // 2. 2nd condition means 
        // x*y % a*b == 0
        // or 

        // I guess only 3 conditions can be 
        // satisfied
        // Cdn1 . find multiple of a in (a,c]
        // && find multiple of b in (b,d]

        // Cdn2 . find multiple of a*b in (a,c]
        
        // Cdn3 . find multiple of a*b in (b,d]
        
        int x = -1 , y = -1;
        // Cdn 1


        // z = 6 * something = x * 9
        // the number z will come 
        // in both the table of 6 and 9
        // so the number will come in the
        // table of LCM of 6 and 9
        // number will come in table of 18
        // first number 
        for(int i=a+1;i<=c;i++)
        {
        	// check if i can be a possible 
        	// number from pair (a,c]

        	int n = lcm(i,a*b);
        	int g = i*b/n;
        	if((g+1) * n <= i*d)
        	{
        		x = i;
        		y = ((g+1)*n)/i;
        	}

        }

        // Cdn 2
        for(int i=a+1;i<=c;i++)
        {
        	if(i%(a*b) == 0)
        	{
        		x = i;
        		y = d;
        	}
        }

        // Cdn 3
        for(int i=b+1;i<=d;i++)
        {
        	if(i%(a*b) == 0)
        	{
        		x = c;
        		y = i;
        	}
        }

        cout << x << " " << y << endl;
    }
    return 0;
}
