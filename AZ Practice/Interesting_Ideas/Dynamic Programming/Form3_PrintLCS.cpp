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
string a,b;
int n,m;
// vector<vector<int>>dp;
int dp[5050][5050];
int back[5050][5050];
int rec(int i,int j)
{
	// pruning
	
	// base 
	if(i >= n || j >= m) return 0;
	// cache
	if(dp[i][j] != -1) return dp[i][j];
	// compute
	int ans = 0;
	if(rec(i+1,j) > ans) // skip character at index i
	{
		ans = rec(i+1,j);
		back[i][j] = 0;
	}
	if(rec(i,j+1) > ans) // skip character at index j
	{
		ans = rec(i,j+1);
		back[i][j] = 1;
	}
	if(a[i] == b[j] && rec(i+1,j+1) + 1 > ans)
	{//x[i]
		ans = 1 + rec(i+1,j+1);
		back[i][j] = 2;
	}
	// save and return
	return dp[i][j] = ans;
}
void generate(int i,int j)
{
	if(i >= n || j >= m) return ;
	if(back[i][j] == 0)
	{
		// cout << "-"<<a[i] << " ";
		generate(i+1,j);
	}
	else if(back[i][j] == 1)
	{
		// cout << "+"<<b[j] << " ";
		generate(i,j+1);
	}
	else
	{
		cout << a[i];
		generate(i+1,j+1);
	}
}
void solve()
{
	cin >> a >> b;
	n = a.size() , m = b.size();
	// dp.resize(n+1);
	// for(int i=0;i<=n;i++) dp[i].assign(m+1,-1);
	memset(dp,-1,sizeof(dp));
	rec(0,0);
	generate(0,0);
	// cout << endl;
}
signed main(){
	fast_io();
    int tt = 1;
    // cin >> tt;
    while(tt--)
    {
    	solve();
    }
    return 0;
}

// vector<int> nextGreater(vector<int> arr)
// {
//     int n = arr.size();
//     vector<int> nextG(n);
//     stack<int> st2;
//     st2.push(n);
//     for(int i=n-1;i>=0;i--)
//     {
//         if(st2.top() == n)
//         {
//             nextG[i] = n;
//             st2.push(i);
//             continue;
//         }
//         else
//         {
//             while(arr[st2.top()] <= arr[i] && st2.top()!=n)
//             {
//                 st2.pop();
//             }
//             nextG[i] = st2.top();
//             st2.push(i);
//         }
//     }
//     return nextG;
// }
// vector<int> nextSmaller(vector<int> arr)
// {
//     int n = arr.size();
//     vector<int> nextS(n);
//     stack<int> st;
//     st.push(n);
//     for(int i=n-1;i>=0;i--)
//     {
//         if(st.top() == n)
//         {
//             nextS[i] = n;
//             st.push(i);
//             continue;
//         }
//         else
//         {
//             while(arr[st.top()] >= arr[i] && st.top()!=n)
//             {
//                 st.pop();
//             }
//             nextS[i] = st.top();
//             st.push(i);
//         }
//     }
//     return nextS;
// }
// vector<int> prevG(vector<int> arr)
// {
//     int n = arr.size();
//     vector<int> prevG(n);
//     stack<int> st2;
//     st2.push(-1);
//     for(int i=0;i<n;i++)
//     {
//         if(st2.top() == -1)
//         {
//             prevG[i] = -1;
//             st2.push(i);
//             continue;
//         }
//         else
//         {
//             while(arr[st2.top()] <= arr[i] && st2.top()!=-1)
//             {
//                 st2.pop();
//             }
//             prevG[i] = st2.top();
//             st2.push(i);
//         }
//     }
//     return prevG;
// }
// vector<int> prevSmaller(vector<int> arr)
// {
//     int n = arr.size();
//     vector<int> prevS(n);
//     stack<int> st2;
//     st2.push(-1);
//     for(int i=0;i<n;i++)
//     {
//         if(st2.top() == -1)
//         {
//             prevS[i] = -1;
//             st2.push(i);
//             continue;
//         }
//         else
//         {
//             while(arr[st2.top()] >= arr[i] && st2.top()!=-1)
//             {
//                 st2.pop();
//             }
//             prevS[i] = st2.top();
//             st2.push(i);
//         }
//     }
//     return prevS;
// }

// #include<bits/stdc++.h>
// #define fast_io() ios::sync_with_stdio(0);cin.tie(0);
// #define endl '\n'
// using namespace std; 
// /* 
// for fast input output use printf and scanf;
// */
// string a,b;
// int n,m;
// int dp[1001][1001][2];
// int back[1001][1001][2];
// int rec(int i,int j,int f)
// {
//     // pruning
//     // base case 
//     if(i >= n || j >= m) return 0;
//     // cache
//     if(dp[i][j][f] != -1) return dp[i][j][f];
//     // compute
//     int ans = 0;
//     if(f == 0 && rec(i+1,j,f) > ans)
//      // skip character at index i
//     {
//         ans = rec(i+1,j,0);
//         back[i][j][f] = 0;
//     }
//     if(f == 0 && rec(i,j+1,f) > ans)
//      // skip character at index j
//     {
//         ans = rec(i,j+1,f);
//         back[i][j][f] = 1;
//     }
//     if(a[i] == b[j] && rec(i+1,j+1,1) + 1 > ans)
//     {
//         ans = 1 + rec(i+1,j+1,1);
//         back[i][j][f] = 2;
//     }
//     // save and return
//     return dp[i][j][f] = ans;
// }
// void generate(int i,int j,int f)
// {
//     if(i >= n || j >= m) return ;
//     if(back[i][j][f] == 0)
//     {
//         generate(i+1,j,0);
//     }
//     else if(back[i][j][f] == 1)
//     {
//         generate(i,j+1,f);
//     }
//     else if(back[i][j][f] == 2)
//     {
//         cout << a[i];
//         generate(i+1,j+1,1);
//     }
// }
// void solve()
// {
//     cin >> a >> b;
//     n = a.size() , m = b.size();
//     // dp.resize(n+1);
//     // for(int i=0;i<=n;i++) dp[i].assign(m+1,-1);
//     memset(dp,-1,sizeof(dp));
//     memset(back,-1,sizeof(back));
//     cout << rec(0,0,0) << endl;
//     generate(0,0,0);
//     cout << endl;
// }
// signed main(){
//     fast_io();
//     int tt = 1;
//     cin >> tt;
//     while(tt--)
//     {
//         solve();
//     }
//     return 0;
// }