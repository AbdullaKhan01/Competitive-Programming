#include<bits/stdc++.h>
using namespace std; 
/* 
for fast input output use printf and scanf;
*/
string a,b;
int n,m;
// vector<vector<int>>dp;
int dp[1001][1001][2];
int back[1001][1001][2];
int rec(int i,int j,int f)
{
    // pruning
    // base 
    if(i >= n || j >= m) return 0;
    // cache
    if(dp[i][j][f] != -1) return dp[i][j][f];
    // compute
    int ans = 0;
    if(f == 0 && rec(i+1,j,f) > ans)
     // skip character at index i
    {
        ans = rec(i+1,j,f);
        back[i][j][f] = 0;
    }
    if(f == 0 && rec(i,j+1,f) > ans)
     // skip character at index j
    {
        ans = rec(i,j+1,f);
        back[i][j][f] = 1;
    }
    if(a[i] == b[j] && rec(i+1,j+1,1) + 1 > ans)
    {
        ans = 1 + rec(i+1,j+1,1);
        back[i][j][f] = 2;
    }
    // save and return
    return dp[i][j][f] = ans;
}
void generate(int i,int j,int f)
{
    // pruning
    // base 
    if(i >= n || j >= m) return ;

    if(back[i][j][f] == 0)
     // skip character at index i
    {
        generate(i+1,j,f);
    }
    if(back[i][j][f] == 1)
     // skip character at index j
    {
        generate(i,j+1,f);
    }
    if(back[i][j][f] == 2)
    {
        cout << a[i];
        generate(i+1,j+1,1);
    }

}
void solve()
{
    cin >> a >> b;
    n = a.size() , m = b.size();
    // dp.resize(n+1);
    // for(int i=0;i<=n;i++) dp[i].assign(m+1,-1);
    memset(dp,-1,sizeof(dp));
    memset(back,-1,sizeof(back));
    rec(0,0,0);
    generate(0,0,0);
    cout << endl;
}
signed main(){
    int tt = 1;
    cin >> tt;
    while(tt--)
    {
        solve();
    }
    return 0;
}