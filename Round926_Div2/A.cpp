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
        vector<string> arr(2);
        cin >> arr[0];
        cin >> arr[1];

        vector<string> pref(n),suff(n);
        suff[n-1] = ""+to_string(arr[1][n-1]-48);
        for(int i=n-2;i>=0;i--){
            suff[i] = to_string(arr[1][i]-48)+suff[i+1];
        }
        pref[0] = ""+to_string(arr[0][0]-48);
        for(int i=1;i<n;i++){
            pref[i] = pref[i-1]+""+to_string(arr[0][i]-48);
        }
        string ans = pref[0]+suff[0];
        // cout << ans << endl;
        for(int i=1;i<n;i++){
            string g = pref[i] + suff[i];
            ans = min(ans,g);
        }
        // cout << ans << endl;
        int cnt = 0;
        for(int i=0;i<n;i++){
            string g = pref[i] + suff[i];
            if(g == ans) cnt++;
        }
        cout << ans << endl;
        cout << cnt << endl;

    }
    return 0;
}