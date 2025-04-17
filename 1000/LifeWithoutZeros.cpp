#include<bits/stdc++.h>
#define mod 1000000007
#define mod2 998244353
#define ceil(a,b) ((a+b-1)/b)
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

int wz(int n) {
	string ans = to_string(n);
	string ans2 = "";
	for(auto i : ans){
		if(i!='0')
			ans2 += i;
	}
	int res = stoi(ans2);
	return res;
}

signed main(){
	
    int n, m;
    cin >> n >> m;
    int sum = n+m;
    if(wz(n)+wz(m) == wz(sum))
    	cout << yes << endl;
    else cout << no << endl;

    return 0;
}