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
static bool cmp(pii &a,pii &b){
	if(a.first == b.first){
		return a.second <= b.second;
	}
	return a.first <= b.first;
}
signed main(){
	
    ll tt;
    cin >> tt;
    while(tt--)
    {
        int n;
        cin >> n;
        vector<pii> arr;
        for(int i=1;i<=n;i++){
        	int x;cin >> x;
        	arr.pb({x,i});
        }
        // sort(all(arr),[](pii&a,pii&b){return a.first<=b.first;});
        sort(all(arr),cmp);
        vector<pii> ans;
        int last = arr[n-1].first;
        int now = arr[n-1].second;
        for(int i=n-2;i>=0;i--){
        	if(arr[i].first == 0) continue;
        	if(last == 0){
        		last = arr[i].first;
        		now = arr[i].second;
        		continue;
        	}
        	int g = min(arr[i].first,last);
        	rep(_,0,g){
        		ans.pb({arr[i].second,now});
        	}	
        	if(arr[i].first >= last){
        		now = arr[i].second;
        	}
        	last = max(arr[i].first,last)-g;
        }
        cout << ans.size() << endl;
        for(auto it:ans){
        	cout << it.first << " " << it.second << endl;
        }
    }
    return 0;
}