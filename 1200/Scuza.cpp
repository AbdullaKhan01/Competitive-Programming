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
        int n,q;
        cin >> n >> q;
        int s = 0;
        vector<int> arr;
        for(int i=0;i<n;i++){
        	int x;
        	cin >> x;
        	s+=x;
        	arr.pb(s);
        }
        vector<int> brr(n);
        brr[0] = arr[0];
        for(int i=1;i<n;i++){
        	brr[i] = max(brr[i-1],abs(arr[i]-arr[i-1]));
        }
        
        vector<int> queries(q);
        input(queries);
        for(auto it:queries){
        	int ans = 0;
        	int st = 0 , e = arr.size()-1;
        	while(st <= e){
        		int mid = (st+e)/2;
        		if(it >= brr[mid]){
        			ans = arr[mid];
        			st = mid+1;
        		}
        		else{
        			e = mid-1;
        		}
        	}
        	cout << ans << " ";
        }
        cout << endl;
    }
    return 0;
}