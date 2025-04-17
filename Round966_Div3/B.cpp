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
    	for(int i=0;i<n;i++)
    	{
    		cin >> arr[i];
    	}
    	int i1 = arr[0]-1 , j = arr[0]+1;
    	bool flag = true;
    	for(int i=1;i<n;i++)
    	{
    		if(arr[i] == i1)
    		{
    			i1--;
    		}
    		else if(arr[i] == j)
    		{
    			j++;
    		}
    		else
    		{
    			flag = false;
    			break;
    		}
    	}
    	cout << (flag?"YES":"NO") << endl;
    }
    return 0;
}