/*
Author : Abd_Codeforce
Date   : 6th August 2024

I can do it !!!!!!!!!
*/


#include<bits/stdc++.h>
#define fast_io() ios::sync_with_stdio(0);cin.tie(0);
#define int long long
using namespace std; 
signed main(){
	fast_io();
    int tt;
    cin >> tt;
    while(tt--)
    {
        int l,r;
        cin >> l >> r;
        int mini = l;
        set<int> s;
        int idx = l+1;
        int ans = 0;
        while(mini != 0)
        {
        	mini /= 3;
        	ans++;
        	if(s.empty())
        	{
        		s.insert(idx*3);
        		idx++;
        		continue;
        	}
        	if(idx > r)
        	{
        		int a = *s.begin();
        		s.erase(s.find(a));
        		s.insert(a*3);
        		continue;
        	}
        	int l = *s.begin();
        	if(l <= idx)
        	{
        		s.erase(s.find(l));
        		s.insert(l*3);
        	}
        	else
        	{
        		s.insert(idx*3);
        		idx++;
        	}
        }
        // now for idx to r calc 
        // and for set elements calculate
        int left = idx , right = r;
        int a = 1;
        int cnt = 1;
        for(int i=0;i<=11;i++)
        {
        	int npow = a*3;
        	int g = 0 , h = 0;
        	if(left < npow)
        	{
        		g = max(left,a);
        	}
        	if(right >= a)
        	{
        		h = min(right,npow-1);
        	}
        	a*=3;
        	if(g <=0 || h <= 0)
        	{
        		cnt++;
        		continue;
        	}
        	else
        	{
        		int ele = h - g + 1;
        		ans += (ele)*cnt;
        		cnt++;
        	}
        }
        for(auto it:s)
        {
        	while(it != 0)
        	{
        		it/=3;
        		ans++;
        	}
        }
        cout << ans << "\n";
    }
    return 0;
}