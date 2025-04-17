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
// #define endl '\n'
using namespace std; 
/* 
for fast input output use printf and scanf;
*/

/*

Approach -> Took help from Editorial 
if we just output i ^ i-1 in the ith query
then let's say the answer is x
after each query the i-1 factor which gets added to the xor
will get eliminated
for eg 
for 1 ^ 0 = X = X ^ 1 ^ 0 = X ^ 1
for 2 ^ 1 = X ^ 1 =  X ^ 1 ^ 2 ^ 1 = X ^ 2
...
so on the Xth query we will output X ^ X - 1
and the answer would also have become X ^ X-1 so we
will get a correct answer there

Ahh I am so dumb i should have thought about this


*/
void solve()
{
	int n,k;
	cin >> n >> k;
	for(int i=0;i<n;i++){
		if(i == 0){
			cout << i << endl;
		}
		else{
			cout << (i ^ (i-1)) << endl;
		}
		int r;
		cin >> r;
		if(r == 1){
			break;
		}
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