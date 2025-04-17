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
    vi brr(n+1,0);
    // brr[0] = arr[0];
    for(int i=1;i<=n;i++){
    	brr[i] = brr[i-1] + arr[i-1];
    }
    sort(all(arr));
    vi crr(n+1,0);
    // crr[0] = arr[0];
    for(int i=1;i<=n;i++){
    	crr[i] = crr[i-1] + arr[i-1];
    }

    int m;
    cin >> m;
    while(m--){
    	int type,l,r;
    	cin >> type >> l >> r;
    	// l--,r--;
    	if(type == 1){
    		cout << brr[r] - brr[l-1] << endl;
    	}
    	if(type == 2){
    		cout << crr[r] - crr[l-1] << endl;
    	}
    }
    return 0;
}