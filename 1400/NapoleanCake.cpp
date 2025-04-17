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
#define output(x) for(auto a:x) cout << a << " ";
#define FOR(i,n) for(i=0;i<n;i++)
using namespace std; 

int main(){
    ll tt;
    cin >> tt;
    while(tt--)
    {
        ll n;
        cin >> n;
        vll arr(n);
        input(arr);
        vll ans(n,0);
        int go=0;
        for(int i=n-1;i>=0;i--){
        	go = llmax(go,arr[i]);
        	if(go>0){
        		ans[i] = 1;
        		go--;
        	}
        }
        output(ans);
        cout << endl;
    }
    return 0;
}