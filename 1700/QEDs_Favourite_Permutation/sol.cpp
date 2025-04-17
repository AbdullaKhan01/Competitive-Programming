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
string s;
void flip(int i){
	if(s[i] == 'L') s[i] = 'R';
	else s[i] = 'L';
}
void solve()
{
	int n,q;cin >> n >> q;
	vector<int> a(n+1);
	set<int> notAllowed,violating;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	int f = -1;
	for(int i=1;i<=n;){
		if(a[i] != i){
			f = max(f,a[i]);
			while(i <= f){
				f = max(f,a[i]);
				if(i < f)
					notAllowed.insert(i);
				i++;
			}
			f = -1;
		}
		else i++;
	}
	s.resize(n+1);
	for(int i=1;i<=n;i++){
		cin >> s[i];
	}
	for(int i=2;i<=n;i++)
	{
		if(s[i] == 'R' && s[i-1] == 'L'){
			if(notAllowed.find(i-1) != notAllowed.end()){
				violating.insert(i-1);
			}
		}
	}
	// for(auto it:notAllowed){
	// 		cout << it << " ";
	// 	}
	// cout << endl;	
	// for(auto it:violating){
	// 		cout << it << " ";
	// 	}
	// cout << endl;	
	
	while(q--){
		int x;cin >> x;
		flip(x);
		if(x >= 2){
			char ch = s[x-1];
			char ch2 = s[x];
			if(ch == 'L' && ch2 == 'R'){
				if(notAllowed.find(x-1) != notAllowed.end()){
					violating.insert(x-1);
				}
			}
			else{
				if(violating.find(x-1) != violating.end()){
					violating.erase(x-1);
				}
			}
		}
		if(x+1 <= n){
			char ch = s[x];
			char ch2 = s[x+1];
			if(ch == 'L' && ch2 == 'R'){
				if(notAllowed.find(x) != notAllowed.end()){
					violating.insert(x);
				}
			}
			else{
				if(violating.find(x) != violating.end()){
					violating.erase(x);
				}
			}
		}

		cout << (violating.empty() ? yes : no) << endl;
	}
	// cout << endl;
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