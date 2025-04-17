#include<bits/stdc++.h>
using namespace std; 
/* 
Author : Abd_Codeforce
Date   : 30th July 2024
*/
char flip(char ch)
{
	if(ch == ')') return '(';
	return ')';
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	int tt;
	cin >> tt;
	while(tt--)
	{
		int n;
		cin >> n;
		string s;
		cin >> s;
		int op = 0;
		int cl = 0;
		bool flag = true;
		for(int i=0;i<n;i++)
		{
			if(s[i] == '(') op++;
			else if(s[i] == ')') cl++;
		}
		for(int i=0;i<n;i++)
		{
			if(s[i] == '_')
			{
				if(flag == true)
				{
					if(cl > op) s[i] = '(',op++;
					else s[i] = ')',cl++;	
				}
				else
				{
					if(cl >= op) s[i] = '(',op++;
					else s[i] = ')',cl++;	
				}
				
				flag = false;
			}
		}
		cout << s << endl;

		// int ans = 0;
		// int cnt = 0;
		// for(int i=0;i<n;i++)
		// {
		// 	if(s[i] == '_')
		// 		cnt++;
		// 	if(s[i] == ')')
		// 	{
		// 		ans+=(cnt*2);
		// 		cnt = 0;
		// 	}
		// }
		// ans+=(cnt*2);
		// cout << ans << '\n';
	}
    return 0;
}