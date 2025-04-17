#include<bits/stdc++.h>
#define mod 1000000007
#define mod2 998244353
#define ll long long
#define ll long long
#define lli long long int
#define vi vector<int>
#define vll vector<ll>
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define input(x) for(auto &a:x) cin >> a;
#define llmax(a,b) max(1LL*(a),1LL*(b))
#define output(x) for(auto a:x) cout << a <<" ";
#define FOR(i,n) for(i=0;i<n;i++)
using namespace std; 
int countSetBits(int n)
{
    int count = 0;
    while (n)
    {
        n = n & (n - 1);
        count++;
    }
    return count;
}
int main(){
    ll n,m,k;
    cin >> n >> m >> k;
    vll arr(m+1);
    for(int i=0;i<=m;i++){
    	cin >> arr[i];
    }
    ll ans = 0;
    ll z = arr[m];
    for(int i=0;i<m;i++){
    	ans += (countSetBits(arr[i]^z)<=k);
    }
    cout << ans << endl;
    return 0;
}