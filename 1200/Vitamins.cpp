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
	    vector<int> arr(8,INT_MAX);
	    int ans = INT_MAX;
	    while(n--){
	    	int price;string vit;
	    	cin >> price >> vit;
	    	int p = 0;
	    	for(int i=0;i<vit.size();i++){
	    		if(vit[i] == 'A') p |= (1<<2);
	    		if(vit[i] == 'B') p |= (1<<1);
	    		if(vit[i] == 'C') p |= (1<<0);
	    	}
	    	arr[p] = min(arr[p],price);
	    }
	    // output(arr);
	    // cout << endl;
	    ans = min(ans,arr[1] + arr[2] + arr[4]);
	    for(int i=1;i<7;i++){
	    	for(int j=1;j<8;j++){
	    		int p = i | j;
	    		// cout << p << endl;
	    		if(p == 7){
	    			// cout << "here" << i << j << endl;
	    			ans = min(ans,arr[i] + arr[j]);
	    		}
	    	}
	    }
	    // ans = min(ans,arr[1]+arr[2]+arr[4]);
	    // ans = min(ans,arr[4] + arr[3]);
	    // ans = min(ans,arr[2] + arr[5]);
	    // ans = min(ans,arr[1] + arr[6]);
	    // ans = min(ans,arr[6] + arr[3]);
	    // ans = min(ans,arr[5] + arr[3]);
	    // ans = min(ans,arr[5] + arr[6]);
	    // ans = min(ans,arr[7]);
	    ans = min(ans,arr[7]);
	    if(ans == INT_MAX){
	    	cout << -1 << endl;
	    }
	    else cout << ans << endl;
	    return 0;
	}