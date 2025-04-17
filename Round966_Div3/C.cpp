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
    	int n;
    	cin >> n;
    	vector<int> arr(n);
    	map<int,vector<int>> mp;
    	for(int i=0;i<n;i++)
    	{
    		cin >> arr[i];
    		mp[arr[i]].push_back(i);
    	}
    	int m;
    	cin >> m;
    	while(m--)
    	{
    		string s;
    		cin >> s;
    		if((int)s.size() != n)
    		{
    			cout << "NO" << endl;
    			continue;
    		}
    		set<char> st;
    		bool flag = true;
    		for(auto it:mp)
    		{
    			vector<int> temp = it.second;
				// insert first character
				char ch = s[temp[0]];
				if(st.find(ch) == st.end())
				{
					st.insert(ch);
				}
				else
				{
					flag = false;
					break;
				}
				if(temp.size() == 1) continue;
				for(int i=1;i<(int)temp.size();i++)
				{
					if(s[temp[i]] == s[temp[i-1]])
					{
						continue;
					}
					else
					{
						flag = false;
						break;
					}
				}
				if(flag == false) break;
    		}
    		cout << (flag?"YES":"NO") << endl;
    	}

    }
    return 0;
}