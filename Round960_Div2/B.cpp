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
		int n,x,y;
		cin >> n >> x >> y;
		x--,y--;
		vector<int> arr(n,1);
		int fact = -1;
		for(int i=y-1;i>=0;i--)
		{
			arr[i]*=fact;
			fact*=-1;
		}
		fact=-1;
		for(int i=x+1;i<n;i++)
		{
			arr[i]*=fact;
			fact*=-1;
		}
		for(int i=0;i<n;i++)
		{
			if(i > 0) cout << " ";
			cout << arr[i];
		}
		cout << '\n';
	}
}