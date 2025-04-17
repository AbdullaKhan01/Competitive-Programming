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
    vi arr(n);
    input(arr);
    map<int,int> mp;
    set<int> s;
    for(int i=0;i<n;i++){
    	s.insert(arr[i]);
    	mp[arr[i]]++;
    }
    sort(all(arr));
    if(arr[n-1] == arr[0]){
    	cout << 0 << " " << (n * (n-1))/2 << endl;
    	return 0;
    }
    int lar = arr[n-1] - arr[0];
    int ans = 0;
    for(auto it:s){
    	int finder = it + lar;
    	if(mp.count(finder)){
    		ans+= mp[finder] * mp[it];
    	}
    }
    cout << lar << " " << ans << endl;
    return 0;
}