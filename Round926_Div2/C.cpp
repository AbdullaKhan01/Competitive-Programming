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
int solve(int sum,int k,int a){
	int s = 1 , e = a;
	int ans=a+1;
	while(s<=e){
		int mid = (s+e)/2;
		if((mid) * k > (sum+mid)){
			ans = mid;
			e = mid-1;
		}
		else{
			s = mid+1;
		}
	}
	return ans;
}
signed main(){
	
    ll tt;
    cin >> tt;
    while(tt--)
    {
 		int k,x,a;
 		cin >> k >> x >> a;
 		int place = 1;
 		int sum = 0;
 		for(int i=1;i<=x;i++){
 			if(place * k > (sum+place)){
 				sum += place;
 			}
 			else{
 				place = solve(sum,k,a);
 				sum += place;
 			}
 		}
 		int rem = a-sum;

 		if((rem * k) > a){
 			cout << yes << endl;
 		}
 		else{
 			cout << no << endl;
 		}
    }
    return 0;
}