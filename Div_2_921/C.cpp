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
        // int a = 0,b=0,c=0,d=0;
        if(n == 1){
            cout << 0 << endl;
            continue;
        }
        int cnt1=0,cnt2=0;
        int a = arr[0];
        int ind = 0;
        while(ind<n && arr[ind] == a){
            ind++;
            cnt1++;
        }
        int p = n-1;
        int e = arr[p];
        while(p>=0 && arr[p] == e){
            p--;
            cnt2++;
        }
        // cout << max(1LL*0, p-ind+1) << endl;
        if(a == e){
            cout << max(1LL*0,p-ind+1) << endl;
        }
        else{
            if(cnt1 >= cnt2){
                cout << max(1LL*0,n-ind) << endl;
            }
            else{
                cout << max(1LL*0,p+1) << endl;
            }
        }
    }
    return 0;
}