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

int main(){
    ll tt;
    cin >> tt;
    while(tt--)
    {
        ll n;
        cin >> n;
        vll ans;
        vll visited(n+1,0);
        for(ll i=1;i<=n;i++){
        	if(!visited[i]){
        		ans.push_back(i);
        		visited[i] = true;
        		ll b = 2*i;
        		while(b<=n && !visited[b]){
        			ans.push_back(b);
        			visited[b] = true;
        			b = 2*b;
        		}
        	}
        }
        output(ans);
        cout << endl;
    }
    return 0;
}