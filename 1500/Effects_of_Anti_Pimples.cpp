#include<bits/stdc++.h>
// #define mod 1000000007
#define mod 998244353
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
long long binpow(long long a, long long b, long long m=mod) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
ll modAdd(ll a,ll b){
    ll p = (a%mod + b%mod)%mod;
    return p;
}
ll modSub(ll a,ll b){
    ll p = (a%mod - b%mod)%mod;
    if(p<0) p+=mod;
    return p;
}
ll modMul(ll a,ll b){
    ll p = (a%mod * b%mod)%mod;
    return p;
}
signed main(){
	fast_io();
    // intuition -> this is a counting combinatorics problem
    // intuition -> maybe we would need to sort array but keeping
    // the indexes intact

    // thought -> let's say the array is [a,b,c]
    // then all possible ways to choosing 
    // elements to colour black will be = 2^N - 1
	// they are 
    // {{1},{2},{3},{1,2},{1,3},{2,3},{1,2,3}}

    // i guess we can use reverse engineering => this is my word
    // instead of taking out the max of all subsets
    // we can maybe count how many times a particular
    // element will appear in the final ans
    // let's say the frequency of (a,b,c) resp. is (x,y,z)

    // then the answer will be just (x*a + y*b + z*c)%998244353

    // but how can we do that actually .

    // got this idea -> 3 or 4 days later

    // lets say the array is [a,b,c,d]

    // so after taking only index 1 lets the max be m1
    // so after taking only index 2 lets the max be m2
    // so after taking only index 3 lets the max be m3
    // so after taking only index 4 lets the max be m4
    
    // lets sort these pairs in decreasing order 
    // let m3 >= m4 >= m2 >= m1
    // so the array will be 
    // [{3,m3},{4,m4},{2,m2},{1,m1}]

    // then if 3 will make a subset with any of the 
    // elements after it then the max will be the 
    // max of 3 so we can actually count is because
    // that no will be nothing but 2 ^ no of elements
    // after 3 


    // lets just write the code no nonsense
    // let's say the array indexes are like this
    // 1 2 3 4 5 6 7 8 9 10

    // VERDICT -> ACCEPTED
    int n;
    cin >> n;
    vector<int> arr(n+1);
    for(int i=1;i<=n;i++)
    {
    	cin >> arr[i];
    }   
    
    for(int i=1;i<=n;i++)
    {
    	for(int j=i;j<=n;j+=i)
    	{
    		arr[i] = max(arr[i],arr[j]);
    	}
    }
    sort(rall(arr));
    int ans = 0;
    for(int i=0;i<n;i++)
    {
        int num = arr[i];
        int freq = n-i-1;
        ans = modAdd(ans,num*binpow(2,freq));
    }
    cout << ans << endl;
    return 0;
}