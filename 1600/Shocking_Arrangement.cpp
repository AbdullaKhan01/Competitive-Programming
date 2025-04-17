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
void solve()
{
	int n;
	cin >> n;
	vector<int> a(n);
	int maxi = INT_MIN,mini = INT_MAX;
	vector<int> x,y;
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
		if(a[i] >= 0) x.push_back(a[i]);
		else y.push_back(a[i]);
		mini = min(mini,a[i]);
		maxi = max(maxi,a[i]);
	}
	sort(all(x));
	sort(all(y));
	int z = maxi - mini;
	int sum = 0;
	int cnt = 0;
	vector<int> g;
	int i = 0 , j = 0;
	while(cnt < n)
	{
		bool flag = false;
		if(i < x.size() && abs(sum + x[i]) < z)
		{
			g.push_back(x[i]);
			sum += x[i++];
			flag = true;
		}
		else if(j < y.size() && abs(sum + y[j]) < z)
		{
			g.push_back(y[j]);
			sum += y[j++];
			flag = true;
		}
		if(flag == true)
			cnt++;
		else break;
	}
	if(cnt == n)
	{
		cout << "Yes" << endl;
		for(auto it:g)
		{
			cout << it << " ";
		}
		cout << endl;
	}
	else
	{
		cout << "No" << endl;
	}

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