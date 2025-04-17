#include <bits/stdc++.h>
#define int long long
#define ceil(a,b) ((a + b - 1)/b)
using namespace std;
void solve(){
    int n,k;cin >> n >> k;
    vector<int> a(n);
    int maxi_max = 0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        maxi_max = max(maxi_max,a[i]);
    }
    int ans = 1e9;
    for(int maxi=1;maxi<= maxi_max;maxi++){
        // check if maxing maxi is possible
        bool flag = false;
        for(int i=0;i<n;i++){
            // a[i] / s == maxi
            if(a[i] < maxi) continue;
            int l = a[i]/maxi;
            if(l>=1 && l <= k && ((a[i]/l) == maxi)){
                flag = true;
                break;
            }
        }
        if(flag == false){
            continue;
        }
        else{
            vector<int> mins;
            // cout << "Yes " << maxi <<  endl;
            for(int i=0;i<n;i++){
                if(a[i] < maxi){
                    mins.push_back(1);
                    continue;
                }
                int g = (a[i]/maxi);
                if(g >= 1 && g <= k){
                    mins.push_back(g);    
                }
                else mins.push_back(k);
            }
            int maxi_m = -1;
            int mini = 1e9;
            for(int i=0;i<n;i++){
                int val = a[i]/mins[i];
                // cout << val << " ";
                maxi_m = max(maxi_m,val);
                mini = min(mini,val);
            }
            // cout << endl;
            ans = min(ans,maxi_m-mini);
            // cout << maxi_m-mini << endl;
        }
    }
    cout << ans << endl;
}
signed main()
{
    int tt;cin >> tt;
    while(tt--){
        solve();
    }
    return 0;
}