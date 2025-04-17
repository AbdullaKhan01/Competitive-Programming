#include<bits/stdc++.h>
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
    	string s;
    	cin >> s;
    	if(s.size() <= 2)
    	{
    		cout << "NO" << endl;
    		continue;
    	}
    	if(s[0] == '1' && s[1] == '0')
    	{
    		string b = s.substr(2);
    		if(b.empty() || b[0] == '0' || stoi(b) <= 1)
    		{
    			cout << "NO" << endl;
    		}
    		else
    		{
    			cout << "YES" << endl;	
    		}
    	}
    	else
    	{
    		cout << "NO" << endl;
    	}
    }
    return 0;
}