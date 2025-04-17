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
int C(int n, int k) {
    int res = 1;
    for (int i = n - k + 1; i <= n; ++i)
        res *= i;
    for (int i = 2; i <= k; ++i)
        res /= i;
    return res;
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
        sort(all(arr));
        int prev = arr[0];
        int cnt = 1;
        int i = 1;
        int sum = 0;
        while(arr[i]==arr[i-1] && i<n){
        	i++,cnt++;
        }
        int ans = 0;
        int curr;
        if(i<n) curr = arr[i];
        else curr = arr[0];
       	sum+=cnt;
        int cnt2 = 1;
        for(i=i+1;i<n;i++){
        	if(arr[i]==arr[i-1]){
        		cnt2++;
        	}
        	else{
        		if(cnt >=2){
        			ans+= cnt2 * C(cnt,2);
        		}
        		if(cnt2 >=2){
        			ans+= (C(cnt2,2) * sum) + C(cnt2,3);
        		}
        		prev = curr;
        		curr = arr[i];
        		sum+=cnt2;
        		cnt2 = 1;
        	}
        }
        if(prev == curr){
        	ans+= C(cnt,3);
        }
        else{
        	if(cnt >=2){
        			ans+= cnt2 * C(cnt,2);
        	}
        	if(cnt2 >=2){
        			ans+= (C(cnt2,2) * sum) + C(cnt2,3);
        	}
        }
        cout << ans << endl;
    }
    return 0;
}