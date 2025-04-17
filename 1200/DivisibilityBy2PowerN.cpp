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
/*
VERDICT -> ACCEPTED
*/
signed main(){
	
    ll tt;
    cin >> tt;
    while(tt--)
    {
        int n;
        cin >> n;
        vector<int> indexes;
        int p = 0;
        for(int i=0;i<n;i++){
            int x;
            cin >> x;
            while(x%2==0){
                p++;
                x/=2;
            }
            int ind = i+1;
            int cnt = 0;
            while(ind %2 == 0){
                cnt++;
                ind/=2;
            }
            indexes.push_back(cnt);
            // cout << endl;
        }
        sort(rall(indexes));
        int ans = 0;
        // cout << "here " << p << " " << n << endl;
        for(int i=0;i<indexes.size();i++){
            if(p>=n) break;
            p+=indexes[i];
            ans++;
        }
        if(p>=n){
            cout << ans << endl;
        }
        else{
            cout << -1 << endl;
        }
    }
    return 0;
}