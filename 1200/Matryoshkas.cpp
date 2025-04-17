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
        int n;
        cin >> n;
        set<int> p;
        map<int,int> mp;
        while(n--){
        	int x;
        	cin >> x;
        	p.insert(x);
        	// p.insert(x+1);
        	mp[x]++;
        }
        int ans = 0;
        int prev = 0;
        for(auto it:p){
        	int l = mp[it];
        	ans+= max(1LL*0,l - prev);
        	prev = l;
        	if(mp.find(it+1) == mp.end()) prev = 0;
        }
        cout << ans << endl;
    }
    return 0;
}