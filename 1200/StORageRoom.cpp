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
long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
signed main(){
	
    ll tt;
    cin >> tt;
    while(tt--)
    {
        int n;
        cin >> n;
        int b = binpow(2,30) - 1;
        vector<int> ans(n,b);
        vector<vector<int>>arr(n,vector<int>(n,0));
        for(int i=0; i < n; i++){
        	for(int j=0;j<n;j++){
        		cin >> arr[i][j];
        		if(i != j){
        			ans[i] &= arr[i][j];
        			ans[j] &= arr[i][j];
        		}
        	}
        }
        bool flag = true;
        for(int i=0;i<n;i++){
        	for(int j=0;j<n;j++){
        		if(i == j) continue;
        		if((ans[i] | ans[j]) != arr[i][j]){
        			flag = false;
        			break;
        		}
        	}
        }
        if(flag){
        	cout << yes << endl;
        	output(ans);
        	cout << endl;
        }
        else{
        	cout << no << endl;
        }
    }
    return 0;
}