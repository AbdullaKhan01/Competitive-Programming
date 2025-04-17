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
        vector<vector<int>>grid(n,vector<int>(m,0));
        vector<int> g;
        for(int i=1;i<=n;i++)
        {
        	for(int j=1;j<=m;j++)
        	{
        		// calc row ans and col ans
        		// total ans = row * col
        		int erow = max(i,k);
        		int ecol = max(j,k);

        		int maxrow = min(n,i+k-1);
        		int maxcol = min(m,j+k-1);
        		int rowans = min(k,maxrow - erow + 1);
        		int colans = min(k,maxcol - ecol + 1);

        		int l = rowans * colans;
        		// cout << l << " ";
        		g.push_back(l);
        	}
        	// cout << endl;
        }
        sort(rall(g));
        int w;
        cin >> w;
        vi arr(w);
        input(arr);
        sort(rall(arr));
        int ans = 0;
        for(int i=0;i<w;i++)
        {
        	ans += (arr[i] * g[i]);
        }
        cout << ans << endl;
    }
    return 0;
}