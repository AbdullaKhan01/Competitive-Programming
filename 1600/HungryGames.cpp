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
void solve2()
{
    int n,k;
    cin >> n >> k;

    vi a(n);
    vi pref(n+1);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
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
            // cout << i << " NO" << endl;
            if(i+1<=n) dp[i] = dp[i+1],ans+=dp[i];
            continue;
        }
        int finder = k + pref[i-1];
        int idx = upper_bound(all(pref),finder) - pref.begin();

        // cout << i << " " << idx << " " << endl;
        // if(idx > i) idx--;
        idx--;
        // subarray from i to idx is valid
        ans += idx-i+1;
        // plus answer 
        if(idx + 2 <= n)
        {
            ans += dp[idx+2];
        }
        // cout << i << " " << idx << " " << ans << endl;
        dp[i] = ans;
    }
    // for(auto it:dp)
    // {
    //     cout << it << " ";
    // }
    // cout << endl;
    cout << ans << "\n";
}

void solve()
{
    int n,k;
    cin >> n >> k;
    vi t(n+1,0);
    vi dp(n+1,0);
    vi pref(n+1,0);


    for(int i=1;i<=n;++i) 
    {
        cin >> t[i];
        pref[i] = pref[i-1] + t[i];
    }
    int ans = 0;
    // iterate on all L
    for(int i=n;i>=1;i--)
    {
        if(t[i] > k)
        {
            // ans += dp[i-1];
            dp[i] = i;
            continue;
        }
        // for every r 
        // first ans
        // sum <= k
        // pref[r] - pref[l-1] <= k
        // pref[l-1] >= pref[r] - k
        // lower_bound on pref[r]-k
        int idx = lower_bound(pref.begin(),pref.end(),pref[i]-k) - pref.begin();
        int first_ans = i - idx;
        dp[i] += first_ans;
        // second ans 
        // sum >= 2k
        // pref[r] - pref[l-1] >= 2k
        // pref[r] - 2k >= pref[l-1]
        // pref[l-1] <= pref[r] - 2k
        // (upper_bound on pref[r] - 2k) - 1
        int idx2 = upper_bound(pref.begin(),pref.end(),pref[i]-(2*k)) - pref.begin() - 1;

        cout << i << " " << first_ans << " " << idx << " " << idx2 << endl; 
        // if(idx2 >= 0)
        // {
        //     dp[i] += dp[idx2+1];
        // }
        if(idx >= 0)
        {
            dp[i] += dp[idx];
        }
        ans += dp[i];
    }

    for(auto it:dp)
    {
        cout << it << " ";
    }
    cout << endl;
    cout << ans << "\n";
}
signed main(){
	fast_io();
    ll tt;
    cin >> tt;
    while(tt--)
    {
        // solve();
        solve2();
    }
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// #define endl "\n"
// #define int long long
// int mod = 1e9+7;

// //int binpow(int a , int b, int mod){ int result = 1;  while(b){if(b%2==1){result = ((result % mod) *(a % mod )) % mod;}a = ((a % mod )*(a%mod)% mod); b = b/2;}return result;}
// // template<typename T>void print(T &a){ for(auto it: a){ cout<<it<<" ";}cout<<endl;}
// // template<typename k,typename v>void print(map<k , v> &mpp){for(auto it: mpp){cout<<"{"<<it.first<<" -> "<<it.second<<"}"<<endl;}}

// int arr[100100];
// void solve(){
//     int n,k;
//     cin>>n>>k;
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }

//     map<int,int>mpp;

//     int ans = INT_MAX;

//     for(int i=0;i<n;i++){

//         mpp[arr[i]]++;

//         if(i>=k){
//             if(mpp.count(arr[i-k])==1){
//                 mpp[arr[i-k]]--;
//                 if(mpp[arr[i-k]]==0){
//                     mpp.erase(arr[i-k]);
//                 }
//             }
//         }

//         if(i>=k-1){
//             int size = mpp.size();
//             ans = min(ans,size);
//         }
//     }
//     cout<<ans<<endl;
// }  
 

// signed main(){
//     ios::sync_with_stdio(0); 
//     cin.tie(0); cout.tie(0);

//     int t = 1;
//     cin>>t;

//     while(t--){
//         solve();
//     }
//     return 0;
// }

