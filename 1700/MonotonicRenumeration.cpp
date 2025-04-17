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
long long binpow(long long a, long long b, long long m=mod2) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
signed main(){
	
    int n;
    cin >> n;
    vi arr(n);
    input(arr);
    // sort(all(arr));
    // output(arr);
    // for(auto it:arr){
    // 	cout << it << endl;
    // }
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++){
    	int e = arr[i];
    	mp[e] = i;
    }
    // for(auto it:mp){
    // 	cout << it.first << " " << it.second << endl;
    // }
    int occ = mp[arr[0]];
    int i = 0;
    for(;i<=occ;i++){
    	int e = arr[i];
    	occ = max(occ,mp[e]);
    }
    cout << occ << endl;
    // // int ans = 1;
    // set<int> s;
    // for(;i<n;i++){
    // 	s.insert(arr[i]);
    // }
    // cout << binpow(2,101)%mod2 << endl;
    return 0;
}