#include<bits/stdc++.h>
#define mod 1000000007
#define mod2 998244353
#define ceil(a,b) ((a+b-1)/b)
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
const int MAX_N = 1000100;
int divisors[MAX_N];
void precompute()
{
	for(int i=1;i<MAX_N;i++)
	{
		for(int j=i;j<MAX_N;j+=i)
		{
			divisors[j]+=1;
		}
	}
}
void solve()
{
	precompute();
	int q;cin>> q;
	while(q--)
	{
		int x;cin >> x;
		cout << divisors[x] << endl; 
	}
}
signed main(){
	
    solve();
    return 0;
}