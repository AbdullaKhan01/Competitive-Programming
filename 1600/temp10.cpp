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
vector<int> nextGreater(vector<int> arr)
{
    int n = arr.size();
    vector<int> nextG(n);
    stack<int> st2;
    st2.push(n);
    for(int i=n-1;i>=0;i--)
    {
        if(st2.top() == n)
        {
            nextG[i] = n;
            st2.push(i);
            continue;
        }
        else
        {
            while(arr[st2.top()] <= arr[i] && st2.top()!=n)
            {
                st2.pop();
            }
            nextG[i] = st2.top();
            st2.push(i);
        }
    }
    return nextG;
}
vector<int> prevG(vector<int> arr)
{
    int n = arr.size();
    vector<int> prevG(n);
    stack<int> st2;
    st2.push(-1);
    for(int i=0;i<n;i++)
    {
        if(st2.top() == -1)
        {
            prevG[i] = -1;
            st2.push(i);
            continue;
        }
        else
        {
            while(arr[st2.top()] <= arr[i] && st2.top()!=-1)
            {
                st2.pop();
            }
            prevG[i] = st2.top();
            st2.push(i);
        }
    }
    return prevG;
}

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
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
	}	
	vector<int> x = nextSmaller(a);
	vector<int> y = prevSmaller(a);
	int ans = 0;
	for(int i=0;i<n;i++)
	{
		// cout << i << " " << x[i] << " " << y[i] << endl;
		ans += (a[i]) * (x[i] - 1 - y[i]);
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