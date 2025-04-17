/**
 * 		author -> Abd_Codeforce
 * 		created -> 20th July 2024	
*/

#include <bits/stdc++.h>

using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
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
		map<int,int> mp;
		bool flag = false;
		for(int i=0;i<n;i++)
		{
			mp[arr[i]]++;
		}
		for(auto it:mp)
		{
			if(it.second % 2 != 0) flag = true;
		}	
		cout << (flag?"YES":"NO") << endl;
	}
}