// #include <iostream>
// #include <bits/stdc++.h>
// #define int long long int
// using namespace std;
// signed main(){
//     int t;cin>>t;
//     while(t--){
//       int n;cin>>n;
//       string s;cin>>s;
//       map<int,int>m;
//       int cnt=0;
//       vector<char>v(n+1,'f');

//       // ln(1e6) = 14 = Time for accessing map element
//       // 1e6 operation -> creating of vector 
//       // 1e6 * 14 operation -> for filling the map(first for loop)
//       // 1e6 * 14 * 14 operations in the second for loop
//       // TOTAL TIME = 1e6 + 1e6 * 14 + 1e6 * 14 * 14      
//       // = 1e6(1 + 14 + 14 * 14) 
//       // = 1e6 * 211 = 211000000 = 2.11 secs

//       // so time >= 2secs

//       // thats why TLE

//       for(int i=0;i<s.size();i++){
//             if(s[i]=='0'){
//                 m[i+1]=0;
//                 v[i+1]='t';
//             }
//       }
//       for(int i=1;i<=n;i++){
//         for(int u=i;u<=n;u+=i){
//             if(v[u]=='t'&&m[u]==0){
//                 cnt+=i;
//                 m[u]=1;
//             }
//             else if(v[u]=='f'){
//                 break;
//             }
//             else if(v[u]=='t'&&m[u]==1){
//                 continue;
//             }
//         }
//       }
//       cout<<cnt<<endl;
//     }		
// }

// #include<bits/stdc++.h>
// #define mod 1000000007
// #define mod2 998244353
// #define ceil(a,b) ((a+b-1)/b)
// #define floor(a,b)((a-b+1)/b)
// #define fast_io() ios::sync_with_stdio(0);cin.tie(0);
// #define ll long long
// #define int long long
// #define vi vector<int>
// #define all(x) (x).begin(),(x).end()
// #define rall(x) (x).rbegin(),(x).rend()
// #define input(x) for(auto &a:x) cin >> a;
// #define output(x) for(auto a:x) cout << a <<" ";
// #define rep(i,a,n) for(int i=(a);i<n;i++)
// #define pb push_back
// #define ppb pop_back
// #define pf push_front
// #define ppf pop_front
// #define ff first
// #define ss second
// #define si set<int>
// #define pii pair<int,int>
// #define mii map<int,int>
// #define msi map<string,int>
// #define yes "YES"
// #define no "NO"
// #define endl '\n'
// using namespace std; 
// /* 
// for fast input output use printf and scanf;
// */
// signed main(){
// 	fast_io();
//     ll tt;
//     cin >> tt;
//     while(tt--)
//     {
//         int n;
//         cin >> n;
//         string s;
//         cin >> s;
//         int ans = 0;
//         vector<int> cnt(n+1,INT_MAX);
//         for(int i = 1 ; i <= n ;i++)
//         {
//         	if(s[i-1] == '0')
//         	{
//         		int j = i;
//         		while(j <= n && s[j-1] == '0')
//         		{
//         			cnt[j] = min(cnt[j],i);
//         			j += i;
//         		}
//         	}
//         }
//         for(int i=1;i<=n;i++)
//         {
//         	if(s[i-1] == '0')
//         		ans += cnt[i];
//         }
//         cout << ans << endl;
//     }
//     return 0;
// }


// #include <bits/stdc++.h>

// using namespace std;
// #define ll long long int
// #define nline "\n"

// ll p = (long long int)1e9 + 7;

// ll sum = 0LL;
// ll squareSum = 0LL;
// ll cnt = 0LL;

// map<ll, ll> frequencyMap;
// multiset<pair<ll, ll>> setfre;

// multiset<ll> low;
// multiset<ll> high;

// ll mod_pow(ll a, ll b, ll p)
// {

//     if (b == 0)
//         return 1;
//     if (b % 2)
//         return a * mod_pow(a, b - 1, p) % p;
//     else
//     {
//         ll temp = mod_pow(a, b / 2, p);
//         return (temp * temp) % p;
//     }
// }
// ll mod_mul(ll a, ll b, ll p)
// {
//     return (a % p) * (b % p) % p;
// }

// ll mod_div(ll a, ll b, ll p)
// {
//     return mod_mul(a, mod_pow(b, p - 2, p), p);
// }

