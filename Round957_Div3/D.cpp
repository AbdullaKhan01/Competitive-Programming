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
        int n,m,k;
        cin >> n >> m >> k;
        string s;
        cin >> s;
        if(m >= n+1)
        {
        	cout << yes << endl;
        	continue;
        }
        vector<int> log,wt;
        bool flag = true;
        int idx = 0;
        for(int i=0;i<s.size();i++)
        {
        	if(s[i] == 'L') log.pb(i);
        	if(s[i] == 'W') wt.pb(i);
        }
        int st = -1;
        int water = 0;
        for(int i=0;i<s.size();i++)
        {
        	// cout << st << endl;

        	if(s[0] == 'L' && (st+m)>=n)
        	{
        		flag = true;
        		break;
        	}

        	if(idx<log.size() && (st+m) >= log[idx])
        	{
        		st = log[idx];
        		i = st;
        		idx++;
        	}
        	else
        	{
        		if(st==-1)
	        	{
	        		int g = i;
	        		while(g < n && m--)
	        		{
	        			if(s[g]=='W') st=g;
	        			g++;
	        		}
	        		i = g-1;
	        		st = g-1;
	        	}

        		if(s[i] == 'C'){
        			// cout << "here1" << endl;
        			flag = false;
        		}
        		else
        		{
        			int x = k;
        			while(i < n && x!=0)
        			{
        				if(s[i] == 'W') water++;
        				if(s[i] == 'L') break;
        				if(s[i] == 'C')
        				{
        					// cout << "here2" << endl;
        					flag = false;
        				}
        				i++;
        				st++;
        				x--;
        			}
        			if(i < n && x == 0)
        			{
        				if(s[i] == 'C' || s[i] == 'W')
        				{
        					// cout << "here3 " << i <<   endl;
        				 	flag = false;
        				}
        			}
        		}
        	}
        }
        if(water<=k && flag)
        	cout << yes << endl;
        else
        {
        	cout << no << endl;
        }
    }
    return 0;
}