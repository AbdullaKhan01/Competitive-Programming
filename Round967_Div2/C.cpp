#include<bits/stdc++.h>
#define fast_io() ios::sync_with_stdio(0);cin.tie(0);
using namespace std; 
/* 
for fast input output use printf and scanf;
*/

int query(int a,int b)
{
    cout << "? " << a << " " << b << endl;
    int d;
    cin >> d;
    return d;
}
void dfs(int a,int b,vector<vector<int>>&ans,set<pair<int,int>>&q)
{
    if(q.find({a,b}) != q.end())
    {
        return ;
    }
    int k = query(a,b);
    q.insert({a,b});
    if(k == a || k == b)
    {
        ans.push_back({a,b});
        return ;
    }
    dfs(k,b,ans,q);
}
void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> ans;
    set<pair<int,int>> q;
    int a = 1;
    for(int i=2;i<=n;i++)
    {
        dfs(a,i,ans,q);
    }
    cout << "! ";
    for(auto it:ans)
    {
        cout << it[0] << " " << it[1] << " ";
    }
    cout << endl;
}
signed main(){
	fast_io();
    int tt;
    cin >> tt;
    while(tt--)
    {
        solve();
    }
    return 0;
}