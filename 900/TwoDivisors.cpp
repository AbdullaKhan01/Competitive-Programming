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
int solve(vector<vector<char>> &grid,int row,int col,int m,
    vector<vector<int>>&dp){
    if(col >= m || row >= 2) return 0;
    if(col == m-1) return 1;
    // cout << "here" << row << " " << col << endl;
    if(row == 0){
        // right
        int right = 0;
        if(col + 1 < m){
            if(dp[row][col+2] != -1){
            right = dp[row][col+2];
            }
            if(grid[row][col+1] != '<'){
                right = solve(grid,row,col+2,m,dp);
            }
        }
        //down
        int down = 0;
        if(row + 1 < 2){
            if(dp[row+1][col+1] != -1){
                down = dp[row+1][col+1];
            }
            else if(grid[row+1][col] != '<'){
                down = solve(grid,row+1,col+1,m,dp);
            }
        }
        return dp[row][col] = right || down;
    }
    else{
        //right
        int right = 0;
        
        if(col + 1 < m){
            if(dp[row][col+2] != -1){
            right = dp[row][col+2];
            }
            else if(grid[row][col+1] != '<'){
                right = solve(grid,row,col+2,m,dp);
            }
        }
        // up
        int up = 0;
        
        if(row - 1 >=0){
            if(dp[row-1][col] != -1){
            up = dp[row][col];
            }
            else if(grid[row-1][col] != '<'){
                up = solve(grid,row-1,col+1,m,dp);
            }
        }
        return dp[row][col] = right || up;
        
    }
}
signed main(){
    fast_io();
    ll tt;
    cin >> tt;
    while(tt--)
    {
        int m;
        cin >> m;
        vector<vector<char>>arr(2,vector<char>(m,' '));
        for(int i=0;i<2;i++){
            for(int j=0;j<m;j++){
                cin >> arr[i][j];
            }
        }
        vector<vector<int>>dp(2,vector<int>(m+1,-1));
        int ans = solve(arr,0,0,m,dp);
        // cout << ans << endl;
        cout << (ans?yes:no) << endl;
    }
    return 0;
}