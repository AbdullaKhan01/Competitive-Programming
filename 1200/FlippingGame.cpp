#include<bits/stdc++.h>
#define mod 1000000007
#define mod2 998244353
#define ceil(a,b) ((a+b-1)/b)
#define ll long long
#define ll long long
#define lli long long int
#define vi vector<int>
#define vll vector<ll>
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define input(x) for(auto &a:x) cin >> a;
#define llmax(a,b) max(1LL*(a),1LL*(b))
#define output(x) for(auto a:x) cout << a <<" ";
#define FOR(i,n) for(i=0;i<n;i++)
using namespace std; 

int main(){
    ll n;
    cin >> n;
    vll arr(n);
    input(arr);
    if(n==1){
    	bool ans = arr[0]==0;
    	cout << ans << endl;
    	return 0;
    }
    vector<pair<int,int>>dp;
    ll totOne=0,totZero=0;
    for(int i=0;i<n;i++){
    	totOne+=arr[i]==1;
    	totZero+=arr[i]==0;
    	dp.push_back({totOne,totZero});
    }
    for(int i=0;i<n-1;i++){
    	for(int j=i;j<n;j++){
    		pair<int,int> ff = dp[i];
    		pair<int,int> ss = dp[j];
    		ll oneCount = ss.first-ff.first+(arr[i]==1);
    		ll zeroCount = ss.second-ff.second+(arr[i]==0);
    		// cout << i << "->" << j << " " << oneCount << " " << zeroCount << endl;
    		ans = max(ans,totOne-oneCount+zeroCount);
    	}
    }
    cout << ans << '\n';
    return 0;
}