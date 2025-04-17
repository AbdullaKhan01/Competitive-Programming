/**
 * 		author -> Abd_Codeforce
 * 		created -> 20th July 2024	
*/

#include <bits/stdc++.h>
using namespace std;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while(tt--)
	{
		int n;
		cin >> n;
		vector<int> a(n);
		for(int i=0;i<n;i++)
		{
			cin >> a[i];
		}

		int cost = 0;
		for(int i=0;i<n;i++)
		{
			if(a[i] <= 0) continue;

			if(a[i] > 2)
			{
				cost++;
			}
			else
			{
				cost++;
				a[min(n-1,i+1)]-=2;
			}
		}
		cout << cost << '\n';
	}
}