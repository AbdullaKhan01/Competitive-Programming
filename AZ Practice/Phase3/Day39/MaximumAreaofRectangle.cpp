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
int n,m;
vector<vector<int>> g;
vector<int> nextSmaller(vector<int> arr)
{
    int n = arr.size();
    vector<int> nextS(n);
    stack<int> st;
    st.push(n);
    for(int i=n-1;i>=0;i--)
    {
        if(st.top() == n)
        {
            nextS[i] = n;
            st.push(i);
            continue;
        }
        else
        {
            while(st.top()!=n && arr[st.top()] >= arr[i])
            {
                st.pop();
            }
            nextS[i] = st.top();
            st.push(i);
        }
    }
    return nextS;
}
vector<int> prevSmaller(vector<int> arr)
{
    int n = arr.size();
    vector<int> prevS(n);
    stack<int> st2;
    st2.push(-1);
    for(int i=0;i<n;i++)
    {
        if(st2.top() == -1)
        {
            prevS[i] = -1;
            st2.push(i);
            continue;
        }
        else
        {
            while(st2.top()!=-1 && arr[st2.top()] >= arr[i])
            {
                st2.pop();
            }
            prevS[i] = st2.top();
            st2.push(i);
        }
    }
    return prevS;
}
void solve()
{
	cin >> n >> m;
	g.assign(n,vector<int>(m,0));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> g[i][j];	
		}
	}
	vector<int> histogram(m,0);
	int ans = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(g[i][j] == 0) histogram[j] = 0;
			else{
				histogram[j] += 1;
			}
		}
		vector<int> next = nextSmaller(histogram);
		vector<int> prev = prevSmaller(histogram);
		for(int i=0;i<m;i++){
			int height = histogram[i];
			int x = next[i] - 1;
			int y = prev[i] + 1;
			int width = x - y + 1;
			ans = max(ans,height * width);
		}
	}
	cout << ans << endl;
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