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
        int q;
        cin >> q;
        int a1[26]={0};
        int a2[26]={0};
        a1[0] = a2[0] = 1;
        bool flag = false;
        while(q--)
        {
        	int n,k;string s;
        	cin >> n >> k >> s;

        	for(int i=0;i<(int)s.size();i++)
        	{
        		if(n == 1)
        		{
        			a1[s[i] - 'a'] += k;
        		}
        		else
        		{
        			if(s[i] - 'a' >= 1) flag = true;
        			a2[s[i] - 'a'] += k;
        		}
        	}
	        
	        // aaabb
	        // aaaaaaabc
	        if(flag)
	        {
	        	cout << "YES" << endl;
	        	continue;
	        }

	        // now 2nd string consist of only a's
	        // if first string contains only a's and has size
	        // <= 2nd string then only answer is yes

	        bool check = true;
	        for(int i=1;i<26;i++)
	        {
	        	if(a1[i] != 0) check = false;
	        }
	        if(check == false)
	        {
	        	cout << no << endl;
	        }

	        else
	        {
	        	if(a1[0] < a2[0])
	        	{
	        		cout << yes << endl;
	        	}
	        	else cout << no << endl;
	        }
        }
    }
    return 0;
}