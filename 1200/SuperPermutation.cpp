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
        if(n==1){
        	cout << 1 << endl;
        	continue;
        }
        if(n%2!=0){
        	cout << -1 << endl;
        }
        else{
        	vi arr(n,0);
        	arr[0] = n;
        	for(int i=1;i<=n-1;i+=2) arr[i] = i;
        	for(int i=2;i<=n-2;i+=2) arr[i] = n-i;
        	output(arr);
 			cout << endl;       
        }
    }
    return 0;
}