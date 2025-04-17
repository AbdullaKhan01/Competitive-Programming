#include<bits/stdc++.h>
#define mod 1000000007
#define mod2 998244353
#define ceil(a,b) ((a+b-1)/b)
#define ll long long
#define int long long int
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
int maximumSumSubArray(vi& arr,int n){
	int best = 0, sum = 0;
 	for(int k = 0; k < n-1; k++) {
		sum = max(arr[k],sum+arr[k]);
		best = max(best,sum); 
	}
	return best;	
}
signed main(){
	
	ll tt;
	cin >> tt;
	while(tt--)
	{
	    int n;
	    cin >> n;
	    vi arr(n);
	    input(arr);
	    // int sum = 0;
	    int sum = accumulate(arr.begin(),arr.end(),1LL*0);
	    // int sum = 0;
	    // for(int i=0;i<n;i++){
	    // 	sum+=arr[i];
	    // }
	    int p = maximumSumSubArray(arr,n);
	    // cout << sum << " " << p << endl;
	    cout << (p>=sum?no:yes) << endl;
	}
    
    return 0;
}