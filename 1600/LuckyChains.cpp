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
// C++ program to find prime factorization of a
// number n in O(Log n) time with precomputation
// allowed.

#define MAXN 10000001
vector<int> spf(MAXN + 1, 1);

// Calculating SPF (Smallest Prime Factor) for every
// number till MAXN.
// Time Complexity : O(nloglogn)
void sieve()
{
    // stores smallest prime factor for every number

    spf[0] = 1;
    for (int i = 2; i <= MAXN; i++) {
        if (spf[i] == 1) { // if the number is prime ,mark
                           // all its multiples who havent
                           // gotten their spf yet
            for (int j = i; j <= MAXN; j += i) {
                if (spf[j]== 1) // if its smallest prime factor is
                          // 1 means its spf hasnt been
                          // found yet so change it to i
                    spf[j] = i;
            }	
        }
    }
}

// A O(log n) function returning primefactorization
// by dividing by smallest prime factor at every step
vector<int> getFactorization(int x)
{
    vector<int> ret;
    while (x > 1) {
        ret.push_back(spf[x]);
        x = x / spf[x];
    }
    return ret;
}

void solve()
{
	int a,b;
	cin >> a >> b;
	if(a > b) swap(a,b);
	// cout << a << " " << b << endl;
	if(a == b)
	{
		if(b == 1)
			cout << 1 << endl;
		else cout << 0 << endl;
		return ;
	}
	if(__gcd(a,b) != 1)
	{
		cout << 0 << endl;
		return ;
	}
	if(a == b-1)
	{
		cout << -1 << endl;
		return ;
	}

	// find smallest k such that x + k is divisible by
	// prime factor of y-x
	// (x + y) % f(y-x) == 0
	// k = f(y-x) - x%f(y-x) 
	assert(b-a != 0);
	int k = 1e9;
	for(auto it : getFactorization(b-a))
	{
		k = min(k,it - (a % it));

	}

	cout << k << endl;
	
}
signed main(){
	fast_io();
	sieve();
    int tt = 1;
    cin >> tt;
    while(tt--)
    {
    	solve();
    }
    return 0;
}