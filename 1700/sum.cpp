#include<bits/stdc++.h>
using namespace std;
bool twosum(vector<int>&a,int st,int en,int target){
    if(en - st + 1 < 2) return false;
    bool flag = false;
    while(st < en){
        int sum = a[st] + a[en];
        if(sum == target) return true;
        else if(sum > target) en--;
        else st++;
    }
    return flag;
}
void solve()
{
    int n;cin >> n;
    vector<int> a(n);

    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    int sum;cin >> sum;
    // unordered_map<int,int> mp;
    int cnt = 0;
    for(int i=1;i<n;i++){
        int target = sum - a[i];
        cnt += twosum(a,0,i-1,target);
    }
    cout << "Total Triplets with sum " << sum << " are " << cnt << endl;
}
signed main(){
    int tt = 1;
    // cin >> tt;
    while(tt--)
    {
        solve();
    }
    return 0;
}