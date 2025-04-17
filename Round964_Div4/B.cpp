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
        int a1,a2,b1,b2;
        cin >> a1 >> a2 >> b1 >> b2;
        // cout << a1 << " " << a2 << " " << b1 << " " << b2 << endl;
        int ans = 0;
        {
        	// show a1
        	if(a1 > b2 && a2>=b1) ans++;
        	if(a1 == b2 && a2 > b1) ans++;

        	if(a1 > b1 && a2 >= b2) ans++;
        	if(a1 == b1 && a2 > b2) ans++;
        }
    	{
        	// show a2
        	if(a2 > b2 && a1>=b1) ans++;
        	if(a2 == b2 && a1 > b1) ans++;

        	if(a2 > b1 && a1 >= b2) ans++;
        	if(a2 == b1 && a1 > b2) ans++;
        }
        cout << ans << endl;
    }
    return 0;
}