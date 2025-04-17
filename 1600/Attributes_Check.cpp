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
void solve()
{
	// 0 5000 or 1 4999 or 
    int n,m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    vector<vector<int>>dp(m+1,vector<int>(m+1,0));
    // dp[i][j] -> what does it represent ???
    // -> it represents the max no of points that can be acquired
    // if out of the first i points we increase j time intelligence
    // that means i - j times we would have increased strength

    vector<int> strength,intelligence;
    int total = 0;
    for(int i=0;i<n;i++)
    {
        if(a[i] > 0)
        {
            intelligence.push_back(a[i]);
        }
        else if(a[i] < 0)
        {
            strength.push_back(-a[i]);
        }
        else
        {
            // we have a zero or attribute increase
            total++;
            if(total == 1){
                strength.clear();
                intelligence.clear();
                continue;
            }

            sort(all(strength));
            sort(all(intelligence));

            for(int j=0;j<=total;j++)
            {
                // we have increased intelligence j times

                // to have strength j 
                // we would have come from 
                // 1 => dp[i-1][j-1] // increasing intelligence
                // or 2 => dp[i-1][j] // increasing strength

                // transitions
                if(j >= 1)
                {
                    // dp[total-1][j-1]
                    int first = dp[total-1][j-1] + 
                    upper_bound(all(intelligence),j-1) - intelligence.begin() + 
                    upper_bound(all(strength),total - j) - strength.begin();

                    dp[total][j] = max(dp[total][j],first);
                }
                if(j != total)
                {
                    // dp[total-1][j-1]
                    int second = dp[total-1][j] + 
                    upper_bound(all(intelligence),j) - intelligence.begin() + 
                    upper_bound(all(strength),total - 1 - j) - strength.begin();

                    dp[total][j] = max(dp[total][j],second);
                }
            }
            strength.clear();
            intelligence.clear();
        }
    }
    // now just go for idx to n
    int maxi = 0;
    // for(int i=0;i<)
    // cout << dp[4][0] << " " << dp[4][1] << endl;
    sort(all(intelligence));
    sort(all(strength));

    for(int i=0;i<=total;i++)
    {
        // for the last numbers after last 0

        // out of total i are for intelligence and 
        // total - i are for strength

        // cout << dp[total][i] << " ";        
        int ans = dp[total][i] + 
        upper_bound(all(intelligence),i) - intelligence.begin() + 
        upper_bound(all(strength),total- i) - strength.begin();

        // cout << dp[total][i] << " " << ans << endl;

        maxi = max(maxi,ans);
    }
    cout << maxi << endl;

}
signed main(){
	fast_io();
    int tt = 1;
    // cin >> tt;
    while(tt--)
    {
    	solve();
    }
    return 0;
}