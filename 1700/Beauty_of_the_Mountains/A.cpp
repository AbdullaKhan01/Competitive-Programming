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
bool comp(pair<int,int>&a,pair<int,int> &b){
	if(a.first == b.first) return a.second > b.second;
	return a.first < b.first;
}
void solve()
{
	int n,m,L;
	cin >> n >> m >> L;
	vector<pair<int,int>> h(n);
	for(int i=0;i<n;i++){
		cin >> h[i].first >> h[i].second;
	}
	sort(all(h),comp);
	int k = 1;
	vector<pair<int,int>> a(m);
	for(int i=0;i<n;i++){
		cin >> a[i].first >> a[i].second;
	}
	sort(all(a));
	int idx = 0;
	int j = 0;
	int cnt = 0;
	multiset<int> ms;
	int pr = 1;
	while(true){
		auto hrd = h[j];
		if(hrd.second < pr){
			j++;
			continue;
		}
		
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