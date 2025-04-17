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
int n,k;
vector<int>arr;
vector<int>pref;
void init()
{
    for(int i=0;i<n;i++)
    {
        pref[i+1] = pref[i] + arr[i];
    }
}
int cost(int left,int right)
{
    //this function returns cost for moving all the
    //elements inside the window left,right in O(logN)

    // move all elements before left to left
    // how
    // suppose a1,a2,a3 are before left
    // cost = left - a1 + left - a2 + left - a3;
    //      = 3*left - (a1+a2+a3);
    // move all elements after right to right
    // suppose a8,a9,a10 are after right
    // cost = a8 - right + a9 - right + a10 - right 
    //      = (a8 + a9 + a10) - 3*right;


    // to find number of elements > right 
    // == n - no of elements <= right
    // == n - upper_bound of (right)

    // to find number of elements < left
    // == lower_bound of left

    int n1 = n - (upper_bound(arr.begin(),arr.end(),right) - arr.begin());
    int n2 = lower_bound(arr.begin(),arr.end(),left) - arr.begin();


    int sum_before = pref[n2];
    int sum_after = pref[n] - pref[n-n1];

    int total_cost = (n2*left - sum_before) + (sum_after - n1*right);

    return total_cost;    
}
bool check(int x)
{
    for(int i=0;i<n;i++)
    {
        int l1 = max(0LL,arr[i]-x);
        int r1 = arr[i];

        int l2 = arr[i];
        int r2 = min(arr.back(),arr[i]+x);

        int c1 = cost(l1,r1);
        int c2 = cost(l2,r2);

        if(min(c1,c2) <= k){
            return true;  
        } 
    }
    return false;
}
signed main(){


    fast_io();
    
    cin >> n >> k;
    arr.resize(n);
    pref.resize(n+1);
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    sort(all(arr));
    init();
    int s = 0 , e = arr.back() - arr[0];
    int ans = e;
    while(s <= e)
    {
        int mid = (s+e)/2;
        if(check(mid))
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;  
        }
    } 
    cout << ans << endl;
    return 0;
}