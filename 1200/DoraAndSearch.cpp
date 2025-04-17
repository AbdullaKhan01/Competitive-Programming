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
void solve(){
	int n;
	cin >> n;
	vi arr(n);
	input(arr);
	int l = 0 , r = n-1; 
	int mini = 1 , maxi = n;
	bool flag = false;
	while(l < r){
		if(arr[l] == mini){
			mini++;
			l++;
			continue;
		}
		if(arr[l] == maxi){
			l++;
			maxi--;
			continue;
		}
		if(arr[r] == mini){
			mini++;
			r--; 
			continue;
		}
		if(arr[r] == maxi){
			maxi--;
			r--;
			continue;
		}
		flag = true;
		cout << l+1 << " " << r+1 << endl;
		break;
	}
	if(flag == false){
		cout << -1 << endl;
	}
}
signed main(){
	
    int tt;
    cin >> tt;
    while(tt--)
    {
        solve();
    }
    return 0;
}