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
int longestSubArray(vi &arr,int n){
	int s = 0;
	int e = 1;
	int ans = INT_MIN;
	int cnt = 1;
	int sum = arr[0];
	while(s < n && e < n){
		if(sum <= arr[e]){
			cout << "here ";
			cout << e << " " << cnt << " " << sum << endl;
			sum+=arr[e];
			e++;
			cnt++;
			
		}
		else{
			ans = max(ans,cnt);
			// cout << "failed" << sum << " " << arr[e] << endl;
			while(s<=e && sum > arr[e]){
				cout << "mere ";
				cout << s << " " << cnt << " " << sum << endl;
				sum-=arr[s];
				cnt--;
				s++;
			}
		}
	}
	ans = max(ans,cnt);
	return ans;
}
signed main(){
	
    int n;
    cin >> n;
    vi arr(n);
    input(arr)
    sort(all(arr));
    // output(arr);
    // cout << endl;
    int sum = 0;
    // int cnt = longestSubArray(arr,n);
    int cnt = 0;
    for(int i=0;i<n;i++){
    	if(sum <= arr[i]){
    		cnt++;
    		sum+=arr[i];
    	}
    }
    cout << cnt << endl;
    return 0;
}