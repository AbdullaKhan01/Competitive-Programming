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
	
    int n,m;
    cin >> n >> m;
    int p = n - m;
    int mini,maxi;
	int l = p / m;
	int t = l+1;
	int k = p % m;
	int sum1 = (l * (l+1)) / 2 ;
	int sum2 = (t * (t+1))/2;
	// cout << l << " " << k << endl;

	// cout << sum1 << " " << sum2 << endl;
	int ans = (m * sum1) + (k * sum2);
	mini = ans;
    maxi = (p * (p+1)) / 2;
    cout << mini << " " << maxi << endl;
    return 0;
}