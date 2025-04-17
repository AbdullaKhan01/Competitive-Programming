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
        vi arr(n);
        input(arr);
        vector<int> suff(n+1,0);
        for(int i=n-1;i>=0;i--)
        {
            suff[i] = suff[i+1] + arr[i];
        }
        int ans = 0;
        int sum = arr[0];
        int idx = 1;
        for(int i=1;i<n;i++)
        {
            if(suff[i] < 0)
            {
                sum += arr[i] * idx;
            }
            else
            {
                ans += sum;
                idx++;
                sum = idx*arr[i];
            }
        }
        ans += sum;
        cout << ans << endl;
    }
    return 0;
}