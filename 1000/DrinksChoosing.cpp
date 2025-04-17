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
int arr[1001]={0};
/*NOT ACCEPTED*/
signed main(){

    ll n,k;
    cin >> n >> k;
    vi ans;
    int b = ceil(n,2),f = 0;
    while(n--){
    	int x;cin >> x;
    	arr[x]++;
    }
    rep(i,0,1001){
    	if(arr[i]!=0) ans.pb(arr[i]);
    }
    sort(rall(ans));
    // output(ans);
    // cout << endl;
    rep(i,0,ans.size()){
    	int need = ceil(ans[i],2);
    	if(b>=need){
    		b-=need;
    		f+=ans[i];
    	}
    	else{
    		f+=(b*2);
    	}
    }
    cout << f << endl;
    return 0;
}