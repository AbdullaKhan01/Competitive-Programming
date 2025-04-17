#include<bits/stdc++.h>
#define mod 1000000007
#define mod2 998244353
#define change(a,b) ((a+b-1)/b)
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

// x * 2^n >= something

// 7 * 2^n >= 30
// 2 + n >= 5
// n 


// g = s1 * 2^x
// l = s2 * 2^y

// g * 2^k >= l
// s1 * 2^x * 2^k >= s2 * 2^y
// 2^k >= (s2/s1) * 2^(y-x)

// taking log both sides
// k >= logab
// k >= loga + logb

// k >= log(s2/s1) + y-x

// k >= log(s2) - log(s1) + (y - x)


// 7 30

// 7 * 2 ^ 0 * 2 ^ k >= 15 * 2 ^ 1

// k >= log2(ceil(15,7)) + (1-0)
// k >= log2(3) + 1
// k >= 2 + 1
// k >= 3
// k = 3

// s2 = 7 * 2 ^

// 5 * 2^1 * 2^k >= 7 * 2^3

// 7 * 8 = 56    10 20 40 80
// k >= log2(ceil(7,5)) + (3-1)
// k >= log2(2) + 2
// k >= 3
void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	input(a);
	int x = 0;
	int s2 = a[0];
	while(s2 % 2 == 0){
		s2 /= 2;
		x++;
	}
	int ans = 0;
	for(int i=1;i<n;i++){
		int s1 = a[i];
		int y = 0;
		while(s1 % 2 == 0){
			s1 /= 2;
			y++;
		}
		double num = s1;
		double den = s2;
		if(log2(num/den) >= (x-y)){
			// s1 * 2^y >= s2 * 2^x
			// s1/s2 >= 2^(x-y)
			// log(s2/s1) >= y-x if true then curr >= prev
			// then a[i] >= prev
			s2 = s1;
			x = y;
		}
		else{
			// s1 * 2^y * 2^k >= s2 * 2^x
			// 2^k >= s2/s1 * 2^(x-y)
			// k >= log2(ceil(s2,s1)) + (x-y)
			double s2d = s2;
			double s1d = s1;
			
			int v1 = ceil(log2(s2d/s1d));
			int v2 = x-y;
			int k = v1 + v2;
			ans += k;
			s2 = s1;
			x = y + k;
		}
		
		// 
	}
	cout << ans << endl;
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



// 




// 3 6 9 12 15
