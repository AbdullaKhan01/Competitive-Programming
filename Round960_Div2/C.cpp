/**
 * 		author -> Abd_Codeforce
 * 		created -> 20th July 2024	
*/

#include <bits/stdc++.h>
#define int long long
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
		long long sum = 0;
		for(int i=0;i<n;i++)
		{
			cin >> a[i];
			sum += a[i];
		}
		map<int,int> mp;
		set<int> s;
		s.insert(0);
		vector<int> mad(n);
		for(int i=0;i<n;i++)
		{
			mp[a[i]]++;
			if(mp[a[i]] >= 2) s.insert(a[i]);
			mad[i] = *s.rbegin();
		}
		mp.clear();
		for(int i=0;i<n;i++)
		{
			mp[mad[i]]++;
		}
		int last = 0;
		for(int i=0;i<n;i++)
		{
			if(mp[mad[i]] >= 2)
			{
				sum += mad[i]*(n-i);
				last = mad[i];
			}
			else
			{
				sum += mad[i];	
				sum += max(0LL,last*(n-i-1));
			} 
		}
		cout << sum << '\n';
	}
}