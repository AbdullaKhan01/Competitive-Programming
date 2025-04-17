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
	
    int a,b,c;
    cin >> a >> b >> c;
    if(a == 1 && c==1){
    	cout << a+b+c << endl;
    	return 0;
    }
    int ans = -1;
    if((b+c)>b*c){
    	ans = max(ans,a*(b+c));
    }
    else ans = max(ans,a*b*c);
    if(a+b>a*b) ans = max(ans,(a+b)*c);
    else ans = max(ans,a*b*c);
    cout << ans << endl;

    return 0;
}