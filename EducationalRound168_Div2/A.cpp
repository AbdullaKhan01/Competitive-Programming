#include<bits/stdc++.h>
using namespace std; 
/* 
Author : Abd_Codeforce
Date   : 30th July 2024
*/
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	int tt;
	cin >> tt;
	while(tt--)
	{
		string s;
		cin >> s;
		int n = s.size();
		int maxi = INT_MIN;
		string ans = "";
		for(int i=25;i>0;i--)
		{
			string ch;
			ch.push_back((char)('a'+i));
			for(int j=0;j<n;j++)
			{
				string temp = s;
				temp.insert(j,ch);

				int sum = 2;
				for(int l=1;l<(int)temp.size();l++)
				{
					sum += (temp[l] == temp[l-1] ? 1:2);
				}
				if(sum >= maxi)
				{
					ans = temp;
					maxi = sum;
				}
			}
		}
		cout << ans << endl;
	}
    return 0;
}