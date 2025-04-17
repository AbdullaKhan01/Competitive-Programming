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

6 3
1 2 1 4 3 8

k = 3 k+pref[l]
2 3
0 2 5

1 -> 1
2 -> 2
3 -> 2
4 -> 0
5 -> 5
6 -> 0

*/
int solve2(vector<int> &a,int k)
{
    int n = a.size();
    vi pref(n+1);
    for(int i=0;i<n;i++)
    {
        pref[i+1] = pref[i] + a[i];
    }
    // iterate over all L

    // sum <= k 
    // pref[r] - pref[l-1] <= k

    // [ |    | ]
    // pref[r] <= k + pref[l-1];
    //          >

    int ans = 0;
    vector<int> dp(n+1,0);
    for(int i=n;i>=1;i--)
    {
        // i is l
        if(a[i-1] > k)
        {
            if(i+1<=n) dp[i] = dp[i+1];
            // cout << i << " NO " << dp[i] << endl;
            continue;
        }
        int finder = k + pref[i-1];
        int idx = upper_bound(all(pref),finder) - pref.begin();

        // cout << i << " " << idx << " " << endl;
        // if(idx > i) idx--;
        idx--;
        // subarray from i to idx is valid
        int contr = 0;
        contr += idx-i+1;
        // plus answer 
        if(idx + 2 <= n)
        {
            contr += dp[idx+2];
            // cout << i << " " << dp[idx+2] << endl;
        }
        // cout << i << " " << idx << " " << contr << endl;
        dp[i] = contr;
    }
    for(auto it:dp)
    {
        ans += it;
    }
    // cout << endl;

    return ans;
}
int correct(vector<int> &arr,int k){
    int n = arr.size();
    int cnt = 0;
    for(int i=0;i<n;i++)
    {
        int sum = 0;
        for(int j=i;j<n;j++)
        {
            sum += arr[j];
            if(sum > k) sum = 0;
            cnt += (sum != 0);
        }
    }
    return cnt;
}
void test(){
    srand(time(NULL));
    int cnt = 1;
    int MAX = 1e3;
    while(cnt <= MAX){
        int n = rand() % 10 + 1;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            arr[i] = rand() % 10 + 1;
        }
        int k = rand() % 10 + 1;
        int correctAns = correct(arr,k);
        int myAns = solve2(arr,k);
        if(correctAns != myAns){
            cout << n << " " << k << endl;
            output(arr);
            cout << endl;
            cout << correctAns << " " << myAns << endl;
            break;
        }
        cnt++;
    }
}
// 21 24
signed main(){
	fast_io();

    //test();
    ll tt;
    cin >> tt;
    while(tt--)
    {
        // solve();
        int n,k;
        cin >> n >> k;
        vi a(n);
        input(a);
        // cout << correct(a,k) << " ";
        cout << solve2(a,k) << endl;
        // cerr << "Hello" << endl;
    }
    return 0;
}