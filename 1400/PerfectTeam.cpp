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
bool solve(int a,int b,int c,int mid){

	if(mid > a || mid > b) return false;
	int l = a - mid;
	int m = b - mid;
	return l+m+c >= mid;
}
signed main(){
	
    ll tt;
    cin >> tt;
    while(tt--)
    {
        int a,b,c;
        cin >> a >> b >> c;
        int s = 0 , e = max({a,b,c});
        int ans=0;
        while(s<=e){
        	int mid = (s+e)/2;
        	if(solve(a,b,c,mid)){
        		ans = mid;
        		s = mid+1;
        	}
        	else{
        		e = mid-1;
        	}
        }
        cout << ans << endl;
    }
    return 0;
}