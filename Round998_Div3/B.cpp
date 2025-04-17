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
void solve()
{
	int n,m;
    cin >> n >> m;
    // int last = -1;
    int g = 0;
    vector<int> ans;
    bool flag = true;
    vector<vector<int>> cows(n,vector<int>(m,0));
    map<int,int> mp;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> cows[i][j];
        }
    }
    while(g < n){
    for(int i=0;i<n;i++){
        bool found = false;
        for(int j=0;j<m;j++){
            if(cows[i][j] == g){
                mp[g] = i;
                found = true;
            }
        }
            if(found){
                break;
            }
        }
        g++;
    }
    vector<int> p;
    set<int> st;
    for(auto it : mp){
        // cout << it.first << " " << it.second << endl;
        st.insert(it.second);
        p.push_back(it.second);
    }
    // output(p);cout << endl;
    int x = 0;
    int idx = 0;
    while(x < n * m){
        bool found = false;
        for(auto it : cows[p[idx]]){
            if(it == x){
                found = true;
                x++;
                break;
            }
        }
        if(found){
            idx = (idx+1)%p.size();
        }
        else{
            cout << -1 << endl;
            return ;
        }
    }
    for(auto it : p){
        cout << it+1 << " ";
    }
    cout << endl;
}
signed main(){
	fast_io();
    int tt = 1;
    cin >> tt;
    while(tt--)
    {
    	solve();
    }
    return 0;
}