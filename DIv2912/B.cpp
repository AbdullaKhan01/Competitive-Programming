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
	
    int tt;
    cin >> tt;
    while(tt--)
    {
        int n,k,x;
        cin >> n >> k >> x;
        vi arr(n);
        input(arr);
        sort(all(arr));
        vi pref(n,0);
        pref[0] = arr[0];
        for(int i=1;i<n;i++){
        	pref[i] = pref[i-1]+arr[i];
        }
        vi suff(n,0);
        suff[n-1] = arr[n-1];
        for(int i=n-2;i>=0;i--){
        	suff[i] = suff[i+1]+arr[i];
        }
        // for(auto it:pref){
        // 	cout << it << " ";
        // }
        // cout << endl;
        // for(auto it:suff){
        // 	cout << it << " ";
        // }
        // cout << endl;
        int j = n-1;
        int zr = 0;
        int q = x;
        for(int i=n-1;i>=1;i--){
        	int yy = suff[i] - zr;
        	int tt = pref[i-1];
        	if(tt < yy && q>0){
        		// cout << "HERE" << endl;
        		// cout << i << " " << tt << " " << yy << endl;
        		zr += arr[j];
        		j--;
        	}
        	else{
        		// break;
        	}
        }
        // int sum = 0;
        // int j = n-1;
        // for(int i=n-1;i>=1;i--){
        // 	sum+=arr[i];
        // 	cout << pref[i-1] << " " << sum << endl;
        // 	if(pref[i-1] < sum){
        // 		cout << "HERE" << endl;
        // 		sum = sum - arr[j];
        // 		arr[j] = -1;
        // 		j--;
        // 	}
        // }
        // for(auto it:arr){
        // 	cout << it <<" ";
        // }
        // cout << endl;
        int final = 0;
        for(int k=j;k>=0;k--){
        	if(x>0){
        		final+=arr[k]*-1;
        		x--;
        	}
        	else{
        		final+=arr[k];
        	}
        }
        cout << final << endl;
    }
    return 0;
}