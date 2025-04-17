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
int n,k;
set<int> st;
vector<int> temp;
vector<int> facts;
void find()
{
	int ab = min(1LL*13,(int)st.size()-1);
	for(auto it:st)
	{
		if(k <= facts[ab])
		{
			temp.push_back(it);
			st.erase(st.find(it));
			find();
			break;
		}
		k -= facts[ab];
	}
}
void solve()
{
	temp.clear();
	st.clear();
	cin >> n >> k;
	for(int i=1;i<=n;i++) st.insert(i);
	find();
	output(temp);
	cout << endl;
}
void init()
{
	int f = 1LL;
	for(int i=1;i<15;i++)
	{
		facts.push_back(f);
		f*=i;

	}
}
signed main(){
	fast_io();
	init();
    int tt = 1;
    // cin >> tt;
    while(tt--)
    {
    	solve();
    }
    return 0;
}