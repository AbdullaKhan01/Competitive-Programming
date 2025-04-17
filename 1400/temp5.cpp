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

#include <bits/stdc++.h>
using namespace std;
// #define ceil(a,b) ((a+b-1)/b)
int main() {
	// your code goes here
    int tt;
    cin >> tt;
    while(tt--){
        long long n;
        cin >> n;
        if(n == 1){
            cout << 1 << endl;
            continue;
        }
        long long sum = 1;
        long long i;
        long long ans = 0;
        if(n%2!=0) sum = 1,i=3;
        else sum = 4,i=5;
        
        // cout << sum << n << endl;
        while(true){
            if(n>=sum){
                ans++;
                sum+=i;
                i+=2;
                sum+=i;
                i+=2;
            }
            else{
                break;
            }
        }
        cout << ans << endl;
    }
}


signed main(){
	
    
    return 0;
}