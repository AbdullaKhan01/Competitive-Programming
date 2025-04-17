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
        int n,k;
        cin >> n >> k;
        vector<pair<int,int>> ps;
        if(n == 4 && k == 3)
        {
        	cout << -1 << endl;
        	continue;
        }
        else
        {
        	//16 15
        	// 1111 1110
        	// 3 1
        	for(int i=n-2;i>=n/2;i--)
        	{
        		int p = 0;
        		int z = __builtin_clz(i);

        		for(int j=32-z-1;j>=0;j--)
        		{
        			if(1 & (i>>j))
        			{
        			}
        			else
        			{		
        				p |= (1<<j);
        			}
        		}
        		ps.push_back({i,p});
        	}
        }
        int a = n-1 , b = 0;
        if(k == n-1)
        {
        	// replace 0 with n-2
        	// replace n-2 with 3
        	// replace 3 with 0	 
        	for(auto it:ps)
        	{
        		if(it.first == 0 || it.second == 0)
        		{
        			if(it.first == 0) it.first = n-2;
	        		if(it.second == 0) it.second = n-2;
        		}
        		else if(it.first == n-2 || it.second == n-2)
        		{
        			if(it.first == n-2) it.first = 3;
        			if(it.second == n-2) it.second = 3;
        		}
        		else if(it.first == 3 || it.second == 3)
        		{
        			if(it.first == 3) it.first = 0;
        			if(it.second == 3) it.second = 0;	
        		}
        		
        		cout << it.first << " " << it.second << endl;
        	}
        	cout << n-1 << " " << n-2 << endl;
        	continue;
        }
        
        for(auto it:ps)
        {
        	if(it.first == k)
        	{
        		swap(b,it.first);
        	}
        	else if(it.second == k)
        	{
        		swap(b,it.second);
        	}
        	cout << it.first << " " << it.second << endl;
        }
        cout << a << " " << b << endl;
    }
    return 0;
}