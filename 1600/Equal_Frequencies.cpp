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
/*

APPROACH -> Let's say we have a string T

let x = length of the string

let s = final ans string

now let k be the no of different characters in string s

let c = no of occurence of each character
		(since each character occures same no of times)

so length of string s = k * c 
   length of string s = x

so k * c = x

this means k and c are the factors of size of the string t

now can we check for each factor ? 

observation k can never be > 26

at max 26 k values are possible 

so for each k we can traverse the string length

how to check ??	

5 1 
1 5





*/

vector<int> getFactors(int n){
	vector<int> ans;
	for(int i=1;i*i<=n;i++){
		if(n % i == 0)
		{
			ans.push_back(i);
			if(n/i != i) ans.push_back(n/i);
		}
	}
	return ans;
}

void solve(){
	int n;cin >> n;
	string s;cin >> s;
	vector<int> mp(26,0);
	vector<vector<int>> pos(26,vector<int>());
	for(int i=0;i<n;i++){
		mp[s[i]-'a']++;
		pos[s[i] - 'a'].pb(i);
	}
	vector<int> order(26);
	iota(order.begin(),order.end(),0);
	sort(all(order),[&](int a,int b){
		return mp[a] > mp[b];
	});
	
	vector<int> f = getFactors(n);
	int ans = 1e9;
	int ans_occ = 0;
	for(int i=0;i<(int)f.size();i++)
	{
		int cnt = 0;
		int dist = f[i];
		int occu =  n/f[i];
		if(dist > 26) continue;
		// we have less than <= 26
		for(int i=0;i<26;i++)
		{
			if(dist > 0)
				cnt += max(0LL,mp[order[i]] - occu);
			else cnt += mp[order[i]];	
			dist--;
		}
		if(cnt < ans)
		{
			ans = cnt;
			ans_occ = occu;
		}
	}
	// cout << ans << " " << ans_occ << endl;
	int dist = n/ans_occ;
	vector<int> cnt(26,0);
	vector<int> used(26,ans_occ);
	vector<int> g(n,0);
	for(int i=0;i<26;i++)
	{
		int cnt = 0;
		for(auto it : pos[order[i]])
		{
			if(dist > 0 && cnt < ans_occ){
				g[it] = order[i];
				used[order[i]]--;
			} 
			else g[it] = -1;
			cnt++;
		}
		dist--;
	}
	vector<int> border(26);
	iota(border.begin(),border.end(),0);
	sort(all(border),[&](int a,int b){
		return used[a] < used[b];
	});
	int j = 0;
	for(int i=0;i<(int)g.size();i++)
	{
		while(j < 26 && used[border[j]] == 0) j++;
		if(g[i] == -1)
		{
			g[i] = border[j];
			used[border[j]]--;
		}
	}
	string f_ans(n,' ');
	for(int i=0;i<n;i++)
	{
		f_ans[i] = 'a' + g[i];
	}
	cout << ans << endl;
	cout << f_ans << endl;
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