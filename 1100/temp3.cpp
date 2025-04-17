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
6
3 2 4 5 9 18

3 2 -> 4 3/2 = 2*(q+1) > 3
4 4 -> 8
8 5 -> 10
10 9 -> 18 10/9 = 1 9 *(1+1) = 18
18 18 -> 36
36

*/
int find(int a,int b)
{
	int s = 1 , e = 1e6+1;
	int ans = b;
	while(s <= e)
	{
		int mid = (s+e)/2;
		if(b * mid > a)
		{
			ans = b*mid;
			e = mid - 1;
		}
		else s = mid + 1;
	}
	return ans;
}
void solve()
{
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
	}
	int first = arr[0];
	for(int i=1;i<n;i++)
	{
		first = find(first,arr[i]);
		// int q = first / arr[i];
		// first = arr[i] * (q+1); 
	}
	cout << first << endl;
}
signed main(){
	fast_io();
    ll tt;
    cin >> tt;
    while(tt--)
    {
        solve();
    }
    return 0;
}