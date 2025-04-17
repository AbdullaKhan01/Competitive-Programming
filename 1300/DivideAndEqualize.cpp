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
	int n;cin >> n;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	bool flag = false;
	for(int i=2;i<=n;i++){
		int cnt = 0;
		for(int j=0;j<n;j++){
			int x = a[j];
			if(x > i){
				// we have x we have to make it i
				// x/something = i
				// something = x/i
				if(x % i == 0) cnt += x/i;	
			}
			else{
				// we have x we have to make it i 
				// x * something = i
				// something = i/x
				if(i % x == 0) cnt -= x/i;
			}	
		}
		flag |= (cnt == 0);	
		if(flag){
			cout << "Yep " << i << endl;
			break;
		}	
	}
	cout << (flag ? yes : no) << endl;
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