#include<bits/stdc++.h>
using namespace std; 
/* 
Author : Abd_Codeforce
Date   : 30th July 2024
*/
int delR[] = {0,-1,0,+1};
int delC[] = {-1,0,+1,0};
bool isSafe(int r,int c,int n,int m)
{
	return (r>=0 && r<=n && c>=0 && c<=m);
}
bool isAlone(int r,int c,vector<string>&grid)
{
	int n = grid.size();
	int m = grid[0].size();
	for(int i=0;i<4;i++)
	{
		int nrow = r+delR[i];
		int ncol = c+delC[i];
		if(isSafe(nrow,ncol,n,m) && grid[nrow][ncol] == '.') return false;
	}
	return true;
}
void dfs(int r,int c,vector<string>&grid,vector<vector<int>> &visited)
{
	
	int n = grid.size();
	int m = grid[0].size();
	visited[r][c] = 1;
	for(int i=0;i<4;i++)
	{
		int nrow = r+delR[i];
		int ncol = c+delC[i];
		if(isSafe(nrow,ncol,n,m) && !visited[nrow][ncol] && grid[nrow][ncol] == '.')
		{
			dfs(nrow,ncol,grid,visited);
		}			
	}
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	int tt;
	cin >> tt;
	while(tt--)
	{
		int n;
		cin >> n;
		vector<string>grid(2);
		vector<vector<int>> visited(2,vector<int>(n+1,0));
		for(int i=0;i<2;i++) cin >> grid[i];
		int c = 0;
		for(int i=0;i<2;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(!visited[i][j] && grid[i][j] == '.')
				{
					c++;
					dfs(i,j,grid,visited);
				}
			}
		}
		int ans = 0;
		for(int i=1;i<2;i++)
		{
			for(int j=0;j<n;j++)
			{

				if(c == 3) ans++;
			}
		}
		cout << ans << "\n";
	}
    return 0;
}