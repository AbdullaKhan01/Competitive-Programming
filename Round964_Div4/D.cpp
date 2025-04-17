/*
Author : Abd_Codeforce
Date   : 6th August 2024

I can do it !!!!!!!!!
*/


#include<bits/stdc++.h>
#define fast_io() ios::sync_with_stdio(0);cin.tie(0);
using namespace std; 
int main(){
	fast_io();
    int tt;
    cin >> tt;
    while(tt--)
    {
        string s,t;
        cin >> s >> t;
        int idx = 0;
        int n = t.size();
        while(idx < n)
        {
        	for(int i=0;i<(int)s.size();i++)
        	{
        		if(idx == n) break;
        		if(s[i] == '?')
        		{
        			s[i] = t[idx];
        			idx++;
        		}
        		else
        		{
        			if(s[i] == t[idx])
        			{
        				idx++;
        			}
        		}
        	}
        	break;
        }
        if(idx == n)
        {
        	cout << "YES\n";
        	for(int i=0;i<(int)s.size();i++)
        	{
        		if(s[i] == '?') s[i] = 'a';
        	}
        	cout << s << "\n";
        }
        else
        {
        	cout << "NO\n";
        }
    }
    return 0;
}