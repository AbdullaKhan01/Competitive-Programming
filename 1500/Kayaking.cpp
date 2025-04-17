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

//VERDICT -> ACCEPTED
signed main(){
	fast_io();
    ll tt=1;
    // cin >> tt;
    while(tt--)
    {
        int n;
        cin >> n;
        vi a(2*n);
        input(a);
        sort(all(a));
        int mini = INT_MAX;
        for(int i=0;i<2*n;i++)
        {
        	for(int j=i+1;j<2*n;j++)
        	{
        		int ans = 0;
        		vector<int> v;
        		for(int k=0;k<2*n;k++)
        		{
        			if(k != i && k!= j) v.push_back(a[k]);
        			if(v.size() == 2)
        			{
        				ans += abs(v[1]-v[0]);
        				v.clear();
        			}
        		}
        		// cout << i << " " << j << " " << ans << endl;
        		mini = min(mini,ans);
        	}
        }
        cout << mini << endl;
    }
    return 0;
}

