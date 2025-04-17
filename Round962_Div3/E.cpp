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
ll modAdd(ll a,ll b){
    ll p = (a%mod + b%mod)%mod;
    return p;
}
ll modSub(ll a,ll b){
    ll p = (a%mod - b%mod)%mod;
    if(p<0) p+=mod;
    return p;
}
ll modMul(ll a,ll b){
    ll p = (a%mod * b%mod)%mod;
    return p;
}
signed main(){
	fast_io();
    ll tt;
    cin >> tt;
    while(tt--)
    {
        string s;
        cin >> s;
        int n = s.size();
        vector<int> pref(n+1,0);
        for(int i=0;i<n;i++)
        {
        	pref[i+1] = (s[i] == '0' ? -1 : 1) + pref[i];
        }

        map<int,int> mp;
        int cnt = 0;
        mp[0]=1;
        for(int i=1;i<=n;i++)
        {
        	// cnt l and r for x and y
        	// first check if some x and y exists
        	// if exists then SUM from x to y = 0
        	
            cnt = modAdd(cnt,modMul((n-i+1),mp[pref[i]]));

            // if(mp.find(pref[i]) != mp.end())
        	// {
        	// 	cnt += (prev + mp[pref[i]]);
        	// 	prev = cnt;
        	// }
        	// mp[pref[i]]++;
            mp[pref[i]] = modAdd(mp[pref[i]],i+1);
        }
        cout << cnt << endl;
    }
    return 0;
}