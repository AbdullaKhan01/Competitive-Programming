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
        string s;
        cin >> s;
        int n = s.size();
        vi arr(n);
        int mini = s[n-1] - 48;
        arr[n-1] = mini;
        for(int i=n-2;i>=0;i--){
        	int e = s[i] - 48;
        	mini = min(mini,e);
        	arr[i] = mini;
        }
        string p;
        int ind = -1;
        for(int i=0;i<s.size();i++){
        	int l = s[i] - 48;
        	ind++;
        	if(l > arr[ind]){
        		// cout << l << " " << arr[i] << endl;
        		int m = min(l+1,1LL*9);
        		p.pb(m+48);
        		s.erase(i,1);
        		i--;
        	}
        }
        // cout << s << " " << p << endl;
        // output(arr);
        // cout << endl;
        s += p;
        sort(all(s));
        cout << s << endl;
    }
    return 0;
}