#include<bits/stdc++.h>
#define fast_io() ios::sync_with_stdio(0);cin.tie(0);

using namespace std; 
/* 
for fast input output use printf and scanf;
*/
int n;
string s;
int dp1[1010][1010];
int rec1(int l,int r) // check palindrome
{
	if(l >= r) return 1;
	if(dp1[l][r] != -1)
	{
		return dp1[l][r];
	}
	int ans = 0;
	if(s[l] == s[r] && rec1(l+1,r-1)) ans = 1; 
	return dp1[l][r] = ans;
}

int dp2[1010];
int rec2(int i) // min cuts for (1....i)
{
	if(i == 0)
	{
		return -1;
	}
	if(dp2[i] != -1) return dp2[i];
	int ans = 1e9;
	for(int j=0;j<i;j++)
	{
		if(rec1(j+1,i))
		{
			ans = min(ans,rec2(j) + 1);
		}
	}
	return dp2[i] = ans;
}
void solve()
{
	cin >> n;
	cin >> s;
	memset(dp1,-1,sizeof(dp1));
	memset(dp2,-1,sizeof(dp2));
	cout << rec2(n) << endl;
}
int32_t main(){
	fast_io();
    int tt = 1;
    // cin >> tt;
    while(tt--)
    {
    	solve();
    }
    return 0;
}