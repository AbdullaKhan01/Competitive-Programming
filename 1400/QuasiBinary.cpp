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
void generate(vector<int>&ans,int index,string s){
	if(s.size() >= index){
		ans.push_back(stoi(s));
		return ;
	}
	generate(ans,index,s+"0");
	generate(ans,index,s+"1");
}
string solve(int tar,vector<int>&binaries,vector<string> &dp){
	if(tar == 0) return "";
	if(tar == 1) return "1";
	if(dp[tar]!="") return dp[tar];
	string ans="";
	int size = INT_MAX;
	int n = binaries.size();
	for(int i=n-1;i>=1;i--){
		if(binaries[i] <= tar){
			string s = to_string(binaries[i]) + " " + solve(tar-binaries[i],binaries,dp);
			if(s.size() <= size){
				ans = s;
				size = s.size();
			}
		}
	}
	return dp[n] = ans;
}
signed main(){
	fast_io();
	vector<int> binaries;
	for(int i=1;i<=6;i++){
		generate(binaries,i,"");
	}
	set<int> s;
	for(auto it:binaries){
		s.insert(it);
	}
	binaries.clear();
	for(auto it:s){
		binaries.pb(it);
	}
	sort(all(binaries));
	// for(auto it:binaries){
	// 	cout << it << endl;
	// }
	vector<int> ans;
	int n;
    cin >> n;
    if(n == 0){
    	cout << 0 << endl;
    	return 0;
    }
    vector<string> dp(n+1,"");
    string p = solve(69,binaries,dp);
    cout << p << endl;
	// sort(all(ans));
	// cout << ans.size() << endl;
	// for(auto it:ans){
	// 	cout << it << " ";
	// }

    return 0;
}