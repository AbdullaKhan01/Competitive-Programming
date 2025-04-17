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
	
    int n;
    cin >> n;
    map<string,int>mp;
    mp["polycarp"] = 1;
    int ans = 1;
    while(n--){
    	string a,b,c;
    	cin >> a >> b >> c;
    	transform(all(a),a.begin(),::tolower);
    	transform(all(c),c.begin(),::tolower);
    	mp[a] = mp[c] + 1;
    	ans = max(ans,mp[a]);

    }
    // for(auto it:mp){
    // 	cout << it.first << " " << it.second << endl;
    // }
    cout << ans << endl;
    return 0;
}