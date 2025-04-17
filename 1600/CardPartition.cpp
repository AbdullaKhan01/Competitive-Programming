// #include<bits/stdc++.h>
// #define mod 1000000007
// #define mod2 998244353
// #define ceil(a,b) ((a+b-1)/b)
// #define floor(a,b)((a-b+1)/b)
// #define fast_io() ios::sync_with_stdio(0);cin.tie(0);
// #define ll long long
// #define int long long
// #define vi vector<int>
// #define all(x) (x).begin(),(x).end()
// #define rall(x) (x).rbegin(),(x).rend()
// #define input(x) for(auto &a:x) cin >> a;
// #define output(x) for(auto a:x) cout << a <<" ";
// #define rep(i,a,n) for(int i=(a);i<n;i++)
// #define pb push_back
// #define ppb pop_back
// #define pf push_front
// #define ppf pop_front
// #define ff first
// #define ss second
// #define si set<int>
// #define pii pair<int,int>
// #define mii map<int,int>
// #define msi map<string,int>
// #define yes "YES"
// #define no "NO"
// #define endl '\n'
// using namespace std; 
// /* 
// for fast input output use printf and scanf;
// */
// int n,k;
// vector<int> a;
// void solve()
// {
// 	cin >> n >> k;
// 	a.resize(n);
// 	int sum = 0;
// 	for(int i=0;i<n;i++)
// 	{
// 		cin >> a[i];
// 		sum += a[i];
// 	}
// 	sort(all(a));
// 	int f = a.back();
// 	// answer can be at max n

// 	// for some s size to be possible
// 	// sum + k should be a multiple of s
// 	// and max frequency of any number <= (sum + k) / s
// 	// since we know s and max freq and sum we can find k
// 	// and check if k is possible

// 	int ans = 1;
// 	for(int s=1;s<=n;s++)
// 	{
// 		// s is the size of the set

// 		// so f <= (sum + k) / s
// 		// sum + k >= f * s
// 		// k >= f * s - sum
// 		// k >= (s - (sum % s))%s

// 		int first = f * s - sum;
// 		int second = (s - (sum % s))%s;

// 		int maxi = max(first,second);
// 		if(k >= maxi)
// 		{
// 			// it is possible
// 			ans = s;
// 			}
// 	}
// 	cout << ans << endl;
// }
// signed main(){
// 	fast_io();
//     int tt = 1;
//     cin >> tt;
//     while(tt--)
//     {
//     	solve();
//     }
//     return 0;
// }