// ll mod_add(ll a, ll b, ll p)
// {
//     return (a % p) + (b % p) % p;
// }

// ll mod_sub(ll a, ll b, ll p)
// {
//     a = (a % p) - (b % p) % p;
//     if (a < 0)
//         a = mod_add(a, p, p);
//     return a;
// }
// void balance()
// {
//     if (high.size() > low.size())
//     {
//         low.insert(*high.begin());
//         high.erase(high.begin());
//     }

//     while (low.size() - high.size() > 1)
//     {
//         ll x = *low.rbegin();
//         high.insert(*low.rbegin());
//         low.erase(low.find(x));
//     }
// }

// void insert(ll x)
// {
//     sum += x;
//     squareSum += pow(x, 2);
//     cnt++;

//     // Mode
//     auto itr = setfre.find(make_pair(frequencyMap[x], x));
//     if (itr != setfre.end())
//     {
//         setfre.erase(itr);
//     }
//     frequencyMap[x]++;
//     setfre.insert(make_pair(frequencyMap[x], x));

//     // Median
//     if (low.empty())
//     {
//         low.insert(x);
//     }
//     else if (x > *low.rbegin())
//     {
//         high.insert(x);
//     }
//     else
//     {
//         low.insert(x);
//     }

//     balance();
// }

// void remove(int x)
// {
//     sum -= x;
//     squareSum -= pow(x, 2);
//     cnt--;

//     // Mode
//     auto itr = setfre.find(make_pair(frequencyMap[x], x));
//     if (itr != setfre.end())
//     {
//         setfre.erase(itr);
//     }
//     frequencyMap[x]--;
//     setfre.insert(make_pair(frequencyMap[x], x));

//     // Median
//     if (low.find(x) != low.end())
//         low.erase(low.find(x));
//     else if (high.find(x) != high.end())
//         high.erase(high.find(x));

//     balance();
// }

// ll getMean()
// {

//     if (cnt == 0)
//         return -1;

//     return mod_div(sum, cnt, p);
// }

// double getVariance()
// {
//     if (cnt == 0)
//         return -1;
//     return mod_sub(mod_div(squareSum, cnt, p), pow(getMean(), 2), p);
// }

// ll getMedian()
// {
//     if (cnt == 0)
//         return -1;

//     if ((low.size() + high.size()) % 2)
//         return *low.rbegin();
//     else
//     {
//         return (mod_div(*low.rbegin() + *high.rbegin(), 2.0, p));
//     }
// }

// ll getMode()
// {
//     if (cnt == 0)
//         return -1;

//     int x = setfre.rbegin()->first;
//     for (auto itr : setfre)
//     {
//         if (itr.first == x)
//             return itr.second;
//     }
//     return setfre.rbegin()->second;
// }

// void solve()
// {
    
//     sum = 0,cnt=0,squareSum = 0;
//     frequencyMap.clear(),setfre.clear();
//     low.clear(),high.clear();
//     int q;
//     cin >> q;

//     while (q--)
//     {
//         string query;
//         cin >> query;

//         if (query == "insert")
//         {
//             ll x;
//             cin >> x;
//             insert(x);
//         }
//         else if (query == "remove")
//         {
//             ll x;
//             cin >> x;
//             remove(x);
//         }
//         else if (query == "getMean")
//             cout << getMean() << nline;
//         else if (query == "getMedian")
//             cout << getMedian() << nline;
//         else
//             cout << getMode() << nline;
//     }

//     // resetting the value for next test case
//     sum = 0LL;
//     cnt = 0LL;
//     frequencyMap.clear();
//     setfre.clear();
//     low.clear();
//     high.clear();
// }

// int main()
// {

//     // freopen("../input.txt", "r", stdin);

//     // freopen("../output.txt", "w", stdout);

//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);

//     int t;
//     cin >> t;
//     while (t--)
//         solve();

//     return 0;
// }
// CFFTD

/*

 Concept
 *

 Framework
 *

 Form
 *

 Tactics
 *

 Debugging
 *

*/

