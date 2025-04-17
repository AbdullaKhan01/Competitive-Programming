#include<bits/stdc++.h>
#define mod 1000000007
#define mod2 998244353
#define ceil(a,b) ((a+b-1)/b)
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
long long binpow(long long a, long long b, long long m=1e9+7) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
int main(){
    ll tt;
    cin >> tt;
    while(tt--)
    {
        ll n,q;
        cin >> n >> q;
        vll arr(n);
        input(arr);
        vector<int> que;
        vector<int> visited(31,0);
       	while(q--){
       		int x;
       		cin >> x;
       		if(!visited[x]){
       			visited[x] = true;
       			que.push_back(x);
       		}
       	}
       	// cout << que.size() << endl;
        for(int i=0;i<que.size();i++){
        	for(int j=0;j<n;j++){
        		if(arr[j] % binpow(2,que[i]) == 0){
        			arr[j]+=(binpow(2,que[i]-1));
        		}
        	}
        }
        output(arr);
        cout << endl;
    }
    return 0;
}