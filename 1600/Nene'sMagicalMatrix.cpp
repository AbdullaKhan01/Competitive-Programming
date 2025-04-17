// #include<bits/stdc++.h>
// #define mod 1000000007
// #define mod2 998244353
// #define ceil(a,b) ((a+b-1)/b)
// #define floor(a,b)((a-b+1)/b)
// #define fast_io() ios::sync_with_stdio(0);cin.tie(0);
// #define ll long long
// #define int long long
// #define vi vector<int>
// #define all(x) (x).begin(),(x).end()
// #define rall(x) (x).rbegin(),(x).rend()
// #define input(x) for(auto &a:x) cin >> a;
// #define output(x) for(auto a:x) cout << a <<" ";
// #define rep(i,a,n) for(int i=(a);i<n;i++)
// #define pb push_back
// #define ppb pop_back
// #define pf push_front
// #define ppf pop_front
// #define ff first
// #define ss second
// #define si set<int>
// #define pii pair<int,int>
// #define mii map<int,int>
// #define msi map<string,int>
// #define yes "YES"
// #define no "NO"
// #define endl '\n'
// using namespace std; 
// /* 
// for fast input output use printf and scanf;
// */
// void solve()
// {
// 	int n;
// 	cin >> n;
// 	vector<vector<int>>rowM(n+1);
// 	vector<vector<int>>colM(n+1);

// 	vector<int> indegR(n+1,0);
// 	vector<int> indegC(n+1,0);
// 	for(int i=1;i<=n;i++)
// 	{
// 		for(int j=1;j<=n;j++)
// 		{
// 			// {i,j}
// 			int col = i;
// 			int row = j;
// 			if(col > row)
// 			{
// 				// row should be done before col
// 				rowM[i].push_back(j);
// 				indegC[j]++;
// 			}
// 			else if(row > col)
// 			{
// 				// col should be done before row
// 				colM[j].push_back(i);
// 				indegR[i]++;
// 			}
// 		}
// 	}

// 	queue<pair<int,int>>q;
// 	for(int i=1;i<=n;i++)
// 	{
// 		if(indegR[i] == 0)
// 		{
// 			q.push({1,i});
// 		}
// 		if(indegC[i] == 0)
// 		{
// 			q.push({2,i});
// 		}
// 	}
// 	while(!q.empty())
// 	{
// 		pair<int,int> front = q.front();q.pop();
// 		int a = front.first;
// 		int b = front.second;
// 		if(a == 1)
// 		{
// 			cout << "Doing Row " << b << endl;
// 			for(auto v:rowM[b])
// 			{
// 				indegC[v]--;
// 				if(indegC[v] == 0)
// 				{
// 					q.push({2,v});
// 				}
// 			}
// 		}
// 		if(a == 2)
// 		{
// 			cout << 
// 			for(auto v:colM[b])
// 			{
// 				indegR[v]--;
// 				if(indegR[v] == 0)
// 				{
// 					q.push({1,v});
// 				}
// 			}
// 		}
// 	}
// }
// signed main(){
// 	fast_io();
//     int tt = 1;
//     cin >> tt;
//     while(tt--)
//     {
//     	solve();
//     }
//     return 0;
// }

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
void solve()
{
	int n;
	cin >> n;
	string s;
	vector<int> temp;
	for(int i=1;i<=n;i++)
	{
		s += to_string(i);
		if(i < n) s.push_back(' ');
	}
	int ans = 0;
	for(int i=n;i>=1;i--)
	{
		ans += i*(2*i-1);
	}
	cout << ans << " " << 2*n << endl;
	for(int i=n;i>=1;i--)
	{
		cout << 1 << " " << i << " " << s << endl;
		cout << 2 << " " << i << " " << s << endl;
	}
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