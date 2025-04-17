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
signed main(){
	fast_io();
    ll tt;
    cin >> tt;
    while(tt--)
    {
        int n;
        cin >> n;
        vector<vector<int>>universities(n+1);
        vector<int> u(n),skills(n);
        rep(i,0,n){
        	cin >> u[i];
        }
        rep(i,0,n){
        	cin >> skills[i];
        }
        rep(i,0,n){
        	universities[u[i]].push_back(skills[i]);
        }
        for(int i=1;i<=n;i++){
           sort(rall(universities[i]));
        }
        for(auto i=1;i<=n;i++){
            vector<int> row = universities[i];
            int gg = row.size();
            for(int go=1;go<gg;go++){
               universities[i][go] += universities[i][go-1];
            }  
        }
        vector<int> ans(n,0);
         rep(i,1,n+1){
            int k = universities[i].size();
            for(int j=1;j<=k;j++){
               int index = k/j * j;
               ans[j-1] += universities[i][index-1];
            }
        }
        output(ans);
        cout << endl;
        
    }
    return 0;
}