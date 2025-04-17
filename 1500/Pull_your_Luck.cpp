
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
// VERDICT -> ACCEPTED
int debug(int n,int x,int p)
{
    int a = min(2*n,p);
    for(int i=1;i<=a;i++)
    {
        int g = (i*(i+1))/2;
        g+=x;
        if(g % n == 0) return i;
    }
    return -1;
}
signed main(){
    fast_io();
    // ll tt;
    // cin >> tt;
    // while(tt--)
    // {
    //     int n,x,p;
    //     cin >> n >> x >> p;
    //     cout << (debug(n,x,p)!=-1?yes:no) << endl;
    // }
    for(int i=1;i<=60;i++)
    {
        int a = (i*(i+1))/2;
        cout << a % 14 << " \n"[i%(2*14)==0];
    }
    return 0;
}



