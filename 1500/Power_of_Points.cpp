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

//VERDICT -> ACCEPTED
signed main(){
	fast_io();
    ll tt;
    cin >> tt;
    while(tt--)
    {
        int n;
        cin >> n;
        vector<pair<int,int>>arr(n);
        for(int i=0;i<n;i++)
        {
        	int x;
        	cin >> x;
        	arr[i] = {x,i};
        }
        sort(all(arr));
        vector<int> suff(n,0);
        vector<int> pref(n,0);
        for(int i=n-2;i>=0;i--)
        {
        	suff[i] += suff[i+1];
        	int forward = n - 1 - i;
        	suff[i] += abs(arr[i+1].first - arr[i].first) * forward;
        }
        for(int i=1;i<n;i++)
        {
        	pref[i] += pref[i-1];
        	int backward = i;
        	pref[i] += abs(arr[i].first - arr[i-1].first) * backward;
        }
        vector<int> store(n);
        for(int i=0;i<n;i++)
        {
        	store[arr[i].second] = pref[i] + suff[i] + n;
        }
        output(store);
        cout << endl;
    }
    return 0;
}