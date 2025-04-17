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


For n = 1
Then six tips increase every turn 
There are x balls between the tips in each turn 
And it increases by +2 
So for any generic N the answer will be 

1 + 6 + 6*1 + 6 + 6*3 + 6 + 6 * 5 …….

N = 3 -> so +6 will be done N-1 times

Then 6 *(1 + 3 + … N-1 times)
Ok

So for N answer is 
1 + (N-1 * 6) + 6 * sum of AP (1 + 3 + 5 + …. N-1) times  


*/
int sumofAp(int n){
	// n/2 2a + n-1 * d
	// int sum = (n * (2 + (n-1)*2))/2;
	return n*n;
	// return sum;
}
int retans(int n){
	 int ans = 1 + (n-1) * n * 6;
	cout << ans << endl;
	return 0;
}
void solve()
{
	int n;
	cin >> n;
	retans(n);
}
signed main(){
	fast_io();
    int tt = 1;
    // cin >> tt;
    while(tt--)
    {
    	solve();
    }
    return 0;
}