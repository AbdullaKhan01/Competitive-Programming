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
// INTUITION -> just make prefix and suffix array and then do 
// accordingly just remove every shop and build an array
// then just find the min element of the array and print the freq

//VERDICT -> ACCEPTED


signed main(){
    fast_io();
    ll tt;
    cin >> tt;
    while(tt--)
    {
        int n,m,d;
        cin >> n >> m >> d;
        vi arr(m);
        for(int i=0;i<m;i++)
        {
            cin >> arr[i];
        }
        int tot = 0;
        int prev = 0;
        vi dp1(m+1);
        vector<bool> sta(m,0);
        if(arr[0] != 1) tot++,prev=1;
        for(int i=0;i<m;i++)
        {

            int l = arr[i]-1-prev;
            tot += (l/d) + 1;
            dp1[i] = tot;
            prev = arr[i];
        }
        tot += (n-prev)/d;
        dp1[m] = tot;
        vi dp2(m,0);
        for(int i=m-1;i>=1;i--)
        {
            dp2[i] = tot - dp1[i] + 1;
        }
        dp2[0] = tot;
        
        vi ans(m);

        ans[0] = 1 + dp2[1] + max(0LL,(arr[1] - 2))/d;

        for(int i=1;i<m-1;i++)
        {
            int gig = arr[i-1];
            int add = (max(0LL,arr[i+1]-1-gig))/d;
            ans[i] =  dp1[i-1] + dp2[i+1] + add;
        }
        
        ans[m-1] = dp1[m-2];
        int gig = arr[m-2];
        ans[m-1] += (max(0LL,n-gig))/d;

        int l = *min_element(all(ans));
        int f = count(all(ans),l);
        cout << l << " " << f << endl;
    }
    return 0;
}