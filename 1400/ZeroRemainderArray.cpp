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
        vi arr(n);
        input(arr);
        int x = 1;
        for(int i=0;i<n;i++)
        {
        	arr[i] = (k - arr[i]%k)%k;
        }
        sort(all(arr));
        output(arr);
        cout << endl;
        map<int,int> mp;
        map<int,vector<int>> ms;
        for(int i=0;i<n;i++)
        {
        	if(arr[i] == 0) continue;
        	mp[arr[i]]++;
        	int freq = mp[arr[i]];
        	ms[freq].push_back(arr[i]);
        }
        vector<int> given;
        for(auto it:ms)
        {
        	for(auto jt:it.second)
        	{
        		given.push_back(jt);
        	}
        }
        int ans = 0;
        int flag = 0;
        for(int i=0;i<given.size();i++)
        {
        	if(given[i] == 0) continue;
        	flag = 1;
        	if(given[i] == x)
        	{
        		ans++;
        		x = (x+1)%k;
        	}
        	else if(given[i] > x)
        	{
        		ans = ans + (given[i]-x) + 1;
        		x = (given[i] + 1)%k;
        	}
        	else if(given[i] < x)
        	{
        		ans = ans + (k - (x - given[i])) + 1;
        		x = (given[i]+1) % k;
        	}
        }
        ans += flag;
        cout << ans << endl;
    }
    return 0;
}