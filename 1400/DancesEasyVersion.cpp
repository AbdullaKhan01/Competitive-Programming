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
VERDICT => 
*/
bool solve(vi &arr,vi &brr,int mid)
{
	int n = arr.size();
	int idx = 0;
	int jdx = mid;
	bool flag = true;
	for(int i=0;i<n-mid;i++)
	{	
		if(arr[idx] >= brr[jdx]) flag = false;
		idx++;
		jdx++;
	}
	return flag;
}
signed main(){
	fast_io();
    ll tt;
    cin >> tt;
    while(tt--)
    {
        int n,m;
        cin >> n >> m;
        // cout << n << " " << m << endl;
        vi arr(n,0);
        vi brr(n,0);
       	arr[0] = 1;
       	for(int i=1;i<n;i++)
       	{
       		cin >> arr[i];
       	}
       	for(int i=0;i<n;i++)
       	{
       		cin >> brr[i];
       	}
       	sort(all(arr));
       	sort(all(brr));
       	// cout << "FIRST ARRAY " << endl;
       	// output(arr);
       	// cout << endl;
       	// cout << "SECOND ARRAY " << endl;
       	// output(brr);
       	// cout << endl;
       	int s = 0 , e = n;
       	int ans = INT_MAX;
       	while(s <= e)
       	{
       		int mid = (s+e)/2;
       		if(solve(arr,brr,mid))
       		{
       			ans = mid;
       			e = mid - 1;
       		}
       		else
       		{
       			s = mid + 1;
       		}
       	}
       	cout << ans << endl;
    }
    return 0;
}