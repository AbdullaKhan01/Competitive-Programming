#include<bits/stdc++.h>
#define mod 1000000007
#define mod2 998244353
#define ceil(a,b) ((a+b-1)/b)
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
signed main(){
	
    set<string> st;
    vector<string> arr = {"ABSINTH", "BEER", "BRANDY", "CHAMPAGNE", "GIN", "RUM", "SAKE", "TEQUILA", "VODKA", "WHISKEY", "WINE"};
    for(auto it:arr) st.insert(it);
    int tt;
	cin >> tt;;
	int ans = 0;
	while(tt--){
		string s;
		cin >> s;
		if(s[0]>='0' && s[0]<='9'){
			int n = stoi(s);
			ans+=(n<18);
		}
		else{
			if(st.count(s) == 1){
				ans++;
			}
		}
	}
	cout << ans << endl;
    return 0;
}