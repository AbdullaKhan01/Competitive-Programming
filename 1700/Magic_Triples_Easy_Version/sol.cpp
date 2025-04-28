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
Crazy Idea Unlocked

ai * b = aj (1)
&
aj * b = ak (2)

substitute value of aj in (2)

we get ai * b * b = ak
b * b = ak/ai
b = sqrt(ak/ai)

max b can be sqrt(10^6) which is 10^3


so we can iterate for all b from 2 to 10^3
for b = 1 we get ai = aj = ak
so no of such pairs = freq[a[i]]C3 * 3!

*/
const int MAXN = 1e6 + 6;
vector<int> freq(MAXN);
void solve(){
	int n;cin >> n;
	vector<int> a(n);
	int maxi = 0;
	for(int i=0;i<n;i++){
		cin >> a[i];
		maxi = max(maxi,a[i]);
		freq[a[i]]++;
	}
	int ans = 0;
	for(int i=0;i<n;i++){
		// for b = 1
		int p = freq[a[i]];
		ans += (p-1) * (p-2);

		for(int b=2;b<=1000;b++){
			// for a[i] j = ai * b
			// k = a[i] * b * b
			int aj = a[i] * b;
			int ak = aj * b;
			if(aj <= maxi && ak <= maxi){
				ans += freq[a[i] * b] * freq[a[i] * b * b];	
			}
			
		}
	}
	cout << ans << endl;
	for(int i=0;i<n;i++){
		freq[a[i]]--;
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