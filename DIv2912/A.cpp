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
        int l = INT_MIN;
        int u = INT_MAX;
        set<int> s;
        while(n--){
        	int a,b;
        	cin >> a >> b;
        	if(a==1){
        		l = max(l,b);
        	}
        	if(a==2){
        		u = min(u,b);
        	}
        	if(a==3){
        		s.insert(b);
        	}
        }
        int count = 0;
        for(auto it:s){
        	if(it>=l && it<=u){
        		count++;
        	}
        }
        int zz = u - l -count + 1;
        int pp = 0;
        cout << max(zz,pp) << endl;
    }
    return 0;
}