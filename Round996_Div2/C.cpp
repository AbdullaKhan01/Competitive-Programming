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
int n,k;
int calc(int g)
{
	if(g == 0) return 1;
	if(g > 40) return -1;
	if(g < 0) return 0;
	
	return 2 * calc(g-1);
}
void solve()
{
	cin >> n >> k;
	vector<int> perm(n);
	int s = 0 , e = n-1;
	int num = 1;
	if(n <= 41 && k > calc(n-1))
	{
		cout << -1 << endl;
		return ;
	}
	int idx = n-2;
	// 1 2 3
	// 1 3 2
	//     1
	//     1

	// 2^1 = 2
	while(num <= n)
	{
		int val = calc(idx);
		if(val == -1){
			perm[s++] = num;
		}
		else{
			if(val >= k) perm[s++] = num;
			else{
				perm[e--] = num;
				k -= val;
			}
		}
		idx--;
		num++;
	}
	output(perm);
	cout << endl;
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