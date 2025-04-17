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
    /*
    given a & b arrays
    beauty = no of indices such that ai > bi
    can we make beauty == 2;
    4 5 6 7 3 4 2 2 9
    
    2 2 3 4 4 5 6 7 9
    2 3 6 7 9 2 2 1 1
    
    2 2 3 6 7 9 2 1 1

    0 0 0 0 0 0 1 1 1

    1 1 2 2 3 3 6 7 9

    1 1 1 1 1 1 0 0 0

    2 3 4
    2 4 1
    1 2 4


    algo ->
    1. find minimum beauty 
    2. find maximum beauty
    compute the greater array while computing min beau

    if x >= min && x <= max
    yes 
    else 
    no
    if(yes)
    {
        take the last x elements of the greater array
        and put it in front of the smallest elements in 
        a 
        put the remaining elements in front of any element
        in a
    }




    */

    ll tt;
    cin >> tt;
    while(tt--)
    {
        int n,x;
        cin >> n >> x;
        vector<pii> a;
        for(int i=0;i<n;i++)
        {
            int x;
            cin >> x;
            a.pb({x,i});
        }
        sort(all(a));
        //9 5
        // 4 5 6 7 9 2 2 3 4
        // 2 3 6 7 9 2 2 1 1

        // cout << endl;
        multiset<int> ms;
        for(int i=0;i<n;i++)
        {
            int x;
            cin >> x;
            ms.insert(x);
        }
        int idx = 0;
        int idx2 = 0;
        int max = 0;
        int min = 0;
        // vi g;
        for(auto it:ms)
        {
            if(it < a[idx].first)
            {
                idx++;
                max++;
            }
            if(it >= a[idx2].first)
            {
                // g.pb(it);
                min++;
                idx2++;
            }
        }
        min = n - min;
        if(x >= min && x <= max)
        {
            cout << yes << endl;
            vector<int> ans(n);
            int idx = n-1;
            int k = n-x;
            while(x--)
            {
                auto it = ms.begin();
                ans[a[idx--].second] = *it;
                ms.erase(it);
            }
            idx = 0;
            while(k--)
            {
                auto it = ms.begin();
                ans[a[idx++].second] = *it;
                ms.erase(it);
            }

            output(ans);
            cout << endl;
        }
        else
        {
            cout << no << endl;
        }

    }
    return 0;
}