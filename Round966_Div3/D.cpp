#include<bits/stdc++.h>
#define int long long
#define fast_io() ios_base::sync_with_stdio(false);cin.tie(0);
using namespace std; 

/* 
Author : Abd_Codeforce
Date   : 13th August 2024
for the WIN
*/
signed main(){
	fast_io();
    int tt;
    cin >> tt;
    while(tt--)
    {
    	int n;
    	cin >> n;
    	vector<int> arr(n),pref(n+1,0);
    	for(int i=0;i<n;i++)
    	{
    		cin >> arr[i];
    		pref[i+1] = pref[i] + arr[i];
    	}
    	string s;
    	cin >> s;
    	vector<int> left,right;
    	for(int i=0;i<n;i++)
    	{
    		if(s[i] == 'L') left.push_back(i+1);;
    	}
    	for(int i=0;i<n;i++)
    	{
    		if(s[i] == 'R')
    		{
    			right.push_back(i+1);	
    		}
    	}
    	int ans = 0;
    	int aa = left.size() , bb = right.size();
    	int x = 0 , y = bb-1;
    	while(x < aa && y>=0)
    	{
    		int e = right[y];
    		int s = left[x];
    		// cout << s << " " << e << endl;
    		if(s <= e)
    			ans += (pref[e] - pref[s-1]);
    		x++,y--;	
    	}
    	cout << ans << endl;
    }
    return 0;
}