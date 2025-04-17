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
signed main(){
	fast_io();
    ll tt;
    cin >> tt;
    while(tt--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        string a = s;
        sort(all(a));
        if(s == a)
        {
        	cout << 0 << endl;
        	continue;
        }
        string p;
        vector<int> indexes;
        int k = INT_MIN;
        for(int i=n-1;i>=0;i--)
        {
        	int d = s[i] - 48;
        	if(d >= k)
        	{
        		p.pb(s[i]);
        		indexes.pb(i);
        		k = d;
        	}
        }
        reverse(all(indexes));
        int idx = 0;
        for(int i=0;i<indexes.size();i++)
        {
        	s[indexes[i]] = p[idx++];
        }
        if(s == a)
        {
        	char ch = p[p.size()-1];

        	cout << p.size() - count(all(p),ch) << endl;
        }
        else{
        	cout << -1 << endl;
        }
    }
    return 0;
}