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
int solve(vi &arr,int time,int maxi,int secondMaxi,int sum){
	int flag = 0;
	int n = arr.size();
	for(int i=0;i<n;i++){
		int p = arr[i];
		int make = maxi;
		int ele = n - 1;
		if(p == maxi) make = secondMaxi;
		int needed = make * ele-1;
        int x = 0;
		if(p > needed){
            int t = p - needed;
            int d = ceil(t,n-1) * n-1;
            x = t - d;
        }
        else if(p<needed){
            x = needed - p;
        }
        else{
            continue;
        }
        if(time < x){
            flag = 1;
            break;
        }
        else if(time > x){
            flag = -1;
        }
	}
    return flag;
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
        int m = arr[n-1],p = arr[n-2];
        int sum = accumulate(all(arr),0);
        // cout << sum << endl;
        int s = 0 , e = 1e9;
        int ans = 0;
        while(s <= e){
        	int mid = (s+e)/2;
        	int g = solve(arr,mid,m,p,sum);
            cout << s << " " << e << " " << mid << " " << g << endl;
        	if(g == 0){
        		ans = mid;
        		e = mid-1;
        	}
        	else if(g == -1){
        		e = mid - 1;
        	}
        	else{
        		s = mid + 1;
        	}
        }
        cout << ans << endl;
    }
    return 0;
}