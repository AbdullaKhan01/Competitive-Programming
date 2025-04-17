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
        int n;
        cin >> n;
        int s = 2 , e = 2e9;
        int ans=2;
        while(s<=e){
        	int mid = (s+e)/2;
        	int z = mid-1;
        	int sum = (z*(z-1))/2;
        	if(sum <= n){
        		ans = mid;
        		s = mid+1;
        	}
        	else{
        		e = mid-1;
        	}
        }
        ans--;
        int k = ans * (ans-1) / 2;
        cout << ans+(n-k) << endl;
    }
    return 0;
}