// #include<bits/stdc++.h>
// #define mod 1000000007
// #define mod2 998244353
// #define ceil(a,b) ((a+b-1)/b)
// #define floor(a,b)((a-b+1)/b)
// #define fast_io() ios::sync_with_stdio(0);cin.tie(0);
// #define ll long long
// #define int long long
// #define vi vector<int>
// #define all(x) (x).begin(),(x).end()
// #define rall(x) (x).rbegin(),(x).rend()
// #define input(x) for(auto &a:x) cin >> a;
// #define output(x) for(auto a:x) cout << a <<" ";
// #define rep(i,a,n) for(int i=(a);i<n;i++)
// #define pb push_back
// #define ppb pop_back
// #define pf push_front
// #define ppf pop_front
// #define ff first
// #define ss second
// #define si set<int>
// #define pii pair<int,int>
// #define mii map<int,int>
// #define msi map<string,int>
// #define yes "YES"
// #define no "NO"
// #define endl '\n'
// using namespace std; 
// /* 
// for fast input output use printf and scanf;
// */
// long long binpow(long long a, long long b, long long m=1e9+7) {
//     a %= m;
//     long long res = 1;
//     while (b > 0) {
//         if (b & 1)
//             res = res * a % m;
//         a = a * a % m;
//         b >>= 1;
//     }
//     return res;
// }
// struct dash
// {
//     //mean
//     int sum = 0;
//     int cnt = 0;
//     int inv2 = binpow(2,mod-2);
//     //mode
//     map<int,int> mp;
//     multiset<pair<int,int>> f;

//     //median
//     multiset<int> low,high;
//     void balance()
//     {
//         if(low.size() < high.size())
//         {
//             int val = *high.begin();
//             high.erase(high.find(val));
//             low.insert(val);
//         }
//         if(low.size() > high.size() + 1)
//         {
//             int val = *low.rbegin();
//             low.erase(low.find(val));
//             high.insert(val);
//         }
//     }
//     void insert(int x)
//     {
//         //mean
//         sum += x;
//         cnt++;

//         //mode
//         int freq = mp[x];
//         if(f.find(make_pair(freq,-x))!=f.end())
//         {
//             f.erase(f.find(make_pair(freq,-x)));
//         }
//         mp[x]++;
//         f.insert({mp[x],-x});

//         //median
//         if(low.empty()) low.insert(x);
//         else if(x <= *low.rbegin())
//         {
//             low.insert(x);
//         }else{
//             high.insert(x);
//         }
//         balance();
//     }
//     void remove(int x)
//     {
//         //mean
//         sum -= x;
//         cnt--;

//         //mode
//         int freq = mp[x];
//         if(f.find(make_pair(freq,-x))!=f.end())
//         {
//             f.erase(f.find(make_pair(freq,-x)));
//         }
//         mp[x]--;
//         if(mp[x])f.insert({mp[x],-x});

//         //median
//         if(high.find(x) != high.end())
//         {
//             high.erase(high.find(x));
//         }
//         else if(low.find(x) != low.end())
//         {
//             low.erase(low.find(x));
//         }
//         balance();
//     }
//     int getMean()
//     {
//         if(cnt == 0) return -1;
//         int l = binpow(cnt,mod-2);
//         return ((sum%mod) * l)%mod;
//     }
//     int getMedian()
//     {
//         if(cnt == 0) return -1;
//         if(cnt%2 != 0)
//         {
//             int val = *low.rbegin();
//             return val%mod;
//         }
//         else 
//         {
//             int val = *low.rbegin() + *high.begin();
//             return ((val%mod) * inv2)%mod;
//         }
//     }
//     int getMode()
//     {
//         if(cnt==0) return -1;
//         return abs(f.rbegin()->second);
//     }
// };
// signed main(){
//     fast_io();
//     ll tt;
//     cin >> tt;
//     while(tt--)
//     {
//         int q;
//         cin >> q;
//         dash d;
//         while(q--)
//         {
//             string s;
//             cin >> s;
//             if(s == "insert")
//             {
//                 int x;
//                 cin >> x;
//                 d.insert(x);
//             }
//             else if(s == "remove")
//             {
//                 int x;
//                 cin >> x;
//                 d.remove(x);
//             }
//             else if(s == "getMean")
//             {
//                 cout << d.getMean() << endl;
//             }
//             else if(s == "getMedian")
//             {
//                 cout << d.getMedian() << endl;
//             }
//             else 
//             {
//                 cout << d.getMode() << endl;
//             }
//             // cout << "done" << endl;
//         }
//     }
//     return 0;
// }