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
struct node{
	int s1,s2,f1,f2;
	node(){
		s1 = 0,s2 = 0,f1=0,f2=0;
	}
};
void solve()
{
	int n,m,k;
	cin >> n >> m >> k;
	vector<vector<int>> g(n,vector<int>(m,0));
	vector<vector<node>> pref(n,vector<node>(m));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> g[i][j];
		}
	}
	vector<string> s(n);
	for(int i=0;i<n;i++){
		cin >> s[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(s[i][j] == '1') pref[i][j].f1++,pref[i][j].s1 = g[i][j];
			else pref[i][j].f2++,pref[i][j].s2 = g[i][j];
			if(j > 0){

				 pref[i][j].f1 += pref[i][j-1].f1;
				 pref[i][j].f2 += pref[i][j-1].f2;
				 pref[i][j].s1 += pref[i][j-1].s1;
				 pref[i][j].s2 += pref[i][j-1].s2;
			}
			if(i > 0){
				 
				 pref[i][j].f1 += pref[i-1][j].f1;
				 pref[i][j].f2 += pref[i-1][j].f2;
				 pref[i][j].s1 += pref[i-1][j].s1;
				 pref[i][j].s2 += pref[i-1][j].s2;
			}
			if(i > 0 && j > 0){
				 pref[i][j].f1 -= pref[i-1][j-1].f1;
				 pref[i][j].f2 -= pref[i-1][j-1].f2;
				 pref[i][j].s1 -= pref[i-1][j-1].s1;
				 pref[i][j].s2 -= pref[i-1][j-1].s2;
			}
		}
	}
	map<int,int> a;
	int sum = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			node ans = pref[i][j];
			int x2 = i,y2 = j;
			int x1 = i - k + 1;
			int y1 = j - k + 1;
			if(x1 >= 0 && y1 >= 0){
				if(y1 > 0){
					ans.s1 -= pref[x2][y1-1].s1;
					ans.s2 -= pref[x2][y1-1].s2;
					ans.f1 -= pref[x2][y1-1].f1;
					ans.f2 -= pref[x2][y1-1].f2;
				} 
				if(x1 > 0){
					ans.s1 -= pref[x1-1][y2].s1;
					ans.s2 -= pref[x1-1][y2].s2;
					ans.f1 -= pref[x1-1][y2].f1;
					ans.f2 -= pref[x1-1][y2].f2;	
				}
				if(x1 > 0 && y1 > 0){
					ans.s1 += pref[x1-1][y1-1].s1;
					ans.s2 += pref[x1-1][y1-1].s2;
					ans.f1 += pref[x1-1][y1-1].f1;
					ans.f2 += pref[x1-1][y1-1].f2;
				}
				int diff = abs(ans.f1 - ans.f2);
				if(diff != 0){
					a[diff]++;
				}
			}
		}
	}
	int s1 = 0,s2 = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(s[i][j] == '1') s1 += g[i][j];
			else s2 += g[i][j];
		}
	}
	// k 
	// array
	// k factors ke
	// 
	// 28 sx + sy = 28;
	bool flag = false;
	sum = abs(s1 - s2);
	sum = abs(sum);
	if(sum == 0) flag = true;
	vector<int> pp;
	for(auto it : a){
		pp.push_back(it.first);
	}
	int sz = (int)pp.size();
	for(int i=0;i<sz;i++){
		for(int j=i;j<sz;j++){
			pp[j] = __gcd(pp[i],pp[j]);
		}
	}
	map<int,int> fl;
	for(auto it : pp) fl[it]++;
	vector<int> mul;
	for(int i=1;i*i<=sum;i++){
		if(sum % i == 0){
			mul.push_back(i);
			if(sum/i != i) mul.push_back(sum/i);
		}
	} 
	sort(all(mul));
	for(auto it : mul){
		if(fl.count(it) || a.count(it)) flag = true;
	}

	cout << (flag ? "YES":"NO") << endl;
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