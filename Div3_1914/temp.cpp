#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define inp(arr, n) for(int i = 0; i < n; i++) cin >> arr[i];


void func() {
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    inp(arr, n);

    sort(arr.begin(), arr.end());

    int i = 0, j = n - 1;
    ll ans = 0;
    while (i < j) {
        if (arr[i] + arr[j] <= x) {
            ans += (j - i); 
            i++;
        } else {
            j--;
        }
    }
    cout <<  2*ans << endl;
}
signed main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    

    ll t;
    cin>>t;
    while(t--){
        func();
    }
}