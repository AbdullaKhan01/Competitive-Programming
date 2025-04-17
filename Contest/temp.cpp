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
void solve2()
{
	int n;
	cin >> n;
	vector<int> arr(n);
	input(arr);
	vector<int> make(n);
	vector<int> temp;
	for(int i=1;i<n;i++)
	{
		int to_make = max(arr[i-1],arr[i]);
		make[i] = abs(arr[i] - to_make);
		// cout << arr[i] << " " << make[i] << endl;
		arr[i] = to_make;
	}

	// 1 < K < 9  
	sort(all(make));
	int cnt = n;
	// int ans = 0;
	int dec = 0;
	int ans = accumulate(all(make),0LL) + *max_element(all(make));
	// for(int i=0;i<n;i++)
	// {
	// 	make[i] -= dec;
	// 	if(make[i] == 0)
	// 	{
	// 		cnt--;
	// 		continue;
	// 	}
	// 	ans += (cnt+1)*(make[i]);
	// 	dec += make[i]; 
	// 	cnt--;
	// }
	cout << ans << "\n";
}
void solve3()
{
	int n,x;
	cin >> n >> x;
	vector<int> arr(n);
	map<int,int> mp;
	int cnt = 0;
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
		int finder = x - arr[i];
		cnt += mp[finder];
		mp[arr[i] % x]++;
	}
	cout << cnt << endl;
}
void solve(int n)
{
	int primes[n+1];
	for(int i=0;i<=n;i++)
	{
		primes[i] = 1;
	}
	for(int i=2;i*i<=n;i++)
	{
		if(primes[i])
		{
			for(int j=2*i;j<=n;j+=i) primes[j] = 0;
		}
	}
	for(int i=2;i<n;i++)
	{
		if(primes[i]) cout << i << " ";
	}
}

// bitmasking -> OA -> 1000 30 40
// STL -> C++ -> 
signed main(){
	fast_io();
    int tt = 1;
    cin >> tt;
    while(tt--)
    {
    	solve2();
    }
    return 0;
}

// a b c d e f g h 

// 1 2 6 6 6 10 10 10 10
// 0 0 0 4 6 0 8 0 9


// 4 6 8 9
// 5 -> 4 
// 2 4 5
// 4 -> 2
// 2 3
// 3 -> 2 
// 1
// 2 -> 1

// 5 5 5 5 4 4 3 3 2
// 5 3 -> 8
// 5 4 -> 9
// 4 2 -> 6
// 5 5 3 -> 4 

// 4 6 8 9
// 3 5 7 8
// 2 4 6 7
// 1 3 5 6
// 0 2 4 5
// 0 1 3 4
// 0 0 2 3

//  1 - 8  k -> k+1 coins

// 4 -> 5 5 5 5 4 4 