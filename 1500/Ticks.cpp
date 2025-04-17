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

// INTUITION -> Starting from the bottom most
// row if we get a * then this means that
// this can be part of a tick or the base of
// a tick so we should check for it being 
// the base of a tick and then just store
// the max size of tick it can be a part of
// and also mark it as a used '*' now in the
// end just check if any '*' is not used or
// it is part of a tick with size < k then the answer
// is false otherwise the answer is true

bool isSafe(int n,int m,int i,int j)
{
	return (i >= 0 && i < n && j>=0 && j<m);
}
signed main(){
	fast_io();
    ll tt;
    cin >> tt;
    while(tt--)
    {
        int n,m,k;
        cin >> n >> m >> k;
        vector<vector<char>> grid(n,vector<char>(m,' '));
        for(int i=0;i<n;i++)
        {
        	for(int j=0;j<m;j++)
        	{
        		cin >> grid[i][j];
        	}
        }
        vector<vector<int>>used(n,vector<int>(m,0));
        vector<vector<int>>maxSize(n,vector<int>(m,0));

        for(int i=n-1;i>=0;i--)
        {
        	for(int j=0;j<m;j++)
        	{
        		if(grid[i][j] == '*')
        		{
        			int l = -1;
        			int i1=i,j1=j , i2=i,j2=j;
        			while(isSafe(n,m,i1,j1) && isSafe(n,m,i2,j2))
        			{
        				if(grid[i1][j1] == '*' && grid[i2][j2] == '*')
        				{
        					l++;
        					i1--;j1--;
        					i2--;j2++;
        				}
        				else
        				{
        					break;
        				}
        			}
        			i1=i,j1=j , i2=i,j2=j;
        			while(isSafe(n,m,i1,j1) && isSafe(n,m,i2,j2))
        			{
        				if(grid[i1][j1] == '*' && grid[i2][j2] == '*')
        				{
        					used[i1][j1]=1;
        					used[i2][j2]=1;
        					maxSize[i1][j1] = max(maxSize[i1][j1],l);
        					maxSize[i2][j2] = max(maxSize[i2][j2],l);
        					i1--;j1--;
        					i2--;j2++;
        				}
        				else break;
        			}
        		}
        	}
        }

        bool flag = true;
        for(int i=0;i<n;i++)
        {
        	for(int j=0;j<m;j++)
        	{

        		if(grid[i][j]=='*')
 	       		{
 	       			if(!used[i][j] || maxSize[i][j] < k) flag = false;
        		}
        	}
        }
        cout << (flag?yes:no) << endl;
    }
    return 0;
}