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
        int n,s,m;
        cin >> n >> s >> m;
        vector<pair<int,int>> v;
        v.push_back({0,0});
        for(int i=0;i<n;i++)
        {
        	int l,r;
        	cin >> l >> r;
        	v.push_back({l,r});
        }
        v.push_back({m,m});
        bool flag = false;
        for(int i=1;i<(int)v.size();i++)
        {
        	int t = v[i].first - v[i-1].second;
        	if(t >= s)
        	{
        		flag = true;
        	}
        }
        cout << (flag?"YES":"NO") << "\n";
    }
    return 0;
}