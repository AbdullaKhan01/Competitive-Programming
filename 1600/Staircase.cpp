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
    vi arr(n);
    input(arr);
    arr.pb(0);
    vector<vector<int>>brr(n);
    int idx = 0;
    for(int i=0;i<n;i++)
    {
        if(arr[i] == 0) idx++;
        else brr[idx].push_back(arr[i]);
    }
    int sum = 0;
    for(int i=0;i<n;i++)
    {
        if(brr[i].empty()) continue;
        if(brr[i].size() % 2 == 0)
        {
            for(auto it:brr[i]) sum += (2*it);
        }
        else
        {
            int maxi = 0;
            for(int j=0;j<(int)brr[i].size();j++)
            {
                if(j % 2 == 0) maxi = max(maxi,brr[i][j]);
                sum += (2*brr[i][j]);
            }
            // cout << maxi 
            sum -= maxi;
        } 
    }
    cout << sum << endl;
}
signed main(){
	fast_io();
    // the question is that there are some broken steps
    // we can do two types of operations

    // either give one times money for two adj steps and save
    // money

    // or give 2*times money for two adj broken steps and 
    // save 1 day

    // we want the no of days to be minimum

    // and what is the minimum effort for this

    // can we not binary search on the number of days

    // ?

    // so the approach is that for any step which is not adjacent
    // to some broken step their effort is added to the 
    // minimum effort and 1 day is added for them

    // other wise 1 3 4 
    // -> 1 + 2*(3+4)
    // ->
    // -> 2*(1+3) + 4 
    // 

	// we can just do greedy
    ll tt;
    cin >> tt;
    while(tt--)
    {
        solve();
    }
    return 0;
}