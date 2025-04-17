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
VERDICT -> ACCEPTED
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
        vi brr(n);
        rep(i,0,n)
        {
        	cin >> arr[i];
        }
        rep(i,0,n)
        {
        	cin >> brr[i];
        }
        vi idx(n);
        iota(all(idx),0);
        sort(all(idx),[&](int i,int j){
            return arr[i] + brr[i] > arr[j] + brr[j];
        });
        int S = 0;
        rep(i,0,n)
        {
            if(!(i&1))
            {
                S+=(arr[idx[i]]-1);
            }
            else
            {
                S-=(brr[idx[i]]-1);
            }
        }
        cout << S << endl;
    }
    return 0;
}