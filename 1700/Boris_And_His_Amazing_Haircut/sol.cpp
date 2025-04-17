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
vector<int> nextGreater(vector<int> &arr)
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
            while(st2.top()!=n && arr[st2.top()] <= arr[i])
            {
                st2.pop();
            }
            nextG[i] = st2.top();
            st2.push(i);
        }
    }
    return nextG;
}
void solve()
{
	int n;cin >> n;
	vector<int> a(n),b(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	for(int i=0;i<n;i++){
		cin >> b[i];
	}
	vector<int> next = nextGreater(b);
	map<int,int> req;
	map<int,int> pos;
	bool flag = true;
	//some manipulation
	for(int i=0;i<n;i++){
		if(b[i] > a[i]){
			flag = false;
			break;
		}
		if(b[i] == a[i] || (req.find(b[i])!=req.end() && pos[b[i]] >= i)){
			continue;
		}
		int idx = next[i];
		req[b[i]]++;
		pos[b[i]] = idx;

	}
	int x;cin >> x;
	map<int,int> have;
	for(int i=0;i<x;i++){
		int num;cin >> num;
		have[num]++;
	}
	for(auto it : req){
		if(have[it.first] < it.second){
			flag = false;
			break;
		}
	}
	cout << (flag ? yes : no) << endl;
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