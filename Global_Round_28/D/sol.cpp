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
	int n,m;
	cin >> n >> m;
	vector<int> par(n),pro(m);
	for(int i=0;i<n;i++){
		cin >> par[i];
	}
	int kevin = par[0];
	for(int i=0;i<m;i++){
		cin >> pro[i];
	}
	sort(all(par));
	sort(all(pro));
	vector<int> at;
	for(int i=0;i<n;i++){
		if(pro[i] > kevin){
			auto val = lower_bound(par.begin(),par.end(),pro[i]) - par.begin();
			// cout << pro[i] << " " << val << endl;
			if(val != n)
				at.push_back(n - val);
		}
	}
	sort(all(at));
	// output(at);cout << endl;
	vector<int> pref(at.size(),0);
	if(at.size())
		pref[0] = at[0];
	for(int i=1;i<(int)at.size();i++){
		pref[i] = pref[i-1] + at[i];
	}
	for(int i=1;i<=m;i++){
		int contest = m/i;
		int removed = m % i;
		int addon = 0;
		if(removed >= at.size()) addon = 0;
		else{
			int start = at.size() - removed - 1;
			// cout << start << endl;
			addon = pref[start];
		}
		int rank = contest;
		cout << rank+addon << " ";
	}
	cout << endl;
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