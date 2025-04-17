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
        int n,k,x;
        cin >> n >> k >> x;
        vi arr(n);
        input(arr);
        sort(all(arr));
        int sum = 0;
        for(int k=n-1-x;k<n;k++){
        	sum+=arr[k];
        }
        vi pref(n,0),suff(n,0);
        pref[0] = arr[0];
        suff[n-1] = arr[n-1];
        int ans = INT_MIN;
        for(int i=1;i<n;i++){
        	pref[i] = pref[i-1] + arr[i];
        }
        for(int i=n-2;i>=0;i--){
        	suff[i] = suff[i+1] + arr[i];
        }
        if(x>=n){
        	if(k>=n){
        		cout << 0 << endl;
        	}
        	int sum = 0;
        	for(int i=0;i<k;i++){
        		sum+=arr[i];
        	}
        	cout << sum * -1 << endl;
        }
        else{
        	int pp = 0;
        	int j = n-1;
        	for(int i=n-1;i>=x;i--){
        		if(k == 0) break;
        		int backSum = pref[i-x];
        		int frontSum = suff[i-x+1] - pp;
        		if(backSum < frontSum && k){
        			pp += arr[j];
        			j--;
        			int xx = (backSum - arr[i-x]) - (frontSum-arr[j]+arr[i-x]);
        			ans = max(ans,xx);
        			k--;
        		}
        	}
        	int sum = 0;
        	int 
        	if(ans < 0){
        		if(k>=n){
        			cout << 0 << endl;
        		}
        		else{
        			cout << ans << endl;
        		}
        	}
        	else cout << ans << endl;
        }
    }
    return 0;
}