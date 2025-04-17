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
#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std; 

int main(){
        ll n,k;
        cin >> n >> k;
        vll arr(n);
        input(arr);
        ll ans = INT_MAX;
        ll sum = 0;
        ll j = 1;
        FOR(i,k){
        	sum+=arr[i];
        }
        ans = sum;
        for(int i=k;i<n;i++){
        	sum-=arr[i-k];
        	sum+=arr[i];
        	// cout << sum << " " << i << endl;
        	if(sum < ans){
        		ans = sum;
        		j = i-(k-1) + 1;
        	}
        }
	        // 4 3
			// 2 2 6 1

        cout << j << endl;
    return 0;
}