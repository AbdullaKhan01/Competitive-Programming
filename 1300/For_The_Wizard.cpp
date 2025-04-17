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
int greaterElements(vector<int> &a,int x){
	// returns no of elements > x in the array

	// == a.size() - no of element <= x

	int smaller_equal = upper_bound(a.begin(),a.end(),x) - a.begin();
	return a.size() - smaller_equal;
}
int smallerElements(vector<int> &a,int x){
	return lower_bound(a.begin(),a.end(),x) - a.begin();
}
int getInv(vector<int>& a){
	int cnt = 0;
	int n = a.size();
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(a[i] > a[j]) cnt++;
		}
	}
	return cnt;
}
void solve()
{
	int n;cin >> n;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	vector<vector<int>> pref(n,vector<int>());
	pref[0].push_back(a[0]);
	for(int i=1;i<n;i++){
		pref[i] = pref[i-1];
		pref[i].push_back(a[i]);
	}
	for(int i=0;i<n;i++){
		sort(pref[i].begin(),pref[i].end());
	}
	int inv = getInv(a);
	int mini = inv;
	int st = 0,en = 0;
	for(int l=0;l<n;l++){
		for(int r=l;r<n;r++){
			// element at lth index goes to rth index

			int new_inv = inv;

			// new inv increase by number of elements
			// between rth and lth index that are > a[l]

			int greater_elements = greaterElements(pref[r],a[l]) - greaterElements(pref[l],a[l]);

			// new inv decrease by number of elements
			// between rth and lth index that are < a[l]
			
			int smaller_elements = smallerElements(pref[r],a[l]) - smallerElements(pref[l],a[l]);

			new_inv += greater_elements;
			new_inv -= smaller_elements;

			if(new_inv < mini){
				mini = new_inv;
				st = l;en = r;
			}
		}
	}
	cout << st+1 << " " << en+1 << endl;
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