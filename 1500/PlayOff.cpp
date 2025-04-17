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
bool check(int x,int n,string s)
{
	
	int sm = 0 , lr = 0;
	int idx1=0,idx2=0;
	for(int i=0;i<n;i++)
	{
		if(s[i] == '1')
		{
			sm|=1<<idx1++;;
		}
		else
		{
			lr|=1<<idx2++;
		}
	}
	return sm <= x-1 && lr <= (1<<n)-x;
}
signed main(){
	fast_io();
    int n;
    cin >> n;
    string s;
    cin >> s;
    for(int i=1;i<=(1<<n);i++)
    {
    	if(check(i,n,s))
    	{
    		cout << i << " ";
    	}
    }
    return 0;
}