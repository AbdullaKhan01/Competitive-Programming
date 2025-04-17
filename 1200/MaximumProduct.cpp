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
        vi arr(n+1);
        int mx = INT_MIN;
        for(int i=1;i<=n;i++){
            cin >> arr[i];
            mx = max(mx,arr[i]);
        }
        sort(arr.begin()+1,arr.end(),[](int &x,int &y){return abs(x) > abs(y);});
        output(arr);
        cout << endl;
        if(mx < 0){
            cout << arr[n] * arr[n-1] * arr[n-2] * arr[n-3] * arr[n-4] << endl;
        }
        else{
            int ans = arr[1] * arr[2] * arr[3] * arr[4] * arr[5];

            for(int i=6 ; i<=n ;i++){
                for(int j = 1;j<=5;j++){
                    int temp  = arr[i];
                    for(int k = 1; k<=5;k++){
                        if(k != j) temp *= arr[k];
                    }
                    ans = max(ans,temp);
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}