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
        int a,b;
        cin >> a >> b;
        int p = sqrt(a);
        int q = sqrt(b);

       	int c1 = q-1;
       	int c2 = p+1;

        int ans = 0;
        if(a == b){
        	int l = sqrt(a);
        	// ans = (a == l*l);
        	cout << (a == l*l) << endl;
        	continue;
        }
        ans += max(1LL*0,c1-c2+1) * 3;
        int l = p+1;
       	for(int i=p*p;i<l*l;i+=p){
       		if(i>=a && i<=b){
       			ans++;
       		}
       	}
       	if(p == q){
       		cout << ans << endl;
       		continue;
       	}
       	for(int i=q*q;i<=b;i+=q){       		
       		if(i>=a && i<=b){
       			ans++;
       		}
       	}
       	cout << ans << endl;

    }
    return 0;
}