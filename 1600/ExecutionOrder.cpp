#include<bits/stdc++.h>
using namespace std; 
/* 
for fast input output use printf and scanf;
*/
int solve(vector<int>&processOrder,vector<int>&executionOrder)
{
	int n = processOrder.size();
	map<int,int> mp;
	for(int i=0;i<n;i++)
	{
		int ele = executionOrder[i];
		mp[ele] = i;
	}
	int maxi = -1;
	int cnt = 0;
	for(int i=0;i<n;i++)
	{
		int time = mp[processOrder[i]];
		if(maxi > time) cnt++;
		maxi = max(maxi,time);
	}
	return cnt;
}
int main(){
	int n;
	cin >> n;
	vector<int> a(n),b(n);
	for(auto &x : a) cin >> x;
	for(auto &x : b) cin >> x;
	cout << solve(a,b) << endl;
    return 0;
}