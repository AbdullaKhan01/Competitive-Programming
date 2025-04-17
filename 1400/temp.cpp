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
// int mod = 1e9+7;
int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
    unordered_map<int,bool> mp1,mp2;
    for(auto it:hFences) mp1[it-1] = true;
    for(auto it:vFences) mp2[it-1] = true;
    hFences.push_back(m);
    vFences.push_back(n);
    sort(hFences.begin(),hFences.end());
    sort(vFences.begin(),vFences.end());
    int x = 1,y=1;
    int ans = 0;
    for(int i=0;i<hFences.size();i++){
        cout << "NEW" << endl;
        for(int j=i+1;j<=hFences.size();j++){
            int a = hFences[j-1];
            int height = a - x;
            cout << a << " " << x << endl;
            if(mp2.find(height)!=mp2.end()){
                cout << "Found " << height << " height" << endl;
                int area = ((height%mod) * (height%mod))%mod;
                ans = max(ans,area);
            }
        }
        x = hFences[i];
    }
    for(int i=0;i<vFences.size();i++){
        cout << "NEW" << endl;
        for(int j=i+1;j<=vFences.size();j++){
            int a = vFences[j-1];
            int width = a - y;
            cout << a << " " << y << endl;
            if(mp1.find(width)!=mp1.end()){
                cout << "Found " << width << " width" << endl;
                int area = ((width%mod) * (width%mod))%mod;
                ans = max(ans,area);
            }
        }
        y = vFences[i];
    }
    if(m == n) ans = ((m-1)%mod*(n-1)%mod)%mod;
    if(ans == 0) return -1;
    return ans;
}
int main(){
    // ll a;
    // cin >> a;
    // ll b;cin>>b;
    vector<int> arr1={2},arr2={8,6,5,4};
    cout << maximizeSquareArea(3,9,arr1,arr2) << endl;

    return 0;
}