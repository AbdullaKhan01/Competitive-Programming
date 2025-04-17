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
	int n,k;
	cin >> n >> k;
	string s;
	cin >> s;
	vector<int> l(k),r(k);
	for(int i=0;i<k;i++)
	{
		cin >> l[i];
	}
	for(int i=0;i<k;i++)
	{
		cin >> r[i];
	}
	vector<int> rev(r.back() + 1,0);
	int q;
	cin >> q;
	while(q--)
	{
		int x;
		cin >> x;
		int i = upper_bound(l.begin(),l.end(),x) - l.begin() - 1;
		int a = r[i] + l[i];
		int mini = min(x,a-x);
		rev[mini]++;
	}
	for(int i=0;i<k;i++)
	{
		int st = l[i];
		int en = r[i];
		int curr = 0;
		for(int j=st;j<=(st+en)/2;j++)
		{	
			curr += rev[j];
			int idx1 = j - 1;
			int idx2 = st + en - j - 1;
			if(curr % 2 != 0)
			{
				swap(s[idx1],s[idx2]);
			}
		}
	}
	cout << s << endl;
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