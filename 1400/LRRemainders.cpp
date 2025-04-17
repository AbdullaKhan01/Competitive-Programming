#include<bits/stdc++.h>
#define mod 1000000007
#define mod2 998244353
#define ceil(a,b) ((a+b-1)/b)
#define floor(a,b)((a-b+1)/b)
#define fast_io() ios::sync_with_stdio(0);cin.tie(0);
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
/* 
for fast input output use printf and scanf;
*/
signed main(){
	fast_io();
    ll tt;
    cin >> tt;
    while(tt--)
    {
        int n,m;
        cin >> n >> m;
        vi arr(n);
        input(arr);
        int i=0,j=n-1;
        vi ans;
        string q;
        cin >> q;
        int s = q.size();
        for(int it=0;it<s-1;it++)
        {
        	if(i >= n || j < 0) break;
        	if(q[it] == 'L'){
        		ans.pb(arr[i]);
        		i++;
        	}
        	else{
        		ans.pb(arr[j]);
        		j--;
        	}
        }
        int ini = arr[i]%m;
        vector<int> g;
        reverse(all(ans));
        for(auto it:ans)
        {
        	g.pb(ini);
        	ini = (ini%m * it%m)%m;
        }
        g.pb(ini);
        reverse(all(g));
        output(g);
        cout << endl;
    }
    return 0;
}