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

// Observation : answer always possible withing 1 swap
vector<int> l;
void check(vector<int> &a,int x){
	int n = a.size();
	l.assign(n+1,0);
	for(int i=0;i<n;i++){
		l[i+1] = a[i];
	}
	// l = a;
	int pos = -1;
	for(int i=1;i<=n;i++){
		if(l[i] == x){
			pos = i;
			break;
		} 
	}
	for(int i=1;i<=n;i++){
		swap(l[i],l[pos]);
		// do someting
		int st = 1 , en = n+1;
		while(en - st > 1){
			int mid = (st + en)/2;
			if(l[mid] <= x) st = mid;
			else en = mid;
		}
		if(l[st] == x){
			int s1 = i, s2 = pos;
			if(s1 > s2) swap(s1,s2);
			if(s1 == s2){
				cout << 0 << endl;
			}
			else{
				cout << 1 << endl;
				cout << s1 << " " << s2 << endl;
			}
			return ;
		}
		swap(l[i],l[pos]);
	}
}

void solve(){
	int n,x;
	cin >> n >> x;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	check(a,x);
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