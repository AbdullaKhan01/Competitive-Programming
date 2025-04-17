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
        vi arr(n);
        input(arr);
        set<int> s;
        map<int,int> f1;
        for(int i=0;i<m;i++)
        {
        	int x;
        	cin >> x;
        	s.insert(x);
        	f1[x]++;
        }
        map<int,int> f2;
        int i = 0,j=0;
        int cnt = 0;
        while(j < m)
        {
        	int e = arr[j];
        	f2[e]++;
        	if(s.find(e) != s.end())
        	{
	        	if(f2[e] <= f1[e])
	        	{
	        		cnt++;
	        	}
        	}
        	j++;
        }
        int ans = (cnt >= k);
        // cout << ans << endl;
        while(i <= j && j < n)
        {
        	// cout << i << " " << j << endl;
        	int e = arr[i];
        	// cout << e << endl;
        	if(f2[e] <= f1[e]) cnt--;
        	f2[e]--;
        	int add = arr[j];
        	// cout << add << endl;
        	f2[add]++;
        	// cout << "here "<<f2[add] << " " << f1[add] << endl;
        	if(s.find(add) != s.end())
        	{
        		// cout << "here" << endl;
        		if(f2[add]<=f1[add])
        		{
        			// cout << "here" << endl;
        			cnt++;
        		}
        	}
        	if(cnt >= k) ans++;
        	i++;
        	j++;
        }
        // cout << endl;
        cout << ans << endl;
    }
    return 0;
}