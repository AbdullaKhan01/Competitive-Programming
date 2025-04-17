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
        
        int n,m;
        cin >> n >> m;
        vi arr(n);
        input(arr);
        int ans = 0;
        vector<int> c;
        for(int i=0;i<arr.size();i++)
        {
        	if(arr[i] % 10 == 0)
        	{
        		int a = arr[i];
        		int cnt = 0;	
        		while(a % 10 == 0)
        		{
        			a/=10;
        			cnt++;
        		}
        		c.pb(cnt);
        		ans += to_string(arr[i]).size()-cnt;
        	}
        	else
        	{
        		ans += to_string(arr[i]).size();
        	}
        }
        sort(rall(c));
        for(int i=0;i<c.size();i++)
        {
        	if(i%2 == 0) continue;
        	else ans += c[i];
        } 

        cout << (ans >= m+1?"Sasha":"Anna") << endl;
    }
    return 0;
}