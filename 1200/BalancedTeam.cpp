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
int longestSubArray(vi &arr,int n,int diff){
	int s = 0;
	int e = 1;
	int ans = INT_MIN;
	int cnt = 1;
	while(s < n && e < n){
		if(arr[e] - arr[s] <= 5){
			e++;
			cnt++;
		}
		else{
			ans = max(ans,cnt);
			while(s<=e && arr[e] - arr[s] > 5){
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
    input(arr);
    sort(all(arr));
    int diff = 5;

    int p = longestSubArray(arr,n,diff);
    cout << p << endl;
    return 0;
}