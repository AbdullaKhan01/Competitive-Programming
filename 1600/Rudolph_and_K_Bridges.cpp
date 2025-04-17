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
        int n,m,k,d;
        cin >> n >> m >> k >> d;
        d++;
        vector<vi> river(n,vi(m,0));
        vector<vi> dp(n+1,vi(m+1,0));
        for(int i=0;i<n;i++)
        {
        	input(river[i]);
        }
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
        	multiset<int> ms;
        	for(int j=m-1;j>=0;j--)
        	{
        		int mini = 0;
        		if(!ms.empty()) mini = *(ms.begin());
        		//dp[i][j] represents the minimum cost
        		// to make a bridge from cell [[i][j],[i][m])
        		// if we install a support at cell [i][j] 
        		dp[i][j] = 1 + river[i][j] + mini;
        		ms.insert(dp[i][j]);
        		if(ms.size() > d)
        		{
        			// remove j+dth element
        			// eg 2 3 4 5
        			//    3 4 5 6
        			ms.erase(ms.find(dp[i][j+d]));
        		}
        	}
        	// since support at [i][0] cell is mandatory
        	// so this is the answer for this row
        	ans.push_back(dp[i][0]);
        }
        vector<int> pref(n+1,0);
        for(int i=0;i<n;i++)
        {
        	pref[i+1] = pref[i] + ans[i];
        }
        int cnt = LLONG_MAX;
        for(int i=k;i<=n;i++)
        {
        	cnt = min(cnt,pref[i] - pref[i-k]);
        }
        cout << cnt << "\n";
        // check every 10th operation

        // no = 

        // 298
        // 290
        // 140 130 120 110 100 90 80 70 60 50 40 30 20 10

    }
    return 0;
}