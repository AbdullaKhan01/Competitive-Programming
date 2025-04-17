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
using namespace std; 
/* 
for fast input output use printf and scanf;
*/
signed main(){
	fast_io();
	int n;
	cin >> n;
	auto find = [&](int x,int y)
	{
		cout << "? " << x+1 << " " << y+1 << endl;
		int a;
		cin >> a;
		return a;
	};
    vector<int> p(n);
    int i = 0;
    for(int j=1;j<n;j++)
    {
    	int pi_mod_pj = find(i,j);
    	int pj_mod_pi = find(j,i);

    	if(pi_mod_pj > pj_mod_pi)
    	{
    		// 3 8 
    		// 3 % 8 > 8 % 3
    		// this means i < j and we found i
    		// i % j > j % i
    		p[i] = pi_mod_pj;
    		i = j;
    	}
    	else
    	{
    		// we have found j;
    		p[j] = pj_mod_pi;
    	}
    }
    p[i] = n;
    cout << "!";
    for(int i=0;i<n;i++)
    {
    	cout << " " << p[i] << endl;
    }
    return 0;
}