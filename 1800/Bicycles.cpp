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
    ll tt=1;
    // cin >> tt;
    while(tt--)
    {
        int n,m;
        cin >> n >> m;
	    vector<vector<pair<int,int>>>adj(n+1);
	    for(int i=0;i<m;i++)
	    {
	        int u,v,w;
	        cin >> u >> v >> w;
	        adj[u].push_back({v,w});
	        adj[v].push_back({u,w});
	    }
	    const int inf = 1e18;
	    vector<int> d(n+1,inf);
	    vector<int> p(n+1,-1);
	    // for(int i=1;i<=n;i++)
	    // {
	    // 	int slow;
	    // 	cin >> slow;
	    // 	for(auto &a:adj[i])
	    // 	{
	    // 		a.second *= slow;
	    // 	}
	    // }
	    int s = 1;
	    d[s] = 0;
	    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
	    pq.push({0,s});
	    while(!pq.empty())
	    {
	        int dist = pq.top().first;
	        int node = pq.top().second;
	        pq.pop();
	        for(auto it:adj[node])
	        {
	            int dn = it.first;
	            int ew = it.second;
	            if(dist + ew < d[dn])
	            {
	                d[dn] = dist + ew;
	                p[dn] = node;
	                pq.push({d[dn],dn});
	            }
	        }
	    }
	    int e = n;
	    if(d[e] == inf)
	    {
	    	cout << -1;
	    	return 0;
	    }
	    vector<int> ans;
	    while(e != -1)
	    {
	    	ans.push_back(e);
	    	e = p[e];
	    }
	    reverse(all(ans));
	    output(ans);
	    cout << endl;
    }
    return 0;
}