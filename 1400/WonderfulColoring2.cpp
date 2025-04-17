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
	// test();
    ll tt;
    cin >> tt;
    while(tt--)
    {
        int n,k;
        cin >> n >> k;
        map<int,vector<int>> mp;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
        	cin >> arr[i];
            if(mp[arr[i]].size()<k){
                mp[arr[i]].push_back(i);    
            }
        	
        }
        
        int m = 0;
        for(auto it:mp){
            m+=it.second.size();
        }
        m -= m%k;        
        vector<int> ans(n,0);
        int color = 0;
        for(auto it:mp){

            for(auto jt:it.second){
                if(m==0) break;
                ans[jt] = ++color;
                color %= k;
                m--;
            }
        }
        output(ans);
        cout << endl;
        
    }
    return 0;
}