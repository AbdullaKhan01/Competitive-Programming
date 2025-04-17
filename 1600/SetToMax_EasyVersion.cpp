#include<bits/stdc++.h>
#define mod 1000000007
#define mod2 998244353
#define ceil(a,b) ((a+b-1)/b)
#define floor(a,b)((a-b+1)/b)
#define fast_io() ios::sync_with_stdio(0);cin.tie(0);
#define ll long long
#define int long long
#define vi vector<int>
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define input(x) for(auto &a:x) cin >> a;
#define output(x) for(auto a:x) cout << a <<" ";
#define rep(i,a,n) for(int i=(a);i<n;i++)
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define ff first
#define ss second
#define si set<int>
#define pii pair<int,int>
#define mii map<int,int>
#define msi map<string,int>
#define yes "YES"
#define no "NO"
#define endl '\n'
using namespace std; 
/* 
for fast input output use printf and scanf;
*/

/*

set the subarray to its maximum value

observations -> if b[i] < a[i] NOT POSSIBLE
             -> if b[i] is not present in a[i] NOT POSSIBLE


*/
void solve()
{
	int n;
	cin >> n;
	vector<int> a(n),b(n);
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
	}
	for(int i=0;i<n;i++)
	{
		cin >> b[i];
	}
	// let's say we are standing on the ith index then 
	// we have actually processed the i-1 elements
	// so if we can change the previous elements then we will

	vector<int> ans(n);
	bool gg = true;
	for(int i=n-1;i>=0;i--)
	{
		if(a[i] != b[i])
		{
			// cout << "for " << i << endl;
			if(b[i] < a[i])
			{
				gg = false;
				break;
			}
			bool found = false;
			int j = i-1;
			int maxi = INT_MIN;
			while(j >= 0)
			{
				// cout << "andar" << endl;
				maxi = max(maxi,a[j]);
				// cout << j << " " << maxi << " " << b[j] << endl;
				if(maxi > b[i] || maxi > b[j])
				{
					found = false;
					// cout << "gadbad" << endl;
					break;
				}
				if(maxi == b[i])
				{
					// cout << "yaha " << j << endl;
					found = true;
					break;
				}
				j--;
			}
			if(found)
			{
				// we have found an index j such that
				// we can change all elements from i to j
				// such that a[i] = b[i] holds true
				// cout << "come in" << endl;
				for(int k=i;k>=j;k--)
				{
					a[k] = maxi;
				}
				// cout << "yes" << endl;
				continue;
			}
			else
			{
				// we cannot get from the previous 
				// indexes just greedily try to get
				// from forward indexes
				bool finder = false;
				int todo = b[i];
				maxi = INT_MIN;
				while(i < n)
				{
					maxi = max(maxi,a[i]);
					if(maxi == todo)
					{
					 	finder = true;
					 	break;
					}
					if(maxi > b[i] || maxi > todo || todo > b[i])
					{
						// finder = false;
						break;
					}
					a[i] = todo;
					i++;
				}
				if(finder == false)
				{
					gg = false;
					break;
				}
			}
		}
	}
	cout << (gg?yes:no) << endl;
}
signed main(){
	fast_io();
    int tt = 1;
    cin >> tt;
    while(tt--)
    {
    	solve();
    }
    return 0;
}