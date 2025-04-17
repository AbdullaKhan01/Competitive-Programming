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
vector<int> palindrome(int n){
	vector<int> ans;
	int m = ceil(n,2);
	int st = pow(10,m - 1);
	int en = pow(10,m);
	for(int i=st;i<en;i++){
		string s = to_string(i);
		if(n % 2 == 0){
			string temp = s;
			reverse(temp.begin(),temp.end());
			ans.push_back(stoll(s + temp));
		}
		else{
			string temp = s;
			temp.pop_back();
			reverse(temp.begin(),temp.end());
			ans.push_back(stoll(s + temp));
		}
	}
	return ans;
}

vector<int> factorial;
void precompute(){
	factorial.assign(11,0);
	factorial[0] = 1;
	factorial[1] = 1;
	for(int i=2;i<11;i++){
		factorial[i] = i * factorial[i-1];
	}
	
}
int combination(int n){
	vector<int> g(10,0);
	string s = to_string(n);
	for(auto it : s){
		g[it - '0']++;
	}
	int ans = factorial[s.size()];
	for(int i=0;i<10;i++){
		ans /= factorial[g[i]];
	}
	int bad = 0;
	if(g[0] > 0){
		bad = factorial[s.size()-1];
		for(int i=1;i<10;i++){
			bad /= factorial[g[i]];
		}
		bad /= factorial[g[0] - 1];
	}
	return ans - bad;
}
void solve()
{
	int n,k;cin >> n >> k;
	vector<int> pal = palindrome(n);

	int ans = 0;
	vector<int> gogo;
	set<string> mp;
	for(auto it : pal){
		if(it % k == 0){
			string alp = to_string(it);
			sort(alp.begin(),alp.end());
			if(mp.count(alp)) continue;
			mp.insert(alp);
			int l = combination(it);
			ans += l;
		}
	}
	cout << ans << endl;
}
void solve2(){
	
}
signed main(){
	precompute();
	fast_io();
    int tt = 1;
    // cin >> tt;
    while(tt--)
    {
    	solve();
    	// test();
    }
    return 0;
}