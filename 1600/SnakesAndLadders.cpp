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
const int INF = 1e9;
int n,m;
int dist[101];
int l[101];
int s[101];
void bfs(int st)
{
	for(int i=1;i<=100;i++)
	{
		dist[i] = INF;
	}
	queue<int> q;
	dist[st] = 0;
	q.push(st);
	while(!q.empty())
	{
		int front = q.front();q.pop();
		if(l[front] != 0 && dist[l[front]] == INF)
		{
			dist[l[front]] = dist[front];
			q.push(l[front]);
		} 
		if(s[front] != 0 && dist[s[front]] == INF)
		{
			dist[s[front]] = dist[front];
			q.push(s[front]);
		} 
		for(int i=6;i>=1;i--)
		{
			int v = front + i;
			if(dist[v] == INF)
			{
				dist[v] = dist[front] + 1;
				q.push(v);
			}
		}
	}
}
void solve()
{
	for(int i=1;i<100;i++) l[i]=s[i]=0;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		int x,y;
		cin >> x >> y;
		l[x] = y;
	}
	cin >> m;
	for(int i=0;i<m;i++)
	{
		int x,y;
		cin >> x >> y;
		s[x] = y;
	}
	bfs(0);
	if(dist[100] == INF) cout << -1 << endl;
	else cout << dist[100] << endl;
}
signed main(){
	fast_io();
    int tt = 1;
    cin >> tt;
    while(tt--)
    {
    	solve();
    }
    return 0;
}