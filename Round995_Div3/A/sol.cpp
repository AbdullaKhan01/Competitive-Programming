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
	int n,k;
	cin >> n >> k;
	vector<int> a(n),b(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
	} 
	for(int i=0;i<n;i++){
		cin >> b[i];
	}
	sort(all(a));
	sort(all(b));
	int ans = 0;
	for(int i=0;i<n;i++){
		int val = a[i];
		int sm2 = lower_bound(all(a),val) - a.begin();
		int greater = n - sm2;
		int ggo = lower_bound(all(b),val) - b.begin();
		ggo = n - ggo;
		int dikkat = ggo - greater;
		if(dikkat <= k){
			int cnt = (greater + dikkat) * val;
			ans = max(ans,cnt);	
		}
		

		int val2 = b[i];

		int sm = lower_bound(all(a),val2) - a.begin();
		int greater2 = n - sm;
		int ggoo = lower_bound(all(b),val2) - b.begin();
		ggoo = n - ggoo;
		int dikkat2 = ggoo - greater2;
		if(dikkat2 <= k){
			int cnt2 = (greater2 + dikkat2) * val2;
			ans = max(ans,cnt2);	
		}
		
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