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
bool func2(int a,int b){
        if(a % 2 == 0 && b%2 == 0){
            return true;
        }
        else if(a%2 != 0 && b%2 != 0){
            return false;
        }
        else{
            int n=a , m=b;
            if(a%2 == 0){
                n/=2;
                m*=2;
            }
            if(b%2 == 0){
                n*=2;
                m/=2;
            }
            if(a+b == n+m){
                return false;
            }
            else{
                return true;
            }
        }
}
bool func1(int l,int b){

        if((l&1) && (b&1)){
            // cout << "1" << endl;
            return false;
        }    
        if(!(l&1) && !(b&1)){
            // cout << "2" << endl;
            return true;
        }
        // int l1 = max(l,b)/min(l,b);
        if(max(l,b) %2 == 0 && max(l,b) == 2*min(l,b)) {
            // cout << "3" << endl;
            // cout << l1 << endl;
            return false;
        }
        else {
            // cout << "4" << endl;
            return true;
        }

}
signed main(){
    
    int a = 100;
    for(int i=0;i<a;i++){
        int x = rand() % 1000;
        int y = rand() % 1000;
        if(func1(x,y) != func2(x,y)){
            cout << x << " " << y << endl;
            cout << "Abdulla -> " << func2(x,y) << endl;
            cout << "Vikalp -> " << func1(x,y) << endl;
        }
    }
    return 0;
}