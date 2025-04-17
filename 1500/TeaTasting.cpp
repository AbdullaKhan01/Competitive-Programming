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
/*
	INTUITION -> EACH ELEMENT WILL GIVE SOME OF ITS
	CONTRIBUTION TO SOME ELEMENTS 

	TWO TYPES OF CONTRIBUTIONS : 
	1. FULL CONTRIBUTION -> = to element VALUE
	2. PARTIAL CONTRIBUTION -> given to 1 element only

	APPROACH -> give partial Contribution to all the 
	required elements 

	Propagate the Sum of element to the elements and 
	for each element extract out the contribution of them

	we can use prefix sum and lower_bound for this maybe

*/

signed main(){
	fast_io();
    ll tt;
    cin >> tt;
    while(tt--)
    {
        int n;
        cin >> n;
        vector<int> a(n),b(n);
        input(a);input(b);
        vi pref(n+1,0);
        for(int i=0;i<n;i++)
        {
        	pref[i+1] = b[i]+pref[i];
        }
        vi cnt(n+1),add(n+1);
        for(int i=0;i<n;i++)
        {
        	int j = lower_bound(pref.begin(),pref.end(),a[i]+pref[i]) - pref.begin() - 1;
        	cnt[i]+=1;
        	cnt[j]-=1;
        	add[j]+= a[i] - (pref[j] - pref[i]);
        }
        for(int i=0;i<n;++i)
        {
        	int ans = cnt[i]*b[i] + add[i];
        	cnt[i+1] += cnt[i];
        	cout << ans << ' ';
        }
        cout << '\n';
    }
    return 0;
}