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
        int n,k;
        cin >> n >> k;
        int num = 0;
        int cnt = 1;
        vector<int> ans;
        int sum = 0;
        int bit = 0;
        for(int i=0;i<32;i++)
        {
            int g = num | (1<<i);
            if((k - g) >= 0)
            {
                int ele = 1<<i;
                sum += ele;
                ans.pb(ele);
                bit++;
                num = g;
            }
            // else break;
            cnt++;
        }
        int remSum = k - sum;
        int remNos = n - bit;
        for(int i=0;i<remNos - 1 ;i++)
        {
            ans.pb(1);
            remSum--;
        }       
        ans.pb(remSum);
        output(ans);
        cout << endl;   
    }
    return 0;
}