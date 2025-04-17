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
	
    int n,m;
    cin >> n >> m;
    vi arr(n),brr(n);
    input(arr);
    input(brr);
    int total = 0;
    int sakta = 0;
    // int kiya = 0;
    vector<int>crr(n,0);
    int p = n-1;

    for(int i=0;i<m;i++){
    	// total+=arr[p];
    	if(brr[p] == 1){
    		total+=arr[p];
    	}
    	else sakta+=arr[p];
    	p--;
    }
    crr[n-m] = sakta;
    while(p>=0){
    	if(brr[p] == 1) total+=arr[p];
    	crr[p] = crr[p+1];
    	if(brr[p] == 0) crr[p]+=arr[p];
    	if(brr[p+m] == 0){
    		crr[p] -= arr[p+m]; 
    	}
    	p--;
    }
    int maxi = 0;
   	// output(crr);
   	// cout << total << endl;
    for(int i=0;i<n;i++){
    	maxi = max(maxi,crr[i]);
    }
    cout << total + maxi << endl;
    return 0;
}