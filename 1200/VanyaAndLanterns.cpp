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
int solve(vector<double> &arr,int m,int l){
	bool flag = true;
	int n = arr.size();
	for(int i=1;i<n;i++){
		int p = arr[i] - arr[i-1];
        cout << p << " ";
		if(p > 2*m) flag = false;
	}
    cout << endl << endl << endl;
	return flag;
}
signed main(){
	
    int n;
    double l;
    cin >> n >> l;
    vector<double>arr;
    arr.pb(0);
    for(int i=0;i<n;i++){
        double lll;
        cin >> lll;
        arr.pb(lll);
    }
    arr.pb(l);
    sort(all(arr));
    output(arr);
    // cout << endl;
    n = arr.size();
    double s = 0 , e = l;
    double ans = 0;
    cout << fixed << setprecision(10);
    while(s<=e){
    	double mid = (s+e)/2;
    	
        cout << s << " " << e << endl;
        cout << mid ;
    	if(solve(arr,mid,l)){
    		cout << yes << endl;
    		ans = mid;
    		e = mid - 0.00000000001;
    	}
    	else{
    		cout << no << endl;
    		s = mid + 0.00000000001;
    	}
    }
    cout << ans << endl;
    return 0;
}