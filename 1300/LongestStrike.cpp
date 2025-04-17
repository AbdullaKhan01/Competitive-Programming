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
        int n,k;
        cin >> n >> k;
        map<int,int> mp;
        vi arr(n);
        rep(i,0,n){
        	cin >> arr[i];
        	mp[arr[i]]++;
        }
        vi ans;
        for(auto it:mp){
        	if(it.second >= k) ans.pb(it.first);
        }
        
        if(ans.size() == 0){
        	cout << -1 << endl;
        	continue;
        }
        int finalStart,finalEnd;
        int start = ans[0];
        int end = ans[0];
        int best = INT_MIN;
        int cnt = 1;
        for(int i=1;i<ans.size();i++){
        	if(ans[i] == end+1){
        		cnt++;
        		end = ans[i];
        	}
        	else{
        		if(cnt>best){
        			best = cnt;
        			finalStart = start;
        			finalEnd = end;
        		}
        		start = ans[i];
        		end = ans[i];
        		cnt = 1;
        	}
        }
        if(cnt>best){
			best = cnt;
			finalStart = start;
			finalEnd = end;
		}
        cout << finalStart << " " << finalEnd << endl;
    }
    return 0;
}