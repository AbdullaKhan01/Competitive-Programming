#include<bits/stdc++.h>
#define mod 1000000007
#define mod2 998244353
#define ceil(a,b) ((a+b-1)/b)
#define floor(a,b)((a-b+1)/b)
#define fast_io() ios::sync_with_stdio(0);cin.tie(0);
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
/* 
for fast input output use printf and scanf;
*/
char flip(char a){
	if(a == 'W') return 'B';
	else return 'W';
}
signed main(){
	fast_io();
    ll tt;
    cin >> tt;
    while(tt--)
    {
        int n,m;
        cin >> n >> m;
        vector<string> arr(n);
        bool ans = true;
        for(int i=0;i<n;i++){
        	cin >> arr[i];
        	int cnt = 0;
        	for(int j=0;j<arr[i].size();j++){
        		if(arr[i][j] == 'U' || arr[i][j] == 'D') cnt++;
        	}
        	if(cnt % 2 != 0) ans = false;
        }
        // cout << ans << endl;
        char bit = 'W';
        if(ans){

        	for(int i=0;i<)

        }
        else{
        	cout << -1 << endl;
        }
    }
    return 0;
}