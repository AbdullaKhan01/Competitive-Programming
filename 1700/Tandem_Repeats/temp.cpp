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
int maximumSumSubArray(vi& arr,int n){
	int best = 0, sum = 0;
 	for(int k = 0; k < n-1; k++) {
		sum = max(arr[k],sum+arr[k]);
		best = max(best,sum); 
	}
	return best;	
}
void solve()
{
	int n;cin >> n;
	vector<int> a(n);
	bool flag = false;
	vector<int> pos,neg;
	for(int i=0;i<n;i++){
		cin >> a[i];
		if(a[i] < 0) flag = true;
		if(a[i] > 0) pos.push_back(a[i]);
		else neg.push_back(a[i]);
	}
	if(flag == false){
		cout << maximumSumSubArray(a,n) << endl;
	}
	sort(all(pos));
	vector<int> slots(n);
	vector<vector<int>> g(n);
	int curr = 0;
	int c1 = 0 , c2 = 0;
	int slot = 1;
	vector<int> k;
	for(int i=0;i<(int)pos.size();i++){
		int sum = c2 + pos[i];
		int psum = c1 + pos[i];
		if(psum == sum){
			slots[i] = slot-1;
			c1 = psum;
		}
		if(psum > sum){
			
		}
		else{
			
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