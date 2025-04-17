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
bool solve(int pos,int mid,int p){

    if(mid == 1) return p == 1;
    if(mid == 2){
        if(pos %2 == 0){
            return p == 2;
        }
        else{
            return p == 1;
        }
    }
    int pp;
    if(mid == 3){
        pp = 1;
    }
    else if(mid > 3) pp = 2;

    int m = (2*mid) - 2;
    int rem;
    if(pos >= m) rem = pos-pos%m;
    else rem = pos;
    // cout << "here" << " " << mid << " " << m << " " << rem << endl;
    if(rem == 0){
        return pp == p;
    }
    else if(rem >=1 && rem<=mid){
        return rem == p;
    }
    else{
        int t = 2 * mid - rem;
        return t == p;
    }
    // int q = (2 * mid) - 2;
    // int i = pos%q;
    // int n = max(1LL*1,mid-2);

    // int diff = pos - i;
    // if(diff == 0){

    // }   
    // int a = mid;
    // int b = mid-2;
    // int s = 0;
    // bool flag = true;
    // bool turn = true;
    // while(pos >= b){
    //     if(turn){
    //         if(s+a <= pos){
    //             pos-=a;
    //         }
    //     }
    //     else{
    //         pos-=b;
    //     }
    //     turn = !turn;
    // }

}
signed main(){
    
    ll tt;
    cin >> tt;
    while(tt--)
    {
        int a,b;
        cin >> a >> b;
        int l = 0;
        int h = 0;
        int s = 1 , e = a;
        while(s<=e){
            int mid = (s+e)/2;
            cout << s << " " << e << " " << mid << endl;
            if(solve(a,mid,b)){
                l = mid;
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        s = 1,e = a;
        cout << "----------"<<endl;
        while(s<=e){
            int mid = (s+e)/2;
            if(solve(a,mid,b)){
                h = mid;
                s = mid+1;
            }
            else{
                e = mid - 1;
            }
        }
        cout << l << " " << h << endl;
        if(l == 0 && h == 0){
            cout << 0 << endl;
        }
        else{
            cout << h - l + 1 << endl;
        }
    }
    return 0;
}