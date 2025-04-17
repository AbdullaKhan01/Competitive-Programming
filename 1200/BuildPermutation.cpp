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
        vi ans(n,-1);
        set<int> p;
        int max = 2*n - 2;
        for(int i=0 ; i*i <= max;i++){
        	p.insert(i*i);
        }
        int ele = n-1;
        while(ele >= 0){
        	int it = *(p.lower_bound(ele));
        	int ind = it - ele;
        	while(ans[ind] == -1 && ind<n){
        		ans[ind++] = ele;
        		ele--;
        	}
        }
        output(ans);
        cout << endl;
        // for(int i=n-1;i>=0;i--){
        // 	auto it = p.upper_bound(i);	
        // 	cout << i << " -> " << *it << endl;
        // }
    }
    return 0;
}