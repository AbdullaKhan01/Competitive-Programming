#include<bits/stdc++.h>
#define mod 1000000007
#define mod2 998244353
#define ceil(a,b) ((a+b-1)/b)
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
const int MAX = 1e5 + 5;
int dfs(int node,vector<vector<int>>&friends,vector<int>&visited,vi &arr){
	if(visited[node]) return INT_MAX;
	visited[node] = 1;
	int a = arr[node];
	int s = INT_MAX;
	for(auto it:friends[node]){
		if(!visited[it]){
			s = min(s,dfs(it,friends,visited,arr));
		}
	}
	return min(a,s);
}
signed main(){
	
    int n,m;
    cin >> n >> m;
    vi arr(n+1);
    rep(i,1,n+1){
    	cin >> arr[i];
    }
    vector<vector<int>>friends(n+1);
    rep(i,0,m){
    	int u,v;
    	cin >> u >> v;
    	friends[u].pb(v);
    	friends[v].pb(u);
    }
    vector<int> visited(n+1,0);
    int ans = 0;
    rep(i,1,n+1){
    	if(friends[i].size() == 0){
    		ans += arr[i];
    	}
    	else{
    		int p = 0;
    		if(!visited[i])
    			p = dfs(i,friends,visited,arr);
    		ans += p;
    	}
    }
    cout << ans << endl;
    return 0;
}