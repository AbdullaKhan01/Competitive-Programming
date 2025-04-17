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
	string s;cin >> s;
	vector<set<int>> a(26,set<int>());
	for(int i=0;i<(int)s.size();i++){
		a[s[i] - 'a'].insert(i);
	}
	int q;cin >> q;
	while(q--){
		int ch;cin >> ch;
		if(ch == 1){
			int pos;
			char c;
			cin >> pos >> c;
			pos--;
			char c2 = s[pos];
			a[c2 - 'a'].erase(pos);
			a[c - 'a'].insert(pos);
			s[pos] = c;
			
		}
		else{
			int l,r;
			cin >> l >> r;
			l--,r--;
			int cnt = 0;
			for(int i=0;i<26;i++){
				auto pos = a[i].lower_bound(l);
				if(pos!=a[i].end() && *pos <= r)cnt++;
			}
			cout << cnt << endl;
		}
	}
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