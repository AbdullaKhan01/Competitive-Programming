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

n m 

if m < n NO

if m == n YES 1 1 1 1 1 n times

m = n+1
2 + 1 1 1 1 IF POSSIBLE

only highest number can have odd frequency

m >= n+2

m even n odd (n-1) 1's m - n + 1
m odd n odd (n-1) 1's m - n + 1

m even n even (n-2) 1's (m - n + 2)/2 ,/ 2
m odd n even 
(x) even times y (even times) ... highest(even times)
because x , y , smaller cannot be odd times
not possible 


n-2 even then n-2 1's rem = m - n + 2 = x
print x/2 x/2

n-2 odd that means n-1 even print n-1 1's and m - n + 1 


set x = 2 if y = 2 no problem if y > 2 no problem 

hence all set 


*/
void solve(){
	int n,m;
	cin >> n >> m;
	if(m < n){
		cout << no << endl;
		return ;
	}
	if(m == n){
		cout << yes << endl;
		while(n--){
			cout << 1 << " ";
		}
		cout << endl;
		return ;
	}
	if(n % 2 != 0){
		cout << yes << endl;
		for(int i=0;i<n-1;i++){
			cout << 1 << " ";
		}
		cout << m - n + 1 << endl;
	}
	else{
		if(m % 2 != 0){
			cout << no << endl;
		}
		else{
			cout << yes << endl;
			for(int i=0;i<n-2;i++){
				cout << 1 << " ";
			}
			int x = m - n + 2;
			cout << x/2 << " " << x/2 << endl;
		}
	}

}
signed main(){
	// 10 100101 11 2 + 1 + 2 + 2 + 2
	// 10 101001 11 2 + 2 + 2 + 1 + 2
	fast_io();
    int tt = 1;
    cin >> tt;
    while(tt--)
    {
    	solve();
    }
    return 0;
}