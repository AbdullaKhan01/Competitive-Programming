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
vector<vector<int>>factors(100006+1);
void precompute(){
	for(int i=1;i<=100006;i++){
		for(int j=i;j<=100006;j+=i){
			factors[j].push_back(i);
		}
	}	
}
void solve()
{
	int n,m;cin >> n >> m;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	sort(all(a));
	// it was a two pointers question -> I was unable to 
	// find the approach

	// Basically if we have a Maximum element M and minimum
	// element m then adding any element in the range M -  m
	// will not change the answer so let's say the array
	// is sorted then the answer will be always a subarray
	// of the array so we can use 2 pointers to find subarray
	// at every r and decrease l when needed

	int count = 0;

	// make 2 pointers -> so the answer is 
	// j - i and we can take min if condition is met


	// when will we increase the count
	// when the

	// when will we decrease the count
	map<int,int> mp;
	int globalAns = 1e9;
	int i = 0;
	for(int j=0;j<n;j++)
	{
		for(auto factor : factors[a[j]])
		{
			if(factor > m) break;
			if(mp[factor]++ == 0)
			{
				count++;
			}
		}
		while(count == m){
			int ans = a[j] - a[i];
			globalAns = min(globalAns,ans);
			for(auto factor : factors[a[i++]]){
				if(factor > m) break;
				if(--mp[factor] == 0){
					count--;
				}
			}
		}
	}

	cout << (globalAns == 1e9 ? -1 : globalAns) << endl;

}
signed main(){
	fast_io();
	precompute();
    int tt = 1;
    cin >> tt;
    while(tt--)
    {
    	solve();
    }
    return 0;
}