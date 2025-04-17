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
	
    int n;
    cin >> n;
    vi arr(n);
    input(arr);
    sort(all(arr));
    vi small;
    vi ans;
    bool flag = true;
    bool flag2 = false;
    for(int i=0;i<n;i++){

    	if(arr[i]==100){
    		ans.pb(arr[i]);
    		continue;	
    	}
    	if(arr[i]==0){
    		ans.pb(arr[i]);
    		flag2 = true;
    		continue;
    	}
    	if(arr[i]>=0 && arr[i]<=9){
    		small.pb(arr[i]);
    	}
    	else if(arr[i]>=10 && arr[i]<=90){
    		if(arr[i]%10 == 0){
    			if(flag){
    				ans.pb(arr[i]);
    				flag = false;
    			}
    		}
    	}
    }
    cout << flag2 << endl;
    if((small.size() ==0 && flag2==false)){
    	ans.clear();
    }
    else{
    	ans.pb(small.back());
    }
    cout << ans.size() << endl;
    output(ans);
    return 0;
}