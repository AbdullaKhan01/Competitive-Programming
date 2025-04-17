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
/*

to make it lexicographically smaller we must assure
that the first character of the string is as small as possible
then the second character then the third character and so
on 

so can we do it greedily -> YES we can

VERDICT -> ACCEPTED 

*/
signed main(){
	fast_io();
    ll tt;
    cin >> tt;
    while(tt--)
    {
        int n,k;
        cin >> n >> k;
        string s;
        cin >> s;
        char prev = 'a';
        map<char,char> mp;
        mp['a'] = 'a';
        for(int i=0;i<n;i++)
        {
        	if(s[i] <= prev)
        	{
        		continue;
        	}
        	else
        	{
        		if(k == 0) continue;
        		int want = s[i] - prev;
        		if(want <= k)
        		{
        			// decider = max(decider)
        			prev = s[i];
        			mp[s[i]] = mp[s[i] - want];
        			k-=want;
        		}
        		else
        		{
        			prev = s[i];
        			char new_char = s[i] - k;
        			mp[s[i]] = new_char;
        			k = 0; 
        		}
        	}
        }
        for(auto it:mp)
        {
        	for(int i=0;i<n;i++)
        	{
        		if(s[i] <= it.first) s[i] = min(s[i],it.second);
        	}
        }
        cout << s << endl;
    }
    return 0;
}