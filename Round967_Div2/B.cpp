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
    int n;
    cin >> n;
    if(n == 1)
    {
        cout << 1 << endl;
        return ;
    }
    if(n % 2 == 0)
    {
        cout << -1 << endl;
    }
    else
    {
        vector<int> p(n);
        p[0] = 1;
        p[n-1] = 2;
        int num = 3;
        int idx = n-2;
        while(num <= n)
        {
            p[idx--] = num;
            num += 2;
        }
        num = 4;
        idx = 1;
        while(num <= n)
        {
            p[idx++] = num;
            num += 2;
        }
        output(p);
        cout << endl;
    }
}
signed main(){
	fast_io();
    ll tt;
    cin >> tt;
    while(tt--)
    {
        solve();
    }
    return 0;
}