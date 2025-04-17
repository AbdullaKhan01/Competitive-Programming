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
	
    ll tt;
    cin >> tt;
    while(tt--)
    {
        string s;
        cin >> s;
        vector<bool> used(s.size(),0);
        int n = s.size();
        int ans = 0;
       	for(int i=1;i<n;i++){
       		if(s[i] == s[i-1] && !used[i-1]){
       			used[i] = true;
       		}
       		if(i > 1 && s[i] == s[i-2] && !used[i-2]){
       			used[i] = true;
       		}
       		ans+=used[i];
       	}
       	cout << ans << endl;
    }
    return 0;
}