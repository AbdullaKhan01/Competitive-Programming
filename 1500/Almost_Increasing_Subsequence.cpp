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

/* INTUITION -> what could be the method used ? greedy or dp
	
   OBSERVATION -> if l to r is sorted then answer 
   is min(2,l-r+1);

   let the the longest increasing subsequence
   bw l and r is [a1,a2,a3,a4,a5] then what
   property will it follow 
   if a2 < a1 then ok else a3 should be < a2


    TOOK HINT FROM THE EDITORIAL

    WILL CODE IT BY MYSELF
*/
//VERDICT -> ACCEPTED
signed main(){
	fast_io();
    ll tt=1;
    // cin >> tt;
    while(tt--)
    {
        int n,q;
        cin >> n >> q;
        vi arr(n);
        input(arr);
        vi pref(n,0);
        for(int i=1;i<n-1;i++)
        {
            pref[i] = pref[i-1];
            if(arr[i-1]>=arr[i] && arr[i]>=arr[i+1])
            {
                pref[i] +=1;
            }
        }
        while(q--)
        {
            int l,r;
            cin >> l >> r;
            l--,r--;
            int ans = r - l + 1;
            if(ans <= 2)
            {
                cout << ans << '\n';
                continue;
            }
            ans -= (pref[r-1]-pref[l]);
            cout << ans << '\n';
        }
    }
    return 0;
}