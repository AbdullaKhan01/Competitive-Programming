#include<bits/stdc++.h>
#define mod 1000000007
#define mod2 998244353
#define ceil(a,b) ((a+b-1)/b)
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
signed main(){
  
    ll tt;
    cin >> tt;
    while(tt--)
    {
        int n;
        cin >> n;
        vi arr(n);
        input(arr);
        vi ans(n+1,1);
        int s = 0,e=1;
        int sum = arr[0];
        while(s<n && e<n){
            sum+=arr[e];
            if(sum <= n && s != e){
              // cout << "in if sum is " << sum << " " << s << " " <<  e << endl;
              ans[sum]++;
              
            }
            while(sum >= n && s<n){
              // cout << "in else sum is " << sum << " " << s << " " << e <<endl;
              sum-=arr[s++];
              if(sum <= n && s != e && s<n && e<n) ans[sum]++;
            }

            e++;
        }
        for(int i=1;i<=n;i++){
          cout << ans[i] << " ";
        }
        cout << endl;
    }

    return 0;
}