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
/*
ACCEPTED
*/
signed main(){
	
    ll tt;
    cin >> tt;
    while(tt--)
    {
		
		int n;
		cin >> n;
		vi arr2(n);
		input(arr2);
		sort(all(arr2));
		int sum = 0;
		int ans = 0;
		int x = arr2[n-1];
		vector<int> arr(x+1,0);
		for(auto it:arr2) arr[it]++;
		for(int i=0;i<=x;i++){
			int p = arr[i];
			if(p == 0) continue;
			int a = (p * (p-1) * (p-2)) / 6;
			int b = (p * (p-1)) / 2;
			ans += a + (b*sum);
			sum+=p;
		}
		cout << ans << endl;
    }
    return 0;
}