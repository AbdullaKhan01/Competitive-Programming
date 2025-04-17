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
        int w;
        cin >> w;
        int a = ceil(w,2);
        vector<int> ans;
        vi arr(n);
        input(arr);
        int sum = 0;
        for(int i=0;i<n;i++){
            if(arr[i] >= a && arr[i]<=w){
                sum = arr[i];
                ans.clear();
                ans.pb(i+1);
                break;
            }
            if(arr[i] > w) continue;
            ans.pb(i+1);
            sum = sum + arr[i];
            if(sum >= a && sum <= w) break;
        }
        if(sum >= a && sum<=w){
            cout << ans.size() << endl;
            output(ans);
            cout << endl;
        }
        else{
            cout << -1 << endl;
        }
    }

    return 0;